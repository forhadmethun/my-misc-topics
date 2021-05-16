package section_3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class RemoveDuplicatesFromListOfIntegers {
    public static void main(String[] args) {
        List<Integer> integerList = Arrays.asList(1, 2,2,5, 3, 4, 5, 6, 7, 8, 9 , 10);

        // imperative
        List<Integer> uniqueListImperative = new ArrayList<>();
        for (Integer i: integerList){
            if(!uniqueListImperative.contains(i)){
                uniqueListImperative.add(i);
            }
        }
        System.out.println(uniqueListImperative);

        // declarative
        final List<Integer> uniqueListDeclarative = integerList.stream()
                .distinct()
                .collect(Collectors.toList());
        System.out.println(uniqueListDeclarative);


    }
}
