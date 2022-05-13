package rock_the_jvm.concurrency;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class ProducerConsumer {
    public static void main(String[] args) {
        System.out.println("Hello wrold");
        Queue<Integer> queue = new LinkedList<>();
        int capacity = 3;

        Producer p = new Producer(queue, capacity);
        Consumer c = new Consumer(queue, capacity);

        p.start();
        c.start();
    }



//    class Wrapper {
//        int val;
//
//        public int getVal() {
//            return val;
//        }
//
//        public void setVal(int val) {
//            this.val = val;
//        }
//
//        public boolean isEmpty () {
//            return val == 0;
//        }
//    }



}

class Producer extends Thread{
    Queue queue;
    int capacity;
    public Producer(Queue queue, int capacity) {
        this.queue = queue;
        this.capacity = capacity;
    }
    @Override
    public void run() {
        int i = 0;
        while (true) {
            synchronized (queue) {
                if (queue.size() == capacity) {
                    try {
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
//                Integer x = queue.poll();
                Integer val = i ++;//new Random(100).nextInt();
                queue.add(val);
                System.out.println("[producer] Added to queue: " + val);
                queue.notify();
            }
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread{
    Queue queue;
    int capacity;
    public Consumer(Queue queue, int capacity) {
        this.queue = queue;
        this.capacity = capacity;
    }
    @Override
    public void run() {
        while (true) {
            synchronized (queue) {
                if(queue.size() == 0) {
                    try {
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

                Integer val = (Integer)queue.poll();
                System.out.println("[consumer] Removed from queue: " + val);
                queue.notify();
                try {
                    Thread.sleep(800);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}