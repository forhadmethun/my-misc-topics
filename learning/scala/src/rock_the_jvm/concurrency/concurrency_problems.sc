
def runInParallel(): Unit = {
  var x = 0
  val thread1 = new Thread(() => {
    x = 1
  })

  val thread2 = new Thread(() => {
    x = 2
  })
  thread1.start()
  thread2.start()
//  Thread.sleep(1000)
  println(x) // race conditions, due to mutable variables...!!!
  // massive issue in parallel computation
}

runInParallel()


case class BankAccount(var amount:Int)

def bu(bankAccount: BankAccount, stuff: String, price: Int): Unit = {
  bankAccount.amount = bankAccount.amount - price;
}
def buSafe(bankAccount: BankAccount, stuff: String, price: Int): Unit = {
  bankAccount.synchronized {
    bankAccount.amount = bankAccount.amount - price;
  }
}

(1 to 1000).foreach {
  _ =>
    val account = BankAccount(50000)
    val thread1 = new Thread(() => bu(account, "shoes", 3000))
    val thread2 = new Thread(() => bu(account, "phone", 4000))
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()
    if (account.amount != 43000) println(s"Aha! bank broken: ${account.amount}")
}

/*
Exercise:
1. Inception thread
  thread 1 ->
    thread 2 ->
      thread 3 ->
          ....

  each thread prints "hello from thread $i"
  print all messages in reverse order

2. What's the min and max value of x?
3. "sleep falacy" what's the value of message?
*/
//1
def inception(maxThreads: Int, i: Int = 1): Thread =
  new Thread(() => {
    if (i < maxThreads) {
      val newThread = inception(maxThreads, i + 1)
      newThread.start()
      newThread.join()
    }
    println(s"hello from thread $i")
  })

inception(50).start()

// 2
def minMax(): Unit = {
  var x = 0
  var thread = (1 to 100).map(_ => new Thread(() => x += 1))
  thread.foreach(_.start())
}

/*
max: 100
min: 1 // why? three steps to update variable, read, increase, assign
  all threads read x = 0 at the same time
  all threads (in parallel) compute 0 + 1 = 1
  all threads try to write x = 1
*/

// 3
def demoSleepFallacy(): Unit = {
  var message = ""
  val aThread = new Thread(() => {
    Thread.sleep(1000)
    message = "Scala is awesome"
  })
  message = "Scala rocks"
  aThread.start()
  Thread.sleep(1001)
  println(message)
}
// what's the output?
/*
almost always : "Scala is awsome",
is it guaranteed? NO
obnoxious situation: (possible)
// yields and cpu gives other threads to work on, in such case the race condition might happen
// it will print then assign the value to message
// join() will resolve the issue
*/
