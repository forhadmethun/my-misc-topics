package files;

public class MyThread2 extends Thread{
    String msg;
    MyThread1 t1;
    public MyThread2(MyThread1 fp, String str){
        t1 = fp;
        msg = str;
        start();
    }
    public void run(){{
        synchronized (t1)
         {

             try {
                 t1.display(msg);
             } catch (InterruptedException e) {
                 e.printStackTrace();
             }
         }
    }
    }

}
