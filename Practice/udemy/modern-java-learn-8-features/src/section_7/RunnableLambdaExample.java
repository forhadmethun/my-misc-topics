package section_7;

public class RunnableLambdaExample {
    public static void main(String[] args) {
        // before 8
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                System.out.println("inside runnable 1");
            }
        };
        new Thread(runnable).start();

        // java 8
        Runnable runnableLambda = () -> System.out.println("from lambda");
        new Thread(runnableLambda).start();
        new Thread(() -> System.out.println("lambda inside thread"));
    }
}
