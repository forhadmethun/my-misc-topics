package rock_the_jvm.concurrency

import scala.collection.mutable
import scala.util.Random

object ThreadCommunication extends App {

  /*
  // producer consumer problem
  producer -> [x] <- consumer
  producer will create the value for the wrapped container then the consumer should read the valu e
  -> classical multi threaded problem while a thread needs to wait until another thread finishes it's job
  */

  class SimpleContainer {
    private var value: Int = 0

    def isEmpty: Boolean = value == 0
    def set(newValue: Int) = value = newValue
    def get = {
      val result = value
      value = 0
      result
    }
  }

  def naiveProdCons(): Unit = {
    val container = new SimpleContainer

    val consumer = new Thread(() => {
      println("[consumer] waiting")
      while(container.isEmpty) {
        println("[consumer] actively waiting")
      }
      println("[consumer] i have consumed " + container.get)
    })

    val producer = new Thread(() => {
      println("[producer] computing")
      Thread.sleep(500)
      val value = 2
      println("[producer] I have produced " + value)
      container.set(value)
    })

    consumer.start()
    producer.start()

  }

  // improved version [ wait, notify ]

  // synchronized: locks the object, only ref type can have synchronized
  // assumptions: (i) no guarantee who gets the first lock (ii) keep minimal sync (iii) thread safety is always important

  /***
   * wait() - ing on an object's monitor suspends the thread indefinitely
   *
   * val someObj = "hello"
   * someObj.syncronized {  <-- lock the object's monitor
   *  // code ...
   *  someObj.wait()        <-- release lock and wait
   *  // code ...           <-- when allowed to proceed, lock the monitor again and continue
   * }
   *
   * someObj.syncronized {  <-- lock the object's monitor
   *  // code
   *  someObj.notify()      <-- signal one sleeping thread that can continue
   *  // code               <-- but only after i'm done and ublock the monitor , use notifyAll() to notify all
   * }
   *
   *
   */

  def smartProdCons(): Unit = {
    val container = new SimpleContainer
    val consumer = new Thread(() => {
      println("[consumer] waiting...")
      container.synchronized {
        container.wait()
      }
      println("[consumer] I have consumed: " + container.get)
    })
    val producer = new Thread(() => {
      println("[producer] hard at work")
      Thread.sleep(500)
      val value = 23
      container.synchronized {
        println("[produccer] I am producing")
        container.set(value)
        container.notify()
      }
    })
  }

//
//  def main(args: Array[String]): Unit = {
//    println("workin!!")
//  }


  /* Producer consumer level 2 */
  /**
   *
   * Producer -> [?, ?, ?] -> Consumer
   */
  def prodConsLargeBuffer(): Unit = {
    val buffer: mutable.Queue[Int] = new mutable.Queue[Int]
    val capacity = 3

    val consumer = new Thread(() => {
      val random = new Random()
      while(true) {
        buffer.synchronized {
          if (buffer.isEmpty) {
            println("[Consumer] buffer empty, waiting")
            buffer.wait()
          }

          // there must be one value here
          val x = buffer.dequeue()
          println("[consumer] consumed " + x)
          buffer.notify()
        }
        Thread.sleep(random.nextInt(500))
      }
    })

    val producer = new Thread(() => {
      val random = new Random()
      var i = 0
      while(true) {
        buffer.synchronized {
          if (buffer.size == capacity) {
            println("[producer] buffer is full, waiting...")
            buffer.wait()
          }
          // there must be one empty space at buffer
          println("[producer] producing " + i)
          buffer.enqueue(i)
          buffer.notify()
          i = i + 1
        }
        Thread.sleep(random.nextInt(500))
      }
    })

  }

  /** Multi Producer consumer **/

  class Consumer(i: Int, buffer: mutable.Queue[Int]) extends Thread {
    override def run(): Unit = {
      val random = new Random()
      while(true) {
        buffer.synchronized {
          while (buffer.isEmpty) {
            println("[Consumer] buffer empty, waiting")
            buffer.wait()
          }

          // there must be one value here
          val x = buffer.dequeue()
          println("[consumer] consumed " + x)
          buffer.notify()
        }
        Thread.sleep(random.nextInt(500))
      }
    }
  }

  class Producer(i: Int, buffer: mutable.Queue[Int], capacity: Int) extends Thread {
    override def run(): Unit = {
      val random = new Random()
      var i = 0
      while(true) {
        buffer.synchronized {
          while (buffer.size == capacity) {
            println("[producer] buffer is full, waiting...")
            buffer.wait()
          }
          // there must be one empty space at buffer
          println("[producer] producing " + i)
          buffer.enqueue(i)
          buffer.notify()
          i = i + 1
        }
        Thread.sleep(random.nextInt(500))
      }
    }
  }

  def multiProducerConsumer(nConsumers: Int, nProducer: Int): Unit = {
    val buffer: mutable.Queue[Int] = new mutable.Queue[Int]()
    val capacity = 3

    (1 to nConsumers).foreach(i => new Consumer(i, buffer).start())
    (1 to nProducer).foreach(i => new Producer(i, buffer, capacity).start())
  }

 }
