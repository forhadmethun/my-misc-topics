
//object AbstractDataType extends App {

  abstract class Animal {
    val creatureType: String
    def eat: Unit
  }

  class Dog extends Animal {
    override val creatureType: String = "Kutta"

    override def eat: Unit = println("kutta khayy")
  }
//}

val dog = new Dog
dog.eat


trait Carnivor {
  def eat(animal: Animal): Unit
}

trait ColdBlooded

class Crocodile extends Animal with Carnivor with ColdBlooded {
  override val creatureType: String = "croc"

  override def eat: Unit = println("Croc is eating")

  override def eat(animal: Animal): Unit = println(s"$creatureType is eating ${animal.creatureType}")
}

val croc = new Crocodile
croc.eat(dog)


// abstract class vs traits
// 1. x : no constructor but now it has
// 2. multiple trait can be inherited
// 3. trait: behavior, abstract class: type of things <subtle difference>


/*
      Any
AnyVal                       AnyRef
(Int, Unit,etc)         (List, Set,..)
                          Null
    Nothing

*/
