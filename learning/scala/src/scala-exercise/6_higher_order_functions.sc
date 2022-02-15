//def sumInts(a: Int, b: Int): Int =
//  if (a > b) 0 else a + sumInts(a + 1, b)

def cube(x: Int): Int = x * x * x

//def sumCubes(a: Int, b: Int): Int =
//  if (a > b) 0 else cube(a) + sumCubes(a + 1, b)
//
//def sumFactorials(a: Int, b: Int): Int =
//  if (a > b) 0 else factorial(a) + sumFactorials(a + 1, b)

def sum(f: Int => Int, a: Int, b: Int): Int =
  if (a > b) 0
  else f(a) + sum(f, a + 1, b)


def id(x: Int): Int = x

def sumInts(a: Int, b: Int) = sum(id, a, b)
def sumCubes(a: Int, b: Int) = sum(cube, a, b)

def sum(f: Int => Int, a: Int, b: Int): Int = {
  def loop(x: Int, acc: Int): Int =
    if (x > b) acc
    else loop(x + 1, acc + f(x))
  loop(a, 1)
}

sum(x => x, 1,10
)
