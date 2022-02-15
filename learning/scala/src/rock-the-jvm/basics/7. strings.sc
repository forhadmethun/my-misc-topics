var str: String = "Hello world"
println(str.charAt(2))
println(str.substring(2, 4))
println(str.split(" ").toList)
println(str.startsWith("Hello"))
println(str.replace(" ", "-"))
println(str.toLowerCase)
println(str.length)

val numInt = "42"
val num = numInt.toInt
println('a' +: numInt :+ 'z')
println(str.reverse)
println(str.take(2))

// String interpolation

// S interpolation
val name = "forhad"
val age = 27
val greet = s"Hello, my name is $name and ${age + 1} years old"

// F interpolation ( formatted)
val speed = 1.2f
val myth = f"$name%s can eat $speed%2.2f burgers per min"

// raw interplation
println(raw"This is \n new line")
val escaped = "This is another \n new line"
println(raw"$escaped")
