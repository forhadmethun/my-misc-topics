abstract class Animal {
  def eat: Unit
}

val animal: Animal = new Animal {
  override def eat: Unit = println("hahaha")
}

/*

class anon$1@5adf4c9b extends Animal {
    override def eat: Unit = println("hahaha")
}
val animal: Animal = new anon$1@5adf4c9b
*/

class Person(name: String) {
  def hi: Unit = println(s"Hi $name")
}

val forhad = new Person("forhad") {
  override def hi: Unit = println("Hello forhad we override it")
}

forhad.hi
