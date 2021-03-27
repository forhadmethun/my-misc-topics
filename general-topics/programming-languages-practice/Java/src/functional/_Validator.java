package functional;

import java.time.LocalDate;
import java.time.Period;
import java.util.function.Function;

import static functional.ValidationResult.*;
import static functional.ValidationResult.EMAIL_NOT_VALID;
import static functional._Validator.isAdult;
import static functional._Validator.isEmailValid;

class Customer{
    String name, email, phoneNumber;
    LocalDate dob;

    public Customer(String name, String email, String phoneNumber, LocalDate dob) {
        this.name = name;
        this.email = email;
        this.phoneNumber = phoneNumber;
        this.dob = dob;
    }
}
enum ValidationResult {
    SUCCESS,
    PHONE_NUMBER_NOT_VALID,
    EMAIL_NOT_VALID,
    IS_NOT_AN_ADULT
}
public interface  _Validator extends Function<Customer, ValidationResult> {
    static _Validator isEmailValid(){
        return customer -> {
            System.out.println("running email validation");
            return customer.email.contains("@") ? SUCCESS : EMAIL_NOT_VALID;
        };
    }

    static _Validator isAdult(){
        return customer -> Period.between(customer.dob, LocalDate.now()).getYears() > 16 ? SUCCESS : IS_NOT_AN_ADULT;
    }

    default _Validator and (_Validator other){
        return customer -> {
            ValidationResult result = this.apply(customer);
            return result.equals(SUCCESS)? other.apply(customer) : result;
        };
    }
}
class Main{
    public static void main(String[] args) {
        Customer customer = new Customer(
                "Alice",
                "alice@gmail.com",
                "+0898787879878",
                LocalDate.of(2015, 1,1)
        );

        ValidationResult result = isEmailValid()
                .and(isAdult())
                .apply(customer);

        System.out.println(result);

    }
}
