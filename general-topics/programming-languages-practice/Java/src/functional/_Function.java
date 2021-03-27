package functional;

import java.util.function.BiFunction;
import java.util.function.Function;

public class _Function {
    Function<String, String> toUpper = str -> str.toUpperCase();
    String toUpper(String str){
        return str.toUpperCase();
    }

    Function<Integer, Integer> incByOne = num -> num + 1;
    Integer incByOne(int num){
        return num + 1;
    }

    Function<Integer, Integer> mulByTen = num -> num * 10;
    Integer mulByTen(int num){
        return num * 10;
    }

    BiFunction<Integer, Integer, Integer> incByOneMulByN = (num, N) -> (num + 1) * N;
    Integer incByOneMulByN(Integer num, Integer N){
        return (num + 1) * N;
    }


    public static void main(String[] args) {
        //incByOne
        _Function function = new _Function();

        int incOneByOne = function.incByOne(1);
        System.out.println(incOneByOne);
        int incTowByOne = function.incByOne.apply(2);
        System.out.println(incTowByOne);


        //incByOneMulByTen
        int incByOneMulByTen = function.incByOneMulByN.apply(1,10);
        System.out.println(incByOneMulByTen);

    }
}
