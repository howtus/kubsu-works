import Workers.HourlyWorker;
import Workers.InterestRateEmployee;
import Workers.StateEmployee;
import Workers.Worker;

public class Main {

    public static void main(String[] args) {

        Worker w01 = new Worker("Дмитрий", "Иванов", 21, "Работник");
        HourlyWorker w02 = new HourlyWorker("Александр", "Демченко", 19, "Работник ПБО", 145, 96);
        StateEmployee w03 = new StateEmployee("Николай", "Медведев", 54, "Директор", 364500);
        InterestRateEmployee w04 = new InterestRateEmployee("Владимир", "Ленский", 36, "Риелтор", 0.15, 1200000);

        // Для начала мы создали 4 объекта разных классов и вывели их в консоль
        w01.show();
        w02.show();
        w03.show();
        w04.show();

        System.out.println("=================");
        // Демонстрация методов класса служащего с почасовой оплатой
        w02.setRate(120);
        w02.show();
        w02.setHours(110);
        w02.show();

        System.out.println("=================");
        // Демонстрация методов класса служащего в штате
        w03.setPremium(12560);
        w03.show();

        System.out.println("=================");
        // Демонстрация методов класса служащего с процентной ставкой
        w04.setPercent(0.3);
        w04.show();
        w04.setSalesAmount(900000);
        w04.show();
    }
}