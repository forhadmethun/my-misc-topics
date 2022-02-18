val x: String = null;
println(x.length)
//throws NPE


//1. throwing exception
val ex: String = throw new NullPointerException


//2. catching exception
def getId(b: Boolean): Int =
  if (b) throw new RuntimeException("No int") else 42

val fail = try {
  getId(true)
} catch {
  case e: RuntimeException => 43
} finally {
  // does not influence the return type
  // use finally only for side effects
  println("In the finally block")
}


//3. defining own exception
class MyException extends Exception
val exc = new MyException

// Practice

//Array.ofDim(Int.MaxValue)
//throw new OutOfMemoryError()

def infinite: Int = 1 + infinite
val nolimit = infinite

throw new StackOverflowError()

class OverflowException extends RuntimeException
class UnderflowException extends RuntimeException
class MathCalculationException extends RuntimeException

object PocketCalculator {
  def add(x: Int, y: Int) = {
    val res = x + y
    if( x > 0 && y > 0 && res < 0) throw new OverflowException
    else if (x < 0 && y < 0 && res > 0) throw new UnderflowException
    res
  }
  def subtract(x: Int, y:Int):Int = x - y
  def multiply(x: Int, y:Int):Int = x * y
  def divide(x: Int, y: Int): Int = {
    if (y == 0) throw new MathCalculationException
    x / y
  }
}
