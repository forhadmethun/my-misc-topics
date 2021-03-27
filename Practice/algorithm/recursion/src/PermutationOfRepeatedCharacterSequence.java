import java.util.*;


class PermutationOfRepeatedCharacterSequence{
    public static void main(String[] args){

    }

    ArrayList<String> printPerms(String s){
        ArrayList<String> result = new ArrayList<String>(); 
        HashMap<Character, Integer> map = buildFreqTable(s); 
        printPerms(map, "", s.length(), result); 
        return result;
    }
    HashMap<Character, Integer> buildFreqTable(String s){
        HashMap<Character, Integer> map = new HashMap<Character, Integer>(); 
        for(char c : s.toCharArray()){
            if(!map.containsKey(c)){
                map.put(c,0);
            }
            map.put(c, map.get(c) + 1); 
        } 
        return map;
    }
    void printPerms(HashMap<Character, 
        Integer> map, 
        String prefix,
        int remaining, 
        ArrayList<String> result
     ){ 
        if(remaining == 0){
            result.add(prefix); 
            return;
        }
        for(Character c : map.keySet()){
            int count = map.get(c); 
            if( count > 0){
                map.put(c, count - 1); 
                printPerms(map, prefix + c, remaining - 1, result);
                map.put(c, count); 
            }
        }

    }

}