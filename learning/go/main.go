package main

import "fmt"

func main() {
	// basic()
	// conditions()
	// loops()
	// fizzbuzz()
	str()
}

func basic() {
	var card string = "Ace of Spades"
	fmt.Println(card)

	var x int
	var y int

	x = 1
	y = 2

	fmt.Printf("x=%v, type of %T\n", x, x)
	fmt.Printf("x=%v, type of %T\n", y, y)

	mean := (x + y) / 2.0 // defining and assigning at the same time, type inference
	fmt.Printf("result: %v, type of %T\n", mean, mean)

}

func conditions() {
	m, y := 2, 3
	z := 2
	fmt.Printf("%v, %v, %v\n", m, y, z)
	// we cannot have un-used variables

	if m < 5 {
		fmt.Printf("m is less than 5\n")
	}

	if z != 2 {

	} else {
		fmt.Printf("z is equal to 2")
	}

	if z > 1 && z <= 2 {
		fmt.Printf("Met the condition\n")
	}

	n := 2
	switch n {
	case 1:
		fmt.Printf("1")
	case 2:
		fmt.Printf("2\n")
	default:
		fmt.Printf("Default")
	}

	switch {
	case n > 100:
		fmt.Print("bigger than 100\n")
	default:
		fmt.Printf("I like to be default\n")
	}
}

func loops() {
	for i := 0; i < 3; i++ {
		fmt.Println(i)
	}
	println("=====")
	a := 0
	for a < 3 {
		println(a)
		a++
	}

	println("---------")
	b := 0
	for {
		if b > 2 {
			break
		}
		println(b)
		b++
	}
}

func fizzbuzz() {
	for i := 1; i <= 20; i++ {
		if i % 3 == 0 && i % 5 == 0 {
			println("fizz buzz")
		} else if i % 3 == 0 {
			println("fizz")
		} else if i % 5 == 0{
			println("buzz")
		} else {
			println(i)
		}

		//println(1 % 5)
		//println(7 % 5)
		//println(10 % 5)
	}

}

func str() {
	book := "The color of magic"
	println(book)

	println(len(book))

	fmt.Printf("book[0]= %v, (type %T)\n", book[0], book[0])

	// go strings are immutable , book[0] = 116, not possible 

	// slice, no end
	fmt.Println(book[4:10])

	// slice, no start
	fmt.Println(book[:4])

	//+ for concatenation 
	fmt.Println("t" + book[1:])

	// go strings are unicode 
	fmt.Println("আমি বাংলায় গান গাই")


	// multi line 
	poem := `
		Country road
		take me home... 
	`
	fmt.Println(poem)

}