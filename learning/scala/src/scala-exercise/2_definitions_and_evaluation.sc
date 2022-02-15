3.14159 * 10 * 10

val radius = 10
val pi = 3.14159

pi * radius * radius
def square(x: Double) = x * x
square(3.0)


def area(radius: Double): Double = 3.14159 * square(radius)

area(10)

def sumOfSquares(x: Double, y: Double) = square(x) + square(y)

val x = 2
val y = square(x)

sumOfSquares(3, 2 + 2)

def loop: Int = loop

def triangleArea(base: Double, height: Double): Double =
  base * height / 2

triangleArea(5, 6)

