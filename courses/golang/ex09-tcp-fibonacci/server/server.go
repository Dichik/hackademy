package main

import (
	"encoding/json"
	"fmt"
	"math/big"
	"net"
	"time"
)

var ch map[int]*big.Int

func main() {
	ch = make(map[int]*big.Int)
	ch[0] = big.NewInt(0)
	ch[1] = big.NewInt(1)

	fmt.Println("Server started...")
	listener, err := net.Listen("tcp", ":8081")
	handleError(err)

	connection, err := listener.Accept()
	handleError(err)

	for {
		var data int
		decoder := json.NewDecoder(connection)
		decodedData := decoder.Decode(&data)
		handleError(decodedData)

		t := time.Now()
		response := Response{
			Time:   time.Since(t),
			Number: fibonacci(data),
		}

		encoder := json.NewEncoder(connection)
		encodedData := encoder.Encode(response)
		handleError(encodedData)
	}
}

func fibonacci(number int) *big.Int {
	currentSize := len(ch)

	if currentSize < number {
		return ch[number]
	}

	a := ch[currentSize-2]
	b := ch[currentSize-1]

	var limit big.Int
	limit.Exp(big.NewInt(10), big.NewInt(99), nil)

	for i := currentSize; i < number; i++ {
		a.Add(a, b)
		ch[i] = a
		a, b = b, a
	}

	return ch[number]
}

func handleError(err error) {
	if err == nil {
		return
	}
	fmt.Println("Error ", err)
}

type Response struct {
	Time   time.Duration
	Number *big.Int
}
