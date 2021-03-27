import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class StringManipulatorByLabelText {
    static String inputPath = "/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/input";
    static String outputPath = "/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/output";

    public static FileWriter fw;

    public static void main(String[] args) throws Exception {
        Collection<File> fileCollection = listFileTree(new File(inputPath));
        StringBuffer sb = new StringBuffer();
        handleStringManipulationByCSV(new File("/media/forhad/Development/MyCodes/Code/Others/general-topics/misc-concept/string-manipulation/src/main/java/files/input/Excepts_Dedoose_Edited.csv"));


//        fw  = new FileWriter(outputPath+"/"+"combined-out.txt");
//        try {
//            fw.write(sb.toString());
//        } catch (IOException ex) {
//            ex.printStackTrace();
//        }
//        fw.close();

    }

    private static void  handleStringManipulationByCSV(File file) throws Exception{

        String path = file.getAbsolutePath();

        BufferedReader reader = new BufferedReader(new FileReader(path));

        String[] emoticonsArray = {"Appreciate","Connect","Emotional expression","Affirming utterance","Reader / audience sensitivity","Personal / Identity expression","Differences statements"};

        ArrayList<String> emoticons = new ArrayList<>(Arrays.asList(emoticonsArray));

        List<String> lines = new ArrayList<>();

        Map<String, ArrayList<String>> stringArrayListMap = new HashMap<>();

        emoticons.forEach(e->{
            stringArrayListMap.put(e,new ArrayList<>());
        });

        String line = null;
        int lineNumber = 1;
        while ((line = reader.readLine()) != null) {
            for(String e: emoticons){
                if(line.split("\",\"").length>1) populateMapData(stringArrayListMap,e,line,emoticons);
            }
            if(line.split("\",\"").length>1)
            System.out.println((lineNumber++) +" : " + line.split("\",\"")[0] + " || " + line.split("\",\"")[1]);
        }





         printMapData(stringArrayListMap,outputPath+"/"+file.getName().replace(".csv","-" + "out.txt"));
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
