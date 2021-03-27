import java.io.BufferedReader;
import java.io.InputStreamReader;

public class RunProcessWithJavaCode {
    public static void runCommand(String str){
        String s;
        Process p;
        try {
            // p = Runtime.getRuntime().exec("code");
            p = Runtime.getRuntime().exec(str);
            // p = Runtime.getRuntime().exec("./out");
            // p = Runtime.getRuntime().exec("ls -a");
            BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
            while ((s = br.readLine()) != null)
                System.out.println("line: " + s);
            p.waitFor();
            System.out.println("exit: " + p.exitValue());
            p.destroy();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String args[]) throws Exception{
        runCommand("ls -a");
        // runCommand("man man");
        // runCommand("g++ main.c -o out");
        // runCommand("./out");
        // runCommand("code");
    }
}
