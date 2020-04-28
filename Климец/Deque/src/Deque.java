import java.util.EmptyStackException;

public class Deque extends Stack {

    private int bottom;

    // Конструктор
    // Заполняю поля и выделяю память под массив
    public Deque(int MAX) {
        super(MAX);
        this.bottom = -1;
    }

    // Конструктор 2
    // Для удобства с параметром массива чисел
    public Deque(int[] array) {
        super(array);
        this.bottom = -1;
    }

    // Конструктор 3
    // Для удобства с параметром массива чисел и максимумом
    public Deque(int[] array, int MAX) {
        super(array, MAX);
        this.bottom = -1;
    }

    // Положить число в дэк снизу
    // Выкидываю исключение, если дэк переполнен
    public boolean addBottom(int element) throws StackOverflowError {
        if (this.isFull()) throw new StackOverflowError();
        stack[bottom] = element;
        bottom--;
        return true;
    }

    // Удалить число из дэка снизу
    // Данный метод просто удаляет верхний элемент, но не возвращает его
    // Выкидываю исключение, если дэк пуст
    public boolean removeBottom() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        bottom++;
        stack[bottom] = 0;
        return true;
    }

    // Взять число из дэка снизу
    // Данный метод возвращает нижний элемент дэка и убирает его
    // Выкидываю исключение, если дэк пуст
    public int getBottom() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        bottom++;
        int temp = stack[bottom];
        stack[bottom] = 0;
        return temp;
    }

    // Проверить на переполненность
    public boolean isFull() {
        return (top == MAX) && (bottom == -1);
    }

    // Проверить на пустоту
    public boolean isEmpty() {
        return (top == 0) && (bottom == -1);
    }

    // Узнать количество элементов в дэке
    public int size() {
        return (top - bottom - 1);
    }

    // Получить максимальный элемент дэка
    // Если дэк пуст, выкидываю исключение
    public int max() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        int max = stack[bottom + 1];
        for (int i = bottom + 1; i < top; i++) {
            if (stack[i] > max) {
                max = stack[i];
            }
        }
        return max;
    }

    // Получить минимальный элемент дэка
    // Если дэк пуст, выкидываю исключение
    public int min() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        int min = stack[bottom + 1];
        for (int i = bottom + 1; i < top; i++) {
            if (stack[i] < min) {
                min = stack[i];
            }
        }
        return min;
    }

    // Заменить средний элемент нулем
    // Если в дэке всего 1 или 2 элемента, то заменять нечего
    // Поэтому просто не меняю элемент
    public void replaceMiddle() {
        if (this.size() >= 3) {
            int index = this.size() / 2;
            stack[top - index - 1] = 0;
        }
    }

    // Инвертировать дэк
    // Если пустой, просто завершаем метод
    public void invert() {
        if (this.isEmpty()) return;
        for (int i = bottom + 1; i < top / 2; i++) {
            int temp = stack[i];
            stack[i] = stack[top - 1 - i];
            stack[top - 1 - i] = temp;
        }
    }

    // Скрытый метод для проверки корректной работы дэка
    // Просто выводит всю инфу об объекте
    public void debug() {
        System.out.println("=======================");
        System.out.println("Top = " + top + " Bottom = " + bottom + " MAX = " + MAX + " Empty = " + this.isEmpty() + " Full = " + this.isFull());
        System.out.println("Min = " + this.min() + " Max = " + this.max());
        for (int i: stack) System.out.print(i + " ");
        System.out.print("\n");
        System.out.println("=======================");
    }

}
