class MyList[+A] {
  def add[B >: A](element: B): MyList[B] = ???
  /*
  A = CAT
  B = DOG = ANIMAL
  */
}
class MyMap[Key, Value]

trait MyTrait[A]

val listOfInt = new MyList[Int]
val listOfStr = new MyList[String]

// object's cannot be type parameterized
object MyList {
  def empty[A]: MyList[A] = ???
}

val emptyListOfInt = MyList.empty[Int]

// variance problem
class Animal
class Dog extends Animal
class Cat extends Animal


// yes List[Cat] extends List[Animal] => Co variance < same thing>

class CovariantList[+A]
val animal: Animal = new Cat
val animalList: CovariantList[Animal] = new CovariantList[Cat]
// animalList.add(new Dog) ??? HARD QUESTION => Return list of animals

// NO => INVARIANCE <different thing, dog and cat not same>
class InvariantList[A]
val invariantAnimalList: InvariantList[Animal] = new InvariantList[Animal]

// NOT AT ALL => CONTRAVARIANT
class ContravariantList[-A]
//val covariantList: CovariantList[Cat] = new ContravariantList[Animal]

// bounded types (<: lower bounded, >: upper bounded)
class Cage[A <: Animal](animal: A)

val cage = new Cage(new Dog)
class Car
//val cage2 = new Cage(new Car) // not possible

