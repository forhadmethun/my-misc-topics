import java.util.*;
import java.io.*;

class BasicStringProcessingSkillsCP3{
    public static void main(String[] args) throws Exception{
        task1();
        task2();
        task3();
        task4();
        task5();
        task6();
    }
    /*
    1. 
    (a) Do you know how to store a string in your favorite programming language?
    (b) How to read a given text input line by line?
    (c) How to concatenate (combine) two strings into a larger one?
    (d) How to check if a line starts with a string ‘.......’ to stop reading input?
    */ 
    public static void task1() throws Exception{
        Scanner sc = new Scanner(new File("/home/forhad/Programming/Code/Others/library_codes/source_file/ch6/ch6.txt"));
        String line; 
        StringBuilder sb = new StringBuilder();
        int count = 1;
        while(sc.hasNext()){
            line = sc.nextLine();
            if(line.contains("......."))break;
            System.out.println(line);
            if(count++ <= 2) sb.append(line);
        }
        System.out.println("-------- concatenated two string---------"); 
        System.out.println(sb.toString());
    }
    /*
    2.
    (a) How to find the first occurrence of a substring in a string (if any)?
    Do we need to implement a string matching algorithm (e.g. Knuth-Morris-Pratt
    algorithm discussed in Section 6.4, etc) or can we just use library functions?
    (b) How to find the next occurrence(s) of a substring in a string (if any)?
    */
    public static void task2() throws Exception{
        String T = "I love CS3233 Competitive Programming. i also love AlGoRiThM"; 
        String P[] = {"I","love","book"};
        for(String p : P){
            task2Helper(T,p);
        }

    }
    public static void task2Helper(String T, String P) throws Exception{
        List<Integer> indicesList = new ArrayList<>(); 
        for(int i = 0; i < T.length(); i++){
            int ti = i; 
            int pi = 0; 
            while(pi < P.length() && T.charAt(ti) == P.charAt(pi)){
                // System.out.println(i + ":" + T.charAt(i));    
                pi++;
                ti++;
            }
            if(pi == P.length()){
                indicesList.add(i);
            }
        } 
        System.out.println(indicesList.size() > 0 ? indicesList : -1);
    }

    /*
     Suppose we want to do some simple analysis of the characters in T and also to transform
each character in T into lowercase. The required analysis are: How many digits, vowels
[aeiouAEIOU], and consonants (other alphabets that are not vowels) are there in T?
Can you do all these in O(n) where n is the length of the string T?
    */
    public static void task3(){
        String numbers = "0123456789"; 
        String vowels = "aeiouAEIOU"; 
        String consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
        StringBuilder lowerCaseT = new StringBuilder(); 
        String T = "01AbcdeiouUXmnOpzux0123kdxalA!x&$Xu";
        int digitCount = 0;
        int vowelsCount = 0;
        int consonantsCount = 0;

        for(int i = 0; i < T.length(); i++){
            int asciiCode = T.charAt(i);
            if( (asciiCode >= 65 && asciiCode <= 90) 
            //|| (asciiCode >= 97 && asciiCode <= 122) 
            ){
                char cap =(char) (asciiCode+32);
                lowerCaseT.append((cap + ""));
            }else{
                lowerCaseT.append(T.charAt(i));            
            }

            if((asciiCode >= 48 && asciiCode <= 57)){
                digitCount++;
            }else if(vowels.contains(""+T.charAt(i))){
                vowelsCount++;
            }else if(consonants.contains(""+T.charAt(i))){
                consonantsCount++;
            }

        }
        System.out.println("-------------lowercase--------------");
        System.out.println(lowerCaseT.toString());
        System.out.println("vowel: " + vowelsCount);
        System.out.println("consonants: " + consonantsCount); 
        System.out.println("numbers: " + digitCount);
    }
/*
(a) How to tokenize a string?
(b) How to store the tokens (the shorter strings) in an array of strings?
(c) How to sort an array of strings lexicographically?
*/
    public static void task4(){
        System.out.println("---task4----");
        String T = "i love cS3233 competitive programming. i also love alGoRiThM"; 
        String arrT[] = T.split(" "); 
        // System.out.println(arrT);
        for(String t: arrT){
            System.out.println(t);
        }
        System.out.println("---after sorting---");
        Arrays.sort(arrT); 
        for(String t: arrT){
            System.out.println(t);
        }
    }
    /*
     Now, identify which word appears the most in T. In order to answer this query, we
need to count the frequency of each word. For T, the output is either ‘i’ or ‘love’,
as both appear twice. Which data structure should be used for this mini task?
    */
    public static void task5(){
        System.out.println("---------task 5 --------------");
        String T = "i love cS3233 competitive programming. i also love alGoRiThM"; 
        Map<String, Integer> wordCountMap = new HashMap(); 
        String arrT[] = T.split(" ");
        for(String t: arrT){
            if(wordCountMap.containsKey(t)){
                wordCountMap.put(t,wordCountMap.get(t) + 1);
            }
            else{
                wordCountMap.put(t,1);
            }
        }
        String mostlyOccuredString = ""; 
        int mostlyOccuredStringCount = Integer.MIN_VALUE;
    
        for(String t: wordCountMap.keySet()){
            int count = wordCountMap.get(t);
            System.out.println(t + " =>" + count);
            if(count > mostlyOccuredStringCount){
                mostlyOccuredString = t; 
                mostlyOccuredStringCount = count;
            }
        }

        System.out.println("---- mosly occured string count -----------"); 
        System.out.println(mostlyOccuredString); 
        System.out.println(mostlyOccuredStringCount); 
        

    }
    /*
The given text file has one more line after a line that starts with ‘.......’ but the
length of this last line is not constrained. Your task is to count how many characters
there are in the last line. How to read a string if its length is not known in advance?
    */
    public static void task6() throws Exception{
        Scanner sc = new Scanner(new File("/home/forhad/Programming/Code/Others/library_codes/source_file/ch6/ch6.txt"));
        String line; 
        StringBuilder sb = new StringBuilder();
        int count = 1;
        String lastLine = "";
        while(sc.hasNext()){
            line = sc.nextLine();
            // if(line.contains("......."))break;
            System.out.println(line);
            if(count++ <= 2) sb.append(line);
            lastLine = line;
        }
        System.out.println("-------- concatenated two string---------"); 
        System.out.println(sb.toString());
        System.out.println("lastLine:");
        System.out.println(lastLine);
        System.out.println(lastLine.length());
    }
    
}

