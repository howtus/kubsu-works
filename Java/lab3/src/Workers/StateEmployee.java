package Workers;

public class StateEmployee extends Worker implements WorkerInterface {

    private int salary, premium;

    public StateEmployee(String firstName, String secondName, int age, String position, int salary) {
        super(firstName, secondName, age, position);
        this.salary = salary;
        this.premium = 0;
    }

    public StateEmployee(String firstName, String secondName, int age, String position, int salary, int premium) {
        super(firstName, secondName, age, position);
        this.salary = salary;
        this.setPremium(premium);
    }


    @Override
    public void show() {
        super.show();
        System.out.println("Премия: " + premium + ", З/п за месяц: " + salary);
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public int getSalary() {
        return salary;
    }

    public void setPremium(int premium) {
        this.premium = premium;
        this.setSalary(this.getSalary() + premium);
    }

    public int getPremium() {
        return premium;
    }
}