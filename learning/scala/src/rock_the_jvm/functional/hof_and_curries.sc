val superFn: (Int, (String, (Int => Boolean))) => (Int => Int) = ???
// HOF => Takes function as param and returns function
// map, flatmap, filter are hof


// a function that applies a function n times over a value x
// nTimes(f, n, x)
// nTimes(f, 3, x)  =f(f(f(x)))

def nTimes(f: Int => Int, n: Int, x: Int): Int = {
  if (n < 1) x
  else nTimes(f, n - 1, f(x))
}

val plusOne = (_: Int) + 1
println(nTimes(plusOne, 5, 1))

def nTimesBetter(f: Int => Int, n: Int): (Int => Int) = {
  if (n <= 0) (x: Int) => x
  else (x: Int) => nTimesBetter(f, n - 1)(f(x))
}

val plus10 = nTimesBetter(plusOne, 10)
val eleven = plus10(1)


// curried function

val superAdder = (x: Int) => (y: Int) => x + y

println(superAdder(2)(3))


// scala supports a better way with multiple parameter in function
def curriedFormat(c: String)(x: Double): String = c.format(x)

val standardFormat: Double => String = curriedFormat("%4.2f")
val preciseFormat: Double => String = curriedFormat("%10.8f")

println(standardFormat(Math.PI))
println(preciseFormat(Math.PI))


// def curriedFormat(a: Int, b: Int)(c:Int)


/*
Exercise:
 1. Expand MyList
    - foreach method A => Unit
      [1, 2, 3].foreach(x => println(x))
    - sort function ((A, A) => B) => MyList[B]
      [1,2,3].sort((x, y) => y - x) => [3, 2, 1]
    - zipWith (list, (A, A) => B) => MyList[B]
      [1, 2, 3].zipWith([4, 5, 6], x * y) => [1*4, 2*5, 3*6] => [4, 10, 18]
    - fold(start)(function) => a value
      [1, 2, 3].fold(0)(x + y) = 6

 2. toCurry(f: (Int, Int) => Int) => (Int => Int => Int)
    fromCurry(f: (Int => Int => Int)) => (Int, Int) => Int

 3. compose(f, g) => x => f(g(x))
    andThen(f, g) => x => g(f(x))

*/

def toCurry(f: (Int, Int) => Int) : (Int => Int => Int) = {
  x => y => (x, y)
}

def fromCurry(f: (Int => Int => Int)) :(Int, Int) => Int = {
  (x, y) => f(x)(y)
}

def compose(f: Int => Int, g: Int => Int): Int ={
  x => f(g(x))
}

def andThen(f: Int => Int, g: Int => Int): Int ={
  x => g(f(x))
}

def supperAdder2: (Int => Int => Int) = toCurry(_ + _)
def add4 = superAdder(4)
println(add4(17)) // prints 21

val simpleAdder = fromCurry(superAdder)
println(simpleAdder(4, 17))

val add2 = (x: Int) = x + 2
val times3 = (x: Int) = x * 3

val composed = compose(add2, times3)
val ordered = andThen(add2, times3)

println(composed(4))
println(ordered(4))


// revisit this ! :P
