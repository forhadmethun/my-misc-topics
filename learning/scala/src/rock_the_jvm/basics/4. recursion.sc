def fact(n: Int): Int = if (n <= 1) 1 else n * fact( n - 1)

fact(4)

def fact2(n: Int): Int = {
  def factUtil(x: Int, acc: Int): Int = {
    if (x <= 1 ) acc else factUtil( x - 1, x * acc)
  }
  factUtil(n, 1)
}
fact2(5)
