package section_18;

interface A{
    default void a(){
        System.out.println("A");
    }
}

interface B extends A{
    default void b(){
        System.out.println("B");
    }
    default void a(){
        System.out.println("overrriden A");
    }
}

interface C{
    default void c(){
        System.out.println("C");
    }
}

interface Ccopy{
    default void c(){
        System.out.println("Ccopy");
    }
}


public class MultipleInheritance implements A, B, C, Ccopy{
    public static void main(String[] args) {
        MultipleInheritance m = new MultipleInheritance();
        m.a(); // always child class overrides!!!
        m.b();
        m.c();
    }

    @Override // only way to resolve circular dependency to override the method in the child class!!
    public void c() {
        Ccopy.super.c();
    }
}
