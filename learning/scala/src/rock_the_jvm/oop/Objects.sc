// scala doesn't have the static stuff, so it has object instead
object Person{ // singleton accept
  val eyes = 2
  def canFly: Boolean = false
  // we'll write factoy method here
  def from(mother: Person, father: Person): Person = new Person("bob")
  def apply(mother: Person, father: Person): Person = new Person("bob")
}
println(Person.eyes)
println(Person.canFly)

// objects are singleton

val marry = Person
val john = Person
println(marry == john)

// companions, `object Person` for static stuff and `class Person` for class level stuff

class Person(val name: String)
val j = new Person("john")
val m = new Person("merry")
val bob = Person.from(j, m)
val bob2 = Person(j, m)

// scala application is Scala object with
// def main(args: Array[String]): Unit
