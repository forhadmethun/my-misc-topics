package functional;

import java.util.Optional;

public class _Optional {
    public static void main(String[] args) {
        var blah = "str";
        Optional.ofNullable("forhad@gmail.com")
//        Optional.ofNullable(null)
                .ifPresentOrElse(
                        email -> System.out.println("sending email to : " + email),
                        () -> System.out.println("no email given")
                );
    }
}
