val o: Option[Int] = Some(4)
println(o)

val n:Option[Int] = None
println(n)

// unsafe API
def unsafe(): String = null


//val result = Some(unsafe())
// invalid, Some should always hold valid value


val result = Option(unsafe())
println(result)

def backUp(): String = "A valid result"

val chained = Option(unsafe()).orElse(Option(backUp()))
println(chained)


// DESIGN unsafe API
def betterUnsafe(): Option[String] = None
def betterBackup(): Option[String] = Some(backUp())

val betterChained = betterUnsafe() orElse betterBackup()
println(betterChained)

// function on Option
println(o.isEmpty)
