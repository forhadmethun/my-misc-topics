import scala.annotation.tailrec

def func(a: String, b: Int): String = {
  a + " " + b
}

func("abba", 1)

def paramLess() = 42
paramLess()

paramLess()

def rFunc(a: String, n: Int): String = {
  if (n == 1) a else a + ", "+ rFunc(a, n - 1)
}

rFunc("abc", 3)

// compiler can infer return type of a method except recursives

def factorial(n: Int): Int = if (n <= 0) 1 else n * factorial(n - 1)
factorial(5)

def fib(n: Int): Int = if (n <= 2) 1 else fib(n - 1) + fib (n - 2)

def isPrime(n: Int): Boolean = {
  @tailrec
  def isPrimeUntil(t: Int): Boolean =
    if (t <= 1) true
    else n % t != 0 && isPrimeUntil(t - 1)
  isPrimeUntil(n / 2)
}

isPrime(3)
isPrime(4)
isPrime(17 * 37)

def strCat(str: String, n: Int): String = {
  @tailrec
  def strUtil(x: Int, acc: String): String = {
    if (x <= 1) acc else strUtil(x - 1, str + " ")
  }
  strUtil(n, str)
}

def isPrime(n: Int): boolean = {
  @tailrec
  def primeUtil(t: Int, b: Boolean): Boolean = {
    if (!b) false
    else if (t <= 1) true
    else primeUtil(t - 1, n % t != 0 && b)
  }
  primeUtil(n / 2, true)
}

def fib(n: Int): Int = {
  def fibUtil(i: Int, last: Int, nextToLast: Int): Unit = {
    if (i >= n) last
    else fibUtil(i + 1, last + nextToLast, last)
  }
  if (n <= 2) 1
  else fibUtil(2, 1, 1)
}
