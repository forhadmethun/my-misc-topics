import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern; 

class StringManipulatorInTB {
    static String[] tb_hbc_list = {"20","50","76","156","408","180","231","356","360","404","508","104","566","586","608","643","710","764","834","704","116","140","178","426","430","516","598","694","894","716"};
    static String[] tb_or_hbc_list = {"20","76","120","156","180","231","356","360","404","426","454","508","104","566","710","764","800","834","894","716","72","140","148","178","288","624","430","516","598"};
    static String[] mdt_tb_hbc_list = {"50","156","408","180","231","356","398","404","360","508","104","566","586","608","643","710","764","804","860","704","20","31","112","417","598","604","498","706","762","716"};
    static String[] sdg_indicator = {"50","156","408","180","231","356","398","404","360","508","104","566","586","608","643","710","764","804","860","704","20","31","112","417","598","604","498","706","762","716"};
    static String inputPath = "D:\\MyCode\\Code\\Others\\general-topics\\misc-concept\\string-manipulation\\src\\main\\java\\files\\input\\tb";
    static String outputPath = "D:\\MyCode\\Code\\Others\\general-topics\\misc-concept\\string-manipulation\\src\\main\\java\\files\\output\\tb";

    public static void main(String[] args) throws Exception {
//        System.out.println("Working Directory = " + System.getProperty("user.dir"));
        Collection<File> fileCollection = listFileTree(new File(inputPath));
        StringBuffer sb = new StringBuffer();
        int x = 0;
        for (File file : fileCollection) {
            if(file.getAbsolutePath().endsWith(".csv")) handleStringManipulationByCSV(file);
//            if(file.getAbsolutePath().endsWith(".txt")) handleStringManipulationByTXT(file);
        }
    }
    private static void  handleStringManipulationByCSV(File file) throws Exception{
        String path = file.getAbsolutePath();
        BufferedReader reader = new BufferedReader(new FileReader(path));
        String line = null;
        int isoNumericIndex = 0;
        int yearIndex = 0;
        if((line = reader.readLine()) != null){
            String[] words = line.split(",");
            for(String w: words){
                if(w.contains("iso_numeric") || w.contains("GeoAreaCode")){
                    break;
                }

                isoNumericIndex++;
            }
            for(String w: words){
                if(w.contains("year")){
                    break;
                }
                yearIndex++;
            }

            if(isoNumericIndex>=words.length || yearIndex>=words.length){
                System.out.println(path);
                return;
            }

        }
        StringBuffer sb_tb_hbc_list = new StringBuffer();
        StringBuffer sb_tb_or_hbc_list = new StringBuffer();
        StringBuffer sb_mdt_tb_hbc_list = new StringBuffer();
        sb_tb_hbc_list.append(line+"\n");
        sb_tb_or_hbc_list.append(line+"\n");
        sb_mdt_tb_hbc_list.append(line+"\n");

        int count = 0;

        while ((line = reader.readLine()) != null) {
            String[] words = line.split(",");
            if(Arrays.stream(tb_hbc_list).anyMatch(words[isoNumericIndex]::contains) /*&& words[yearIndex].equals("2017")*/){
                sb_tb_hbc_list.append(line+"\n");
            }
            if(Arrays.stream(tb_or_hbc_list).anyMatch(words[isoNumericIndex]::contains) /*&& words[yearIndex].equals("2017")*/){
                sb_tb_or_hbc_list.append(line+"\n");
            }
            if(Arrays.stream(mdt_tb_hbc_list).anyMatch(words[isoNumericIndex]::contains) /*&& words[yearIndex].equals("2017")*/){
                sb_mdt_tb_hbc_list.append(line+"\n");
            }
        }
//        System.out.println(count);
        String fileName[] = file.getName().split("\\.");

        writeToFile(sb_tb_hbc_list, fileName[0]+"_1"+"_out." + fileName[1]);
        writeToFile(sb_tb_or_hbc_list, fileName[0]+"_2"+"_out." + fileName[1]);
        writeToFile(sb_mdt_tb_hbc_list, fileName[0]+"_3"+"_out." + fileName[1]);




        return;
    }

    static void writeToFile(StringBuffer sb, String extension) throws Exception{
        fw  = new FileWriter(outputPath+"/"+extension);
        try {
            fw.write(sb.toString());
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        fw.close();
    }
    public static FileWriter fw;
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
