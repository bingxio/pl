package main

import (
    "time"
    "fmt"
)

func main() {
    ticker := time.NewTicker(time.Second * 300)
    
    counter := 0
    
    go func() {
        for range ticker.C {
            fmt.Printf("call ticker for %d count. \n", counter)
            
            counter ++
            
            if counter == 5 {
                ticker.Stop()
            }
        }
    }()
}
