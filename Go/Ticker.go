package main

import (
    "time"
    "fmt"
)

func main() {
    ticker := time.NewTicker(time.Second * 300)
    
    go func() {
        for range ticker.C {
            fmt.Println("call at ticker !")
            
            ticker.Stop()
        }
    }()
}
