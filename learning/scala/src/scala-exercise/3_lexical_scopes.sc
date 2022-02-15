def abs(x: Double) = if (x < 0 ) -x else x
def square(x: Double) = x * x

def sqrt(x: Double) = {
  def sqrtIter(guess: Double, x: Double): Double =
    if (isGoodEnough(guess, x)) guess
    else sqrtIter(improve(guess, x), x)

  def improve(guess: Double, x: Double) =
    (guess + x / guess) / 2

  def isGoodEnough(guess: Double, x: Double) =
    abs(square(guess) - x) < 0.001

  sqrtIter(1.0, x)
}

sqrt(4)


def sqrt2(x: Double) = {
  def sqrtIter(guess: Double): Double =
    if (isGoodEnough(guess)) guess
    else sqrtIter(improve(guess))

  def improve(guess: Double) =
    (guess + x / guess) / 2

  def isGoodEnough(guess: Double) =
    abs(square(guess) - x) < 0.001

  sqrtIter(1.0)
}
val x = sqrt2(16)

val y = x + 1; y * y
y * y


object Hello {
  def main(args: Array[String]) = println("hello world!")
}

//Hello.main(Array[""])

val x = 0
def f(y: Int) = y + 1
val result = {
  val x = f(3)
  x * x
} + x



