package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"math/big"
	"net"
	"os"
	"strconv"
	"time"
)

type Response struct {
	Number *big.Int
	Time   time.Duration
}

func main() {
	connection, err := net.Dial("tcp", "127.0.0.1:8081")
	handleError(err)

	defer connection.Close()

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input, err := strconv.ParseInt(scanner.Text(), 10, 64)
		handleError(err)

		encoder := json.NewEncoder(connection)
		encod := encoder.Encode(input)
		handleError(encod)

		var message Response
		decoder := json.NewDecoder(connection)
		decod := decoder.Decode(&message)
		handleError(decod)

		fmt.Println(&message.Time, message.Number)
	}
}

func handleError(err error) {
	if err == nil {
		return
	}
	fmt.Println("Error ", err.Error())
}
