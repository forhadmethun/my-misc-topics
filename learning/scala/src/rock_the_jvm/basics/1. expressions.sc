println("hello world")
val x = 1 + 2  // Expression
println(2 + 3 * 4)
// + - * % >> << & |
println( 1 == x)
// != >= <= !
println(!(1 == x))

var aVar = 2
aVar += 2
// -= /= *=
var conditonVal = true
val anotherVal = if (conditonVal) 2 else 5
if (anotherVal > 5) 2 else 1
// if is not instruction it's expression in scala

var i = 1
val pp = while (i < 10) {
  println(i)
  i = i + 1
}
println(pp)
// AVOID THIS, as it's imperative style
// In Scala everything is an expression!
val aWeirdVal = (aVar= 3)

// loop or assignments are side effects, which returns units

val codeBlock = {
  val y = 2
  val z = y + 1
  if (z > 2) "hello" else "Good bye"
}

println("Hello forhad!!")
