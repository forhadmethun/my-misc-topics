package functional;

import java.util.function.Predicate;

public class _Predicate {
    static Predicate<String> isPhoneNumberValidForEstonia = phoneNumber -> phoneNumber.startsWith("+372");
    static Predicate<String> isPhoneNumberValidForBD = phoneNumber -> phoneNumber.startsWith("+880");

    public static void main(String[] args) {
        System.out.println(isPhoneNumberValidForEstonia.test("+372"));
        System.out.println(isPhoneNumberValidForEstonia.or(isPhoneNumberValidForBD).test("+880"));
    }
}
