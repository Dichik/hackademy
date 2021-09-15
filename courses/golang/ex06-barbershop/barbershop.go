package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type Client struct {
	name string
}

var wg sync.WaitGroup

var customersAtAll = 10
var numberOfWaitingClients = 0
var barberSleep = false
var wasCustomers = 0
var clientsVisitedBarber []Client

func main() {
	fmt.Println("Good morning! Working day starts!\n")

	prepareSeats()

	clientsWaiting := make(chan Client, customersAtAll)

	wg.Add(1)
	go arriving(clientsWaiting)

	wg.Add(1)
	go cutting(clientsWaiting)

	wg.Wait()

	defer fmt.Println("\nOh, it was a hard day! See you tomorrow!")
}

func prepareSeats() {
	fmt.Println("Start preparing seats...")
	time.Sleep(time.Second * 3)
	fmt.Println("Waiting seats were prepared.\n")
}

func customerAlreadyWas(customerName string) bool {
	for _, v := range clientsVisitedBarber {
		if v.name == customerName {
			return true
		}
	}
	return false
}

func arriving(clientsWaiting chan Client) {
	defer wg.Done()
	rand.Seed(time.Now().UnixNano())

	for i := 0; i < customersAtAll; i++ {
		var nextClientGoAfter = rand.Intn(5)
		time.Sleep(time.Second * time.Duration(nextClientGoAfter))

		clientName := string(rune('A' + rand.Intn(26)))
		if customerAlreadyWas(clientName) {
			i--
		} else if numberOfWaitingClients < 5 {
			clientsWaiting <- Client{clientName}
			fmt.Println(clientName, " has gone and waiting")
			numberOfWaitingClients++
		} else {
			fmt.Println(clientName, " has not found a seat so he/she has gone")
		}
		wasCustomers++
	}
}

func cutting(clientsWaiting chan Client) {
	defer wg.Done()

	for wasCustomers < customersAtAll {
		if numberOfWaitingClients > 0 {
			currentClient := <-clientsWaiting
			if barberSleep {
				barberSleep = false
				fmt.Println(currentClient.name, " awake barber")
			}
			fmt.Println("Barber is cutting ", currentClient.name)
			time.Sleep(time.Second * 2)
			numberOfWaitingClients--
			clientsVisitedBarber = append(clientsVisitedBarber, currentClient)
		} else if !barberSleep {
			fmt.Println("Barber sleep")
			barberSleep = true
		}
	}
}
