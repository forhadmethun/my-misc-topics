package rock_the_jvm.oop

class Animal {
  val creatureType = "wild"
  def eat = println("khay khali")
  protected def protect = println("Protected")
}

class Cat extends Animal {
  def crunch = {
    eat
    protect
    println("Crunching")
  }
}

def main(args: Array[String]): Unit = {
  val meow = new Cat

  meow.eat

  val dog = new Dog
  dog.eat

  // type substitution ~ polymorphism
  // object will call the most overriden stuff if possible
  val kutta: Animal = new Dog

}


class Person(name: String, age: Int) {
  def this(name: String) = this(name, 1);

}

class Adult(name: String, age: Int, idCard: String) extends Person(name, age)

// Overriding
class Dog extends Animal{
  override val creatureType = "kutta"
  override def eat: Unit = {
    // super
    super.eat
    println("kutta khay")
  }
}

class Dog2( override val creatureType: String) extends Animal {

}

class Dog3(overrideVal: String) extends Animal {
  override val creatureType: String =  overrideVal
}

// prevent override, use final before the method name
// use final before class so that it can't be inherited
// seal the class: can extends in the same file but not from others
