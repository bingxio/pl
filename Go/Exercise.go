package main

import (
	"fmt"
)

const (
	UsernameIncorrect = "username incorrect"
	PasswordIncorrent = "password incorrect"

	Success = "login successfully"
)

type User struct {
	Username string
	Password string
}

func (u User) validate(username, password string) string {
	if u.Username != username {
		return UsernameIncorrect
	} else if u.Password != password {
		return PasswordIncorrent
	} else {
		return Success
	}
}

func main() {

	a := User{
		Username: "turaiiao",
		Password: "12345678",
	}

	fmt.Println(a)

	b := a.validate("turaiiao", "123")

	fmt.Println(b)
}
