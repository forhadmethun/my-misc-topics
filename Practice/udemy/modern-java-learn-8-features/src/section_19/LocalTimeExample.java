package section_19;

import java.time.LocalTime;
import java.time.temporal.ChronoField;
import java.time.temporal.ChronoUnit;

public class LocalTimeExample {
    public static void main(String[] args) {
        System.out.println(LocalTime.now());
        System.out.println(LocalTime.of(23, 23));
        System.out.println(LocalTime.of(23, 23, 23));
        System.out.println(LocalTime.of(23, 23, 23, 23));
        System.out.println(LocalTime.now().getHour());
        System.out.println(LocalTime.now().getMinute());
        System.out.println(LocalTime.now().get(ChronoField.CLOCK_HOUR_OF_DAY));
        System.out.println(LocalTime.now().toSecondOfDay());
        System.out.println(LocalTime.now().minusHours(1));
        System.out.println(LocalTime.now().minus(2, ChronoUnit.MINUTES));
        System.out.println(LocalTime.now().with(LocalTime.MIDNIGHT));
        System.out.println(LocalTime.now().with(ChronoField.HOUR_OF_DAY, 5));
        System.out.println(LocalTime.now().withHour(5));
    }
}
