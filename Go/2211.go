// The Go programming language
package main

import (
	"encoding/json"
	"fmt"
	"time"
)

var (
	a int = 1
	b     = "str"
	c     = 1.3
	d     = 3.
)

const (
	Id   = 99
	Name = "bingxio"
)

type User struct {
	Id       int       `json:"id"`
	Name     string    `json:"name"`
	CreateAt time.Time `json:"create_at"`
}

func (u User) Stringer() string {
	return fmt.Sprintf(
		"{%d, %s, %s}",
		u.Id,
		u.Name,
		u.CreateAt.Format("2006-01-02 15:04"),
	)
}

func (u User) Regist(name string) {
	fmt.Println("regist: ", name)
}

func (u *User) Login(id int, name string) bool {
	fmt.Println("login: ", id, name)
	return true
}

type Model interface {
	Regist(string)
	Login(int, string) bool
}

func init() {
	fmt.Println("init program!!")
	fmt.Printf(
		"a = %d, b = %s, c = %f, d = %f\n",
		a, b, c, d,
	)
}

func reciver(p chan int) {
	fmt.Println("p:", <-p)
}

func main() {
	print("Hello\t")
	println("World")

	fmt.Printf("Id = %10d\nName = %8s\n",
		Id, Name)

	arr := []User{}
	fmt.Printf("arr: %v\n", arr)

	u := User{
		Id:       Id,
		Name:     Name,
		CreateAt: time.Now(),
	}
	var m Model = &u
	m.Regist("jarry")
	m.Login(3, "bingxio")

	arr = append(arr, u)
	arr = append(arr, User{})

	for i, u2 := range arr {
		fmt.Println(i, u2.Stringer())

		json, err := json.Marshal(u2)
		if err == nil {
			fmt.Println(string(json))
		}
	}
	for i := 0; i < 6; i++ {
		if i%2 == 0 {
			fmt.Println(i)
		}
	}

	length := func(list ...int) int {
		return len(list)
	}(1, 2, 3, 4, 5)

	fmt.Println("len of list: ", length)

	x := make(chan int)
	y := make([]*uint8, 4)

	var w chan string
	fmt.Printf("w: %v\n", w)

	go func() {
		x <- 34
		fmt.Println("call of sec routine")
	}()

	reciver(x)
	fmt.Println(x)

	var p uint8 = 20

	for i := range y {
		y[i] = &p
		if p%2 == 0 {
			p += 5
		} else {
			p++
		}
		fmt.Println("ok: ", p)
	}
}
