def fact(n: Int): Int = {
  def factUtil(n: Int, acc: Int = 1): Int = {
    if (n <= 1) acc
    else factUtil(n - 1, acc * n)
  }

//  factUtil(n, 1)
// with default param
// N.B: Default param cannot be omitted in the beginning
  factUtil(n)
}

fact(5)

def savePic(format: String = "Hello", width: Int = 1920, height: Int = 1080): Unit = println("Hey ya")
// named argument
savePic(width = 500)

savePic(height = 200, width = 200, format = "bmp")
