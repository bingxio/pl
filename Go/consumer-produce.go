package main

import (
    "sync"
)

func main() {
    var wg sync.WaitGroup
    
    c := make(chan int, 10)
    
    wg.Add(1)
    go func() {
        for i := 0; i < 100; i++ {
            c <- i
        }
        close(c)
        
        wg.Done()
    }()
    
    for i := 0; i < 3; i++ {
        wg.Add(1)
        
        go func() {
            for v := range c {
                if v % 2 == 0 {
                    println(v)
                }
            }
            
            wg.Done()
        }()
    }
    
    wg.Wait()
}
