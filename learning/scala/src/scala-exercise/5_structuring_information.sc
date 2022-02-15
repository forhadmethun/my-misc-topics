case class Note(
                 name: String,
                 duration: String,
                 octave: Int)

val c3 = Note("C", "Quarter", 3)

sealed trait Symbol
case class Note(name: String, duration: String, octave: Int) extends Symbol
case class Rest(duration: String) extends Symbol

val symbol1: Symbol = Note("C", "Quarter", 3)
val symbol2: Symbol = Rest("Whole")

def symbolDuration(symbol: Symbol): String =
  symbol match {
    case Note(name, duration, octave) => duration
    case Rest(duration) => duration
  }

val invalidNote = Note("not a name", "not a duration", 3)


sealed trait Duration
case object Whole extends Duration
case object Half extends Duration
case object Quarter extends Duration

def fractionOfWhole(duration: Duration): Double =
  duration match {
    case Whole => 1.0
    case Half =>
      0.5

    case Quarter =>
      0.25

  }
fractionOfWhole(Half)
