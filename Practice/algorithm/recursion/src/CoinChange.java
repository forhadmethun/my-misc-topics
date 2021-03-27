import java.util.*;
public class CoinChange {
    public static void main(String[] args) {
        int denoms[] = {25, 10, 5, 1};
        System.out.println(makeChange(100,denoms,0));
    }
    static int makeChange(int amount, int[] denoms, int index){
        if(index >= denoms.length - 1){
            return 1;
        }
        int denomAmount = denoms[index];
        int ways = 0;
        for( int i = 0; i*denomAmount <= amount; i++){
            int amountRemaining = amount - i * denomAmount;
            ways += makeChange(amountRemaining, denoms, index + 1);
        }
        return ways;
    }
}
