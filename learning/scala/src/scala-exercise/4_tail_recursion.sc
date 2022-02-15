def gcd(a: Int, b: Int): Int =
  if (b == 0) a else gcd(b, a % b)

gcd(14, 21)

def factorial(n: Int): Int =
  if (n == 0) 1 else n * factorial(n - 1)

factorial(4)

def factorial2(n: Int): Int = {
//  @tailrec
  def iter(x: Int, result: Int): Int =
    if (x == 0) result
    else iter(x - 1, result * x)

  iter(n, 1)
}

factorial2(4)
