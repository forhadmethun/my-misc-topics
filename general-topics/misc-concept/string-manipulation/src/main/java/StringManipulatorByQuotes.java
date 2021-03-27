import java.io.*;
import java.util.*;

public class StringManipulatorByQuotes {
    static String inputPath = "/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/input/lasdataset.csv";
    static String outputPath = "/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/output";

    public static FileWriter fw;

    public static void main(String[] args) throws Exception {
        StringBuffer sb = new StringBuffer();
        List<String> outputList = handleStringManipulationByCSV(new File(inputPath));
        outputList.forEach(e->{
            sb.append(e + "\n");
        });

        fw  = new FileWriter(outputPath+"/"+"lasdataset_out.csv");
        try {
            fw.write(sb.toString());
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        fw.close();

    }

    private static List<String>  handleStringManipulationByCSV(File file) throws Exception{

        List<String> outputList = new ArrayList<>();
        String path = file.getAbsolutePath();

        BufferedReader reader = new BufferedReader(new FileReader(path));
        String line = null;
        int lineNumber = 1;

        while ((line = reader.readLine()) != null) {
            List<String> lineList = Arrays.asList(line.split(","));
            int len = lineList.size();
            String str = "";
            for(int i=5;i< len;i++){
                str += lineList.get(i);
            }
//            String[] words = str.split("\\s+");
            String quotes = "QUOTES";
            int index = str.indexOf(quotes)+(quotes.length());
            lineNumber++;
//            if(index > str.length()-1)return null;
            try {
                String expectedString = str.substring(index);
                List<String> newLineList = Arrays.asList(expectedString.split("//"));

                String outputString =
                        lineList.get(0) + "," +
                                lineList.get(1) + "," +
                                lineList.get(2) + "," +
                                lineList.get(3) + "," +
                                lineList.get(4) + ",";
                String allLines ="";

                for (int i = 0; i < newLineList.size(); i++) {

                    String currentLine = newLineList.get(i);

                    boolean interviewer = false;
                    boolean interviewee = true;

                    String[] words = currentLine.split("\\s+");

                    String intervieweeString = "";

                    for(int j = 0; j < words.length; j++){

                        if(words[j].contains("Interviewee:")){
                            intervieweeString +=words[j] + " ";
                            if(j+1 == words.length)break;
                            j++; // check corner case
                            while (!words[j].contains("Interviewer:") && !words[j].contains("Interviewee:")) {
                                intervieweeString += words[j] + " ";
                                if(j+1 == words.length)break;
                                j++;
                            }
//                            int x = 0;
//                            outputList.add(outputString + intervieweeString);
                            allLines+=intervieweeString;

                            intervieweeString = "";
                        }

//                        if(words[j].equals("Interviewer:")){
//                            while (!words[j].equals("Interviewee:")) {
//                                j++;
//                            } j++;
//                        }

//                        while (!words[j].equals("Interviewee:")) {
//                            if(words[j].equals("Interviewer:")){ j--; break;}
//                            j++;
//                            intervieweeString += words[j];
//                        }

                    }








//                    outputList.add(outputString + newLineList.get(i));
                }
                if(allLines.equals(""))continue;
                outputList.add(outputString+allLines);
            }catch(Exception e){
                continue;
            }

//            if(lineNumber == 2) break;
        }



        return outputList;

//        printMapData(stringArrayListMap,outputPath+"/"+file.getName().replace(".csv","-" + "out.txt"));
    }


    private static String printMapData(Map<String, ArrayList<String>> stringArrayListMap,String path) throws IOException {
        StringBuffer sb = new StringBuffer();
        fw  = new FileWriter(path);
        stringArrayListMap.keySet().forEach(k->{
            stringArrayListMap.get(k).forEach(e->{
                try {
                    String currentLine = k+ " : " + e+"\n";
                    fw.write(currentLine);
                    sb.append(currentLine);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            });
        });
        fw.close();
        return sb.toString();
    }

    private static void populateMapData(Map<String, ArrayList<String>> stringArrayListMap, String e, String line, ArrayList<String> emoticons) {
        if (line.contains(e)) {
            String tempString = new String(line.split("\",\"")[0]);
//            for(String emo: emoticons){
//                tempString = new String(tempString.replace(emo,""));
//            }
//            String regEx = "(@.([^\\s]+))";
            stringArrayListMap.get(e).add(tempString);
        }
    }


}
