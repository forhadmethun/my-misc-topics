//package rock_the_jvm.oop

//- the - jvm.oop

object Basic {

  def main(args: Array[String]): Unit = {
    val person = new Person("forhad", 28)
    val person2 = new Person("Imona", 26)
    person likes person2
    person + person2

    println(person.x)
    person.greet("another")

    new Counter2(5).inc.print
    new Counter2(5).inc.inc.print

    // prefix notation
    // unary only works with + - ! ~
    val x = -1
    val y = 1.unary_-

    println(!person)

    //postfix notation
//    def isAlive =
    println(person.isAlive)
//    println(person isAlive)

    // apply
    println(person.apply())
    println(person())

    //
    println((person + "the rockstar").apply())
    println((+person))
  }

}

class Person(val name: String, age: Int = 20) { // this is constructor code block
  val x = 2
  println(x + 2)

  def greet(name: String) = println(s"${this.name} says hi , $name")

  def greet() = println(s"Hi, I'm $name")

  def this(name: String) = this(name, 0)
  def this () = this("Forhad")
  def likes(person: Person): Unit = println(s"${this.name} likes ${person.name}")
  def +(person: Person): Unit = println(s"${this.name} likes ${person.name}")
  def +(nickname: String): Person = new Person(s"${this.name}($nickname)", age)
  def +(): Person = new Person(s"$name (the rock star)", age)
  def unary_! : String = s"$name, what hell?!"
  def unary_+ :Person = new Person(name, age + 1)
  def isAlive: Boolean = true
  def apply(): String = s"$name from the apply method"
  def learns(things: String): String = s"$name learns $things"
//  def learns = this learns "scala"
  def apply(n: Int): String = s"$name watched bla bla $n times"


}

class Writer(firstName: String, surName: String, year: Int) {
  def fullName(): String = firstName + " " + surName
}

class Novel(name: String, yearOfRelease: Int, author: Writer) {
  def authorAge(): Int = 1922
  def isWrittenBy(author: String): Boolean = name.equalsIgnoreCase(author)
  def copy(year: Int): Novel = new Novel(name, year, author)
}

class Counter2(n: Int) {
  def inc = new Counter2(n + 1)
  def inc(x: Int): Counter2 = {
    if (x <= 0) this
    else inc.inc(x - 1)
  }
    //new Counter2(n + x)
  def dec = new Counter2(n - 1)
  def dec(x: Int): Counter2 = {
    if (n <= 0) this
    else dec.dec(x) // new Counter2(n - x)
  }
  def print = println(n)
}

class Counter(count: Int = 0) {
  var c = count;
  def currentCountValue(): Int = c
  def inc():Int = {
    c += 1
    c
  }
  def dec():Int = {
    c -= 1
    c
  }
  def inc(n: Int): Int = {
    c += n
    c
  }
  def dec(n: Int): Int = {
    c -= n
    c
  }
}
