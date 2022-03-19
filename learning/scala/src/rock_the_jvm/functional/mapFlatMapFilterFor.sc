val list = List(1, 2, 3)
println(list.head)
println(list.tail)

println(list.map(_ + 1))
println(list.map(_ + " is a number"))

// filter
println(list.filter( _ % 2 == 0))

// flatMap
val toPair = (x : Int) => List(x, x + 1)
println(list.flatMap(toPair))

// print all combination between two lists
val numbers = List(1, 2, 3)
val chars = List('a', 'b', 'c', 'd')
val colors = List('r', 'g', 'b')
// output: List(a1, a2, ... d3)
val combination = numbers.flatMap(
  n => chars.flatMap(
    c => colors.flatMap(color => "" + c + n + color)))
println(combination)


// foreach
list.foreach(println)

// for comprehension

val forCom = for {
  n <- numbers if n % 2 == 0
  c <- chars
  color <- colors
} yield "" + c + n + color
println(forCom)

for {
  n <- numbers
} println(n)

list.map {
  x => x * 2
}

/*
  1. MyList supports for comprehension
     map(f: A => B) => MyList[B]
    filter(p: A => Boolean) => MyList[B]
    flatMap(f: A => MyList[B]) => MyList[B]

  2. Implement Maybe & Just *** < do it near future >
*/
