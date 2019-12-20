package Workers;

public class HourlyWorker extends Worker {

    private int salary, rate, hours;

    public HourlyWorker(String firstName, String secondName, int age, String position, int rate, int hours) {
        super(firstName, secondName, age, position);
        this.rate = rate;
        this.hours = hours;
        setSalary();
    }


    @Override
    public void show() {
        super.show();
        System.out.println("Ставка: " + rate + ", Отработано часов: " + hours + ", З/п за месяц: " + salary);
    }

    private void setSalary() {
        salary = rate * hours;
    }

    public int getSalary() {
        return salary;
    }

    public void setRate(int rate) {
        this.rate = rate;
        setSalary();
    }

    public int getRate() {
        return rate;
    }

    public void setHours(int hours) {
        this.hours = hours;
        setSalary();
    }

    public int getHours() {
        return hours;
    }
}
