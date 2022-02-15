def abs(x: Double) = if (x >= 0) x else -x

abs(-2)

def improve(guess: Double, x: Double) =
  (guess + x / guess) / 2

def isGoodEnough(guess: Double, x: Double) =
  abs(guess * guess - x) < 0.001

def sqrtIter(guess: Double, x: Double): Double =
  if (isGoodEnough(guess, x)) guess
  else sqrtIter(improve(guess, x), x)

def sqrt(x: Double) = sqrtIter(1.0, x)

sqrt(4)

def factorial(n: Int): Int = if (n == 1) 1 else n * factorial(n - 1)

factorial(3)

