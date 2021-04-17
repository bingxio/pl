package main

import (
	"context"
	"fmt"
	"time"
)

type Future struct {
	await func(ctx context.Context) interface{}
}

func (f Future) Await() interface{} {
	return f.await(context.Background())
}

func Exec(f func() interface{}) Future {
	var r interface{}

	c := make(chan struct{})

	go func() {
		defer close(c)
		r = f()
	}()

	return Future{
		await: func(ctx context.Context) interface{} {
			select {
			case <-ctx.Done():
				return ctx.Err()
			case <-c:
				return r
			}
		},
	}
}

func main() {
	fmt.Println("START!!")

	r := Exec(
		func() interface{} {
			time.Sleep(time.Second * 3)
			fmt.Println("DONE.")
			return 1
		},
	).Await()

	fmt.Println("END", r)
}
