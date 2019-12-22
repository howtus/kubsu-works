import java.util.EmptyStackException;

public class Stack {

    private int[] stack;
    private int top;
    private final int MAX;

    // Конструктор
    public Stack(int MAX) {
        this.MAX = MAX;
        this.top = 0;
        stack = new int[MAX];
    }

    // Деструктор
    public void close() {
        for (int i: stack) i = 0;
        top = 0;
    }

    // Положить число в стек
    public boolean add(int element) throws StackOverflowError {
        if (this.isFull()) throw new StackOverflowError();
        stack[top] = element;
        top++;
        return true;
    }

    // Удалить число из стека
    public boolean remove() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        top--;
        stack[top] = 0;
        return true;
    }

    // Взять число из стека
    public int get() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        top--;
        return stack[top];
    }

    // Проверить на переполненность
    public boolean isFull() {
        return (top == MAX);
    }

    // Проверить на пустоту
    public boolean isEmpty() {
        return (top == 0);
    }

    // Узнать элементов в стеке
    public int size() {
        return top;
    }

    // Получить максимальный элемент стека
    public int max() {
        int max = stack[0];
        for (int i: stack) {
            if (i > max) {
                max = i;
            }
        }
        return max;
    }

    // Получить минимальный элемент стека
    public int min() {
        int min = stack[0];
        for (int i: stack) {
            if (i < min) {
                min = i;
            }
        }
        return min;
    }


    // @TODO Заменить средний элемент нулем

    // Скрытый метод для проверки корректной работы стека
    public void _debug() {
        System.out.println("Top = " + top + " MAX = " + MAX + " Empty = " + this.isEmpty() + " Full = " + this.isFull());
        System.out.println("Min = " + this.min() + " Max = " + this.max());
        for (int i: stack) System.out.print(i + " ");
        System.out.print("\n");
    }
}
