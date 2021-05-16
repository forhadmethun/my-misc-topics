package section_3;

import java.util.stream.IntStream;

//sum of 100 numbers
class ImperativeVsDeclarative{
    public static void main(String[] args) {
        // imperative
        int sum = 0;
        for(int i = 0; i <= 100; i++){ // will be issue for multi-threaded environment
            sum = sum + i;
        }
        System.out.println(sum);

        //declerative
        int sum1 = IntStream.rangeClosed(0, 100) // external iteration
                .sum();
        System.out.println(sum1);
    }
}
