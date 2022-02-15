object Main extends App {
  def callByValue(x: Long): Unit = {
    println(x)
    println(x)
  }

  def callByName(x: => Long): Unit = {
    println(x)
    println(x)
  }
  def main(args: Array[String]): Unit = {
    callByName(System.nanoTime())
  }
}


