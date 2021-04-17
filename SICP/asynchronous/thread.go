package main

import (
	"fmt"
	"time"
)

func PublicNews(text string) {
	go func() {
		time.Sleep(time.Second)
		fmt.Println("NEWS: ", text)
	}()
	fmt.Println("END")
	time.Sleep(time.Second * 2)
}

func main() {
	PublicNews("ABC")
}
