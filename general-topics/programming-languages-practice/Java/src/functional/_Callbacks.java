package functional;

import java.util.function.Consumer;

public class _Callbacks {
    public static void main(String[] args) {
        hello(
                "Forhad", "Hossain", value ->{
                    System.out.println(value);
                }
        );
        hello(
                "Forhad", null , value ->{
                    System.out.println(value);
                }
        );

        hello2(
                "Forhad", null , () ->{
                    System.out.println("Null value provided for lastName");
                }
        );

    }
    static void hello(String fName, String lName, Consumer<String> callback){
        if(lName != null){
            System.out.println(fName + " " + lName);
        }
        else{
            callback.accept(fName);
        }
    }

    static void hello2(String fName, String lName, Runnable callback){
        if(lName != null){
            System.out.println(fName + " " + lName);
        }
        else{
            callback.run();
        }
    }
}
