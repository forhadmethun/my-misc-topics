var x = 10
while(x >= 0) {
  println(x)
  x = x - 1
}
printf("finished")

x = 10
do {
  x = x - 1
  println(x)
} while(x >= 0);
printf("backoff again")

for(x <- 1 to 10) {
  println(x)
}

printf("-----\n")
for(x <- 10 to 0 by - 1) {
  println(x)
}
println("End of reverse loop")

var y = for(x <- 1 to 10) yield x + 1

var word = "monday"
for(x <- 0 until word.length) {
  println(word(x))
}