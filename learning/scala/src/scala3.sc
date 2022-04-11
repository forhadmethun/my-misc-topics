object Id:
  val ans = 2

  def square(x: Double): Double =
    val result = x * x
    result
  end square

  def max(x: Int, y: Int) = if x > y then x else y

  def forCheck =
    for x<- List(1,3,3)
      yield x *x

Id.square(Id.ans)
Id.max(2, 3)
Id.forCheck

enum Permission:
  case CanView
  case CanEdit
  case canDelete

enum Delivery:
  case Standard
  case Express
  case Fast(track: Boolean)
  def cost: Double =
    this match {
      case Standard => 3.99
      case Express => 7.99
      case Fast(true) => 15.55
      case Fast(false) => 12.22
    }

val standard = Delivery.Standard
standard.cost
val fast = Delivery.Fast(true)
fast.cost


// --
enum IntList:
  def sum:Int =
  this match {
    case Pair(h, t) => h + t.sum
    case End => 0
  }
  case Pair(head: Int, tail: IntList)
  case End

//var intList = IntList.Pair(1, IntList.Pair(2, IntList.Pair(3, IntList.END)))


enum MyList[A]:
  def length: Int =
    this match {
      case Pair(h, t) => 1 + t.length
      case End() => 0
    }
  case Pair(head: A, tail: MyList[A])
  case End[A]() extends MyList[A]

//val list = MyList.Pair("a", MyList("b", MyList.end()))

extension [A] (a: A)
  def debug = println(s"Debug: $a")

"CAT".debug
5.debug

extension (s: String)
  def palindrome(): Boolean =
    s.toLowerCase.reverse == s.toLowerCase

"abba".palindrome()
"ammu".palindrome()

extension (i: Int)
  def odd = i % 2 == 1
  def even = i% 2 == 0

5.odd
5.even


@main def hello =
  println("Hello")

hellog

object Min:
  def min[A](x: A, y:A)(using ord: Ordering[A]): A =
    if ord.compare(x, y) < 0 then x else y

  given aGivenOrdering: Ordering[Int] with
    def compare(x: Int, y: Int) = 1

  def minExample() =
    println(min(42, 5)(using Ordering.Int))

Min.minExample()










