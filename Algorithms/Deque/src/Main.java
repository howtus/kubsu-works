public class Main {

    public static void main(String[] args) {

        // Масств чисел
        int[] array = {34,542,341,654,5756,643,-327,8432,19,1,113,-12,3213,4314,1545,216};
        // Используем третий конструктор, чтобы не париться
        Deque s3 = new Deque(array, 20);
        // После каждого своего действия я буду вызывать метод .debug()
        // Он позволит отслеживать изменение дэка
        // Некоторые методы не вызываю, потому что они и так вызываются в .debug()
        s3.debug();
        // Добавляем элемент 321 наверх дэка
        s3.add(321);
        s3.debug();
        // Удаляем элемент из дэка
        s3.remove();
        s3.debug();
        // Удаляем элемент из дэка снизу
        s3.removeBottom();
        s3.debug();
        // Добавляем элемент 444 внищ дэка
        s3.addBottom(444);
        s3.debug();
        // Берем элемент из дэка сверху
        int temp = s3.get();
        System.out.println("Проверка метода .get() = " + temp);
        s3.debug();
        // Берем элемент из дэка снизу
        temp = s3.getBottom();
        System.out.println("Проверка метода .getBottom() = " + temp);
        s3.debug();
        // Узнаем размер дэка
        temp = s3.size();
        System.out.println("Проверка метода .size() = " + temp);
        // Узнаем максимум дэка
        temp = s3.getMAX();
        System.out.println("Проверка метода .getMAX() = " + temp);
        // Инвертируем дэк
        s3.invert();
        s3.debug();
        // Деструктор
        s3.close();
    }
}