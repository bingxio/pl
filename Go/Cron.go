package main

import (
	"fmt"
	"time"

	"github.com/robfig/cron"
)

func main() {
	code := "0 0 * * * ?"

	c := cron.New()

	c.AddFunc(code, func() {
		currentTime := time.Now().Format("2006-01-02 15:04")

		fmt.Println(currentTime)
	})

	c.Start()

	select {}
}
