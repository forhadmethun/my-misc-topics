
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

}



val list = new Cons(1, new Cons(2, new Cons(3, Empty)))
val list2 = new Cons(1, new Cons(2, new Cons(3, Empty)))
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

// polymorphic call
println(list.toString)



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
