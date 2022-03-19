val doubler = new Function1[Int, Int] {
  override def apply(v1: Int): Int = v1 * 2
}

// anonymous function
val doubler2: Int => Int = (x: Int) => x * 2  // syntactic sugar of previous statement
val doubler3: Int => Int = x => x * 2  // syntactic sugar of previous statement

println(doubler(2))
println(doubler2(2))

// multiple param
val adder: (Int, Int) => Int = (x, y) => x + y

// no param
val noParam: () => Int = () => 3
println(noParam())


// curly braces with lambda
val strToInt: String => Int = {
  (x) => x.toInt
}

//incrementer
val inc: Int => Int = x => x + 1
val inc2: Int => Int = _ + 1
val anotherAdder: (Int, Int) => Int = _ + _ // sugar for (a, b) => a + b
// each underscore means different param, so if same param is there multiple time then can't use _

val superAdder = (x: Int) => (y: Int) => x + y

println(superAdder(2)(3))

// Takeaways
/*
Instead of using anonymous FunctinX we can use §lambda§
(x, y) => x + y
multiple param needs to be wrapped within () and seperated by ,
return type is inferred
right side contains the expression

Further sugar with _
*/
