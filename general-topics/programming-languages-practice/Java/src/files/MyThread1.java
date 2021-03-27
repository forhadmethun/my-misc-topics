package files;

public class MyThread1{
     void display(String msg) throws InterruptedException {
        System.out.print("[" + msg);
        Thread.sleep(100);
        Thread.sleep(100);
        Thread.sleep(100);
        Thread.sleep(1000);
        System.out.println("]");
    }
}
