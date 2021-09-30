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
	Time   time.Duration
	Number *big.Int
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
		encodedData := encoder.Encode(input)
		handleError(encodedData)

		var response Response
		decoder := json.NewDecoder(connection)
		decodedData := decoder.Decode(&response)
		handleError(decodedData)

		fmt.Println(response.Time, response.Number)
	}
}

func handleError(err error) {
	if err == nil {
		return
	}
	fmt.Println("Error ", err)
}
