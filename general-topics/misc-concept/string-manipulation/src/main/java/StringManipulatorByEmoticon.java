import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern; 

class StringManipulatorByEmoticon {
    static String inputPath = "/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/input";
    static String outputPath = "/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/output";

    public static void main(String[] args) throws Exception {
        Collection<File> fileCollection = listFileTree(new File(inputPath));
        StringBuffer sb = new StringBuffer();
        for (File file : fileCollection) {
            if(file.getAbsolutePath().endsWith(".csv")) sb.append(handleStringManipulationByCSV(file));
            if(file.getAbsolutePath().endsWith(".txt")) handleStringManipulationByTXT(file);
        }
    }

    private static void handleStringManipulationByTXT(File file) throws Exception  {
        BufferedReader reader = new BufferedReader(new FileReader(file.getAbsoluteFile()));
        fw  = new FileWriter(outputPath+"/"+file.getName().replace(".txt","-" + "out.txt"));
        String line = null;
        while ((line = reader.readLine()) != null) {
            String modifiedLine = new String(line);
            String currentLine = new String(line);
            Pattern pattern = Pattern.compile("([0-9].*@)");
            Matcher matcher = pattern.matcher(currentLine);
            if(matcher.find()){
                String matchedString = matcher.group(1);
                Integer code = Integer.valueOf(matchedString.split("@")[1]);
                modifiedLine = new String (code + " : " + line.replace(matchedString,"")+"\n");
                System.out.println(modifiedLine);
                try {
                    fw.write(modifiedLine);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }


//            for(String e: emoticons){
//                populateMapData(stringArrayListMap,e,line,emoticons);
//            }
        }
        fw.close();
    }

    private static String handleStringManipulationByCSV(File file) throws Exception{
        String path = file.getAbsolutePath();
        BufferedReader reader = new BufferedReader(new FileReader(path));
        String[] emoticonsArray = {"Anger", "Anticipation","Disgust","Surprise","Joy","Fear", "Sadness","Trust"};
        ArrayList<String> emoticons = new ArrayList<>(Arrays.asList(emoticonsArray));
        List<String> lines = new ArrayList<>();
        Map<String, ArrayList<String>> stringArrayListMap = new HashMap<>();
        emoticons.forEach(e->{
            stringArrayListMap.put(e,new ArrayList<>());
        });
        String line = null;
        while ((line = reader.readLine()) != null) {
            for(String e: emoticons){
                populateMapData(stringArrayListMap,e,line,emoticons);
            }
        }
        return printMapData(stringArrayListMap,outputPath+"/"+file.getName().replace(".csv","-" + "out.txt"));
    }

    public static FileWriter fw;
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
            String tempString = new String(line);
            for(String emo: emoticons){
                tempString = new String(tempString.replace(emo,""));
            }
            String regEx = "(@.([^\\s]+))";
            stringArrayListMap.get(e).add(modifiedString(tempString,e).replaceAll(regEx,""));
        }
    }

    static String modifiedString(String line, String emo){
        return (line.replace("\t","")).replace("-","").replace(emo,"");
    }

    public static Collection<File> listFileTree(File dir) {
        Set<File> fileTree = new HashSet<File>();
        if(dir==null||dir.listFiles()==null){
            return fileTree;
        }
        for (File entry : dir.listFiles()) {
            if (entry.isFile()) fileTree.add(entry);
            else fileTree.addAll(listFileTree(entry));
        }
        return fileTree;
    }
}
