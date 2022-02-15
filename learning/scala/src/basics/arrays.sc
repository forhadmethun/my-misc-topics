def avg(numbers: List[Int]): Double = {
  var sum: Double = 0;
  for(number <- numbers) sum += number
  sum /= numbers.length
  sum
}
avg(List(1, 2, 3))

def sum(numbers: List[Int]): Int = numbers.sum
sum(List(1, 2, 3))
def min(numbers: List[Int]): Int = numbers.min
min(List(1, 2, 3))

var min2 = (numbers: List[Int]) => {
  var m = numbers(0)
  for(number <- numbers) if (number < m) m = number
  m
}
min2(List(1,2,3))

def max(numbers: List[Int]): Int = numbers.max
max(List(1, 2, 3))
