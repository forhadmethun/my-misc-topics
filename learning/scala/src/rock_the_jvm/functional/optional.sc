import scala.util.Random

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

println(o.get) // UNSAFE -> might break

// function on Option
println(o.isEmpty)

println(o.map(_ * 2))
println(o.filter(_ >= 2))
println(o.flatMap(x => Option(x * 20)))

// for comprehension
val conf: Map[String, String] = Map(
  "host" -> "0.0.0.0",
  "port" -> "80"
)

class Connection {
  def connect = "Connected"
}

object Connection {
  val random = new Random(System.nanoTime())

  def apply(host: String, port: String): Option[Connection] = {
    if (random.nextBoolean()) {
      Some(Connection(host, port))
    }
    None
  }
}

// try to establish connection, if connected print from the connect method

val host = conf.get("host")
val port = conf.get("port")
val maybeConnection = host.flatMap(h => port.flatMap(p => Connection.apply(h, p)))
maybeConnection.map(_.connect).foreach(println)
println("hello")

// chained calls
conf.get("host")
  .flatMap(h => conf.get("port")
    .flatMap(p => Connection(h, p)))
  .map(con => con.connect)
  .foreach(println)

// for comprehension

val connStatus = for {
  host <- conf.get("host")
  port <- conf.get("port")
  connection <- Connection(host, port)
} yield connection.connect

connStatus.foreach(println)
