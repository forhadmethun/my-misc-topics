class StringMethodCheck {
  public static void main(String[] args) {
      String stringName = "abc";
      System.out.println("============Start: Substring Method Check =======");
      int i = 1;
      System.out.println("stringName.substring(0,0): " + stringName.substring(0,i)); // prints  0 to i-1
      System.out.println("stringName.substring(1): " + stringName.substring(i));   // prints i to n-1
      System.out.println("===========End: Substring Method Check ========");
   }
}
