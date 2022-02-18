/* case class has it's own equals/hashCode/toString
Also own Companion
 */

case class Person(name: String, age:Int)

// 1. class params are field
val forhad = new Person("Forhad", 27)
println(forhad.name)


// 2. toString
println(forhad.toString)

// 3. equals
val forhad2 = new Person("Forhad", 27)
println(forhad == forhad2)

// 4. CCs has copy method
val forhad3 = forhad.copy(age=28)
println(forhad3)

// 5. has companion object
val person = Person
val forhad4 = Person("Forhad", 27)

// 6. Are serializable

// 7. has extractor pattern so can be used in pattern matching

case object UK {
  def name: Unit = println("UK")
}







