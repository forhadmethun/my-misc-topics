// functions are first class elements
// !! It means we want to work with functions like we would with plane values !!

// In OOP
class Action {
  def execute(value: String): Int = ???
}

//
trait ActionTrait[A, B] {
  def execute(value: A): B
}

trait MyFn[A, B] {
  def apply(value: A): B
}

val doubler = new MyFn[Int, Int] {
  override def apply(value: Int): Int = value * 2
}

println(doubler(2))

                           //input, output
val strToInt = new Function[String, Int] {
  override def apply(v1: String): Int = v1.toInt
}

println(strToInt("123"))


val adder: ((Int, Int) => Int) = new Function2[Int, Int, Int] {
  override def apply(v1: Int, v2: Int): Int = v1 + v2
}
println(adder(2,3))

// we have function types
// Function2[A, B, R] = (A, B) => R

// ALL SCALA FUNCTIONS ARE OBJECTS

// practice
//1. write function that takes two string as param and returns a new string
val concat: (String, String) => String = new Function2[String, String, String] {
  override def apply(v1: String, v2: String): String = v1 + v2
}

println(concat("a", "B"))

//val transformer: (A) => B
// takes type a as input returns b output
abstract class MyList[+A] {
  def map[B](transformer: A => B): MyList[B]
}

// a function takes an int as param and return a function that takes int and return int

//Function1[Int, Function1[Int, Int]]
val superAdder: Function1[Int, Function1[Int, Int]] = new Function1[Int, Function1[Int, Int]] {
  override def apply(x: Int): Int => Int = new Function1[Int, Int] {
    override def apply(y: Int): Int = x + y
  }
}

val superAdder3 = superAdder(3)
val addWithSuperAdder3 = superAdder3(4)
println(addWithSuperAdder3)
println(superAdder(3)(4)) // curried function


// TAKEAWAYS
/*

Using function as parameters
Using function as values

=> Scala is on the top of JVM which is designed for JAVA
- so first class elements are objects which are instances of class
Solution: All scala functions are objects !
Function traits upto 22 params
syntactic sugar function types

*/
