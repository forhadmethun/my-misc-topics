
/*
  implements singly linked list
  head = first element of the list
  isEmpty = is the list empty
  add(int)  => new list with this element
  toString => string representation
*/

trait MyPredicate[-T] {
  def test(elem: T): Boolean
}

trait MyTransformer[-A, B] {
  def transform(elem: A): B
}



abstract class MyList[+A]{
  def head: A
  def tail: MyList[A]
  def isEmpty: Boolean
  def add[B >: A](element: B): MyList[B]
  def printElements: String
  override def toString: String = "[" + printElements + "]"

  def map[B](transformer: MyTransformer[A, B]): MyList[B]
  def flatMap[B](transformer: MyTransformer[A, MyList[B]]): MyList[B]
  def filter(predicate: MyPredicate[A]): MyList[A]

  def ++[B>:A](list: MyList[B]): MyList[B]
  def foreach(f: A => Unit): Unit
  def sort(comparison: (A, A) => Int): MyList[A]
//  def zipWith[B, C](list: MyList[B], zip: (A, B) => C): MyList[C]
}

case class Cons[+A](h: A, t: MyList[A]) extends MyList[A] {
  def head: A = h
  def tail: MyList[A] = t
  def isEmpty: Boolean = false
  def add[B >: A](element: B): MyList[B] = new Cons(element, this)
  override def printElements: String = {
    if(t.isEmpty) "" + h
    else h.toString + " " + t.printElements
  }
  /*
  [1,2,3].map(n*2)
    = new Cons(1 * 2, [2,3].map(n*2)
    = new Cons(2, new Cons(2 * 2, [3].map(n*2))
    = new Cons(2, new Cons(4, new Cons(3 * 2, Empty.map(n * 2)))
    = new Cons(2, new Cons(4, new Cons(6, Empty)))

  */

  def map[B](transformer: MyTransformer[A, B]): MyList[B] = {
    Cons(transformer.transform(h), t.map(transformer))
  }

  /*
    [1, 2].flatMap(n => [n, n+1])
    = [1,2] ++ [2].flatMap(n => [n + 1])
    = [1,2] ++ [2,3] ++ Empty.flatMap(n => [n+1])
    = [1,2] ++ [2,3] ++ Empty
    = [1,2,2,3]
  */
  def flatMap[B](transformer: MyTransformer[A, MyList[B]]): MyList[B] =
    transformer.transform(h) ++  t.flatMap(transformer)


/*
  [1,2,3].filter(n%2 == 0)
  = [2,3.filter(n%2==0)
  = new Cons(2, [3].filter(n%2==0))
  = new Cons(2, Empty.filter(n%2==0))
  = new Cons(2, None)


*/
  def filter(predicate: MyPredicate[A]): MyList[A] = {
    if (predicate.test(h)) Cons(h, t.filter(predicate))
    else t.filter(predicate)
  }
  def ++[B>:A](list: MyList[B]): MyList[B] = new Cons(h, t ++ list)

  override def foreach(f: A => Unit): Unit = {
    f(h)
    t.foreach(f)
  }

  override def sort(comparison: (A, A) => Int): MyList[A] = ???
  /*
    override def sort(comparison: (A, A) => Int): MyList[A] = {
    def insert(x: A, sortedList: MyList[A]): MyList[A] = {
      if (sortedList.isEmpty) new Cons(x, Empty)
      else if (comparison(x, sortedList.head) <= 0) new Cons(x, sortedList)
      else new Cons(sortedList.head, insert(x, sortedList.tail))
    }
    val sortedTail = t.sort(comparison)
    insert(h, sortedTail)
  }
  */

  def zipWith[A, B, C](list: MyList[B], zip: (A, B) => C): MyList[C] = ???
//  {
//    if(!list.isEmpty) throw new RuntimeException("list do not have the same length")
//    else new Cons(zip(h, list.head), t.zipWith(list.tail, zip))
//  }

  def fold[B](start: B)(operator: (B, Nothing) => B): B = start

}

case object Empty extends MyList[Nothing] {
  def head: Nothing = throw new NoSuchElementException
  def tail: MyList[Nothing] = throw new NoSuchElementException
  def isEmpty: Boolean = true
  def add[B >: Nothing](element: B): MyList[B] = new Cons(element, Empty)
  override def printElements: String = ""
  def map[B](transformer: MyTransformer[Nothing, B]): MyList[B] = Empty
  def flatMap[B](transformer: MyTransformer[Nothing, MyList[B]]): MyList[B] = Empty
  def filter(predicate: MyPredicate[Nothing]): MyList[Nothing] = Empty
  def ++[B>:Nothing](list: MyList[B]): MyList[B] = list
  override def foreach(f: Nothing => Unit): Unit = ()
  override def sort(comparison: (Nothing, Nothing) => Int): MyList[Nothing] = Empty
  def zipWith[B, C](list: MyList[B], zip: (Nothing, B) => C): MyList[C] = {
    if(!list.isEmpty) throw new RuntimeException("list do not have the same length")
    else Empty
  }
//  def fold[B](start: B)(operator: (B, A) => B): B = t.fold(operator(start, h))(operator)

}


val list = new Cons(1, new Cons(2, new Cons(3, Empty)))
val list2 = new Cons(1, new Cons(2, new Cons(3, Empty)))
println("=== start: foreach === ")
list2.foreach(println)
println("=== end: foreach === ")
println(list.head)
println(list.tail.head)
println(list.add(4).head)
println(list.isEmpty)
println("=====")
println(list.equals(list2)) // due to the case class
println("=====")

println(list.filter(_ % 2 == 0))
println(list.map(_ * 2))
println(list.flatMap(new MyTransformer[Int, MyList[Int]] {
  override def transform(elem: Int): MyList[Int] = new Cons(elem, new Cons(elem + 1, Empty))
}))

println("=== start: for comprehension === ")

println(
for {
  n <- list
  n2 <- list2
} yield n + n2
)

println("=== start: for comprehension === ")

// polymorphic call
println(list.toString)

// zip
//println(list.zipWith[Int, Int](list2, _ + _))


// fold
//println(list.fold(0)(_ + _))

val listOfInt: MyList[Int] = new Cons(1, new Cons(2, Empty))
listOfInt.printElements

val listOfStr: MyList[String] = new Cons("a", new Cons("B", Empty))
listOfStr.printElements















// My Implementation
class Node(n: Int) {
  var data = n
  var next: Node = null
}


abstract class LL {
  var root: Node;

  def add(n: Int): Unit = {
    if (root == null) root = new Node(n)
    val newNode = new Node(n)
    newNode.next = new Node(n)
    root = newNode
  }

  def head(): Node = root

  def isEmpty(): Boolean = root == null

  def print(): Unit = {
    var temp = root
    while (temp != null) {
      printf("%d ", temp.data)
      temp = temp.next
    }
  }
}
