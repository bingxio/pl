package main

import (
	"fmt"
	"time"
)

type AddFn func(int, *int) int

func (f AddFn) call(x int, p *int) int {
	return f(x, p)
}

func main() {
	fmt.Println("GENERIC GO!!")

	p := new(int)
	*p = 20

	fn := func(x int, p *int) int {
		fmt.Println("x = ", x, "*p = ", *p)
		return x + *p
	}
	var qw AddFn = fn
	var r = qw.call(4, p)
	fmt.Println(r)

	done := make(chan bool)
	fmt.Println("address:", done)

	go Announce()
	time.Sleep(time.Second * 3)
}

func Announce() {
	go func() {
		for i := 1; i < 4; i++ {
			fmt.Println(i)
			time.Sleep(time.Second)
		}
	}()
}
