package Workers;

public class Worker {

    private String firstName, secondName, position;
    private int age;

    public Worker(String firstName, String secondName, int age, String position) {
        this.firstName = firstName;
        this.secondName = secondName;
        this.position = position;
        this.age = age;
    }

    public void show() {
        System.out.println(firstName + " " + secondName + ", " + age + ". Должность: " + position);
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setSecondName(String secondName) {
        this.secondName = secondName;
    }

    public String getSecondName() {
        return secondName;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public String getPosition() {
        return position;
    }
}
