import java.util.concurrent.{Executor, Executors}

val aThread = new Thread(new Runnable {
  override def run(): Unit = println("Running in parallel")
})
aThread.start()

//aThread.join() block unti finishesh

val helloThread = new Thread(() => (1 to 5).foreach(_ => println("hello")) )
val byeThread = new Thread(() => (1 to 5).foreach(_ => println("bye")) )

helloThread.start()
byeThread.start()

val pool = Executors.newFixedThreadPool(10);
pool.execute(() => println("Something in the thread pool"))

pool.execute(() => {
  Thread.sleep(1000)
  println("will print after 1 sec")
})

pool.execute( () => {
  Thread.sleep(1000)
  println("Will print after 1 sec")
  Thread.sleep(1000)
  println("Will print after 2 sec")
})

pool.shutdown() // will shutdown the pool and will not accept any action

//pool.shutdownNow()

println(pool.isShutdown)


