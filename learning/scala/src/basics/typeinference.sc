object typeinference {
  val num = 5
  val dec = 5.1234123
  val x = 1 +  2 * 3.5
  List(1, 2, 3.2) // returns double
  List(1, true) // returns anyval
  List(1, true, "abc") // returns any time

  def addOne(x:Int) = x + 1
  def function1(x:Int) = if(x > 0) 1 else "negative" // return any

}