package Workers;

public class InterestRateEmployee extends Worker implements WorkerInterface {

    private int salesAmount;
    private double percent, salary;

    public InterestRateEmployee(String firstName, String secondName, int age, String position, double percent, int salesAmount) {
        super(firstName, secondName, age, position);
        this.percent = percent;
        this.salesAmount = salesAmount;
        setSalary();
    }

    @Override
    public void show() {
        super.show();
        System.out.println("Процентная ставка: " + percent + ", Общая сумма продаж: " + salesAmount + ", З/п за месяц: " + (int)salary);
    }

    public void setSalary() {
        salary = (double)(percent * salesAmount);
    }

    public int getSalary() {
        return (int)salary;
    }

    public void setPercent(double percent) {
        this.percent = percent;
        setSalary();
    }

    public double getPercent() {
        return percent;
    }

    public void setSalesAmount(int salesAmount) {
        this.salesAmount = salesAmount;
        setSalary();
    }

    public int getSalesAmount() {
        return salesAmount;
    }
}