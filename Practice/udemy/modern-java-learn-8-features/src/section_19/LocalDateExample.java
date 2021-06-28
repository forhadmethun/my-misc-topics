package section_19;

import java.time.LocalDate;
import java.time.temporal.ChronoField;
import java.time.temporal.ChronoUnit;
import java.time.temporal.TemporalAdjuster;
import java.time.temporal.TemporalAdjusters;

public class LocalDateExample {
    public static void main(String[] args) {
        System.out.println(LocalDate.now());
        System.out.println(LocalDate.of(2021, 07, 1));
        System.out.println(LocalDate.ofYearDay(2021, 222));
        System.out.println(LocalDate.now().getMonth());
        System.out.println(LocalDate.now().getMonthValue());
        System.out.println(LocalDate.now().getDayOfWeek());
        System.out.println(LocalDate.now().getDayOfMonth());
        System.out.println(LocalDate.now().getDayOfYear());
        System.out.println(LocalDate.now().get(ChronoField.DAY_OF_MONTH));

        // modifying local date

        System.out.println(LocalDate.now().plusDays(2));
        System.out.println(LocalDate.now().plusMonths(2));
        System.out.println(LocalDate.now().minusDays(2));
        System.out.println(LocalDate.now().withYear(2012));
        System.out.println(LocalDate.now().with(ChronoField.YEAR, 2012));
        System.out.println(LocalDate.now().with(TemporalAdjusters.firstDayOfNextMonth()));

        System.out.println(LocalDate.now().minus(1, ChronoUnit.DAYS));
        System.out.println(LocalDate.now().isLeapYear());
        System.out.println(LocalDate.ofYearDay(2020, 01).isLeapYear());
        System.out.println(LocalDate.now().isEqual(LocalDate.now()));
        System.out.println(LocalDate.now().isBefore(LocalDate.now()));

//        System.out.println(LocalDate.now().minus(1, ChronoUnit.MINUTES)); // throws exception as time operation not supported on date
        System.out.println(LocalDate.now().isSupported(ChronoUnit.MINUTES));

    }
}
