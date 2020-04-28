import java.util.EmptyStackException;

public class Stack {

    protected int[] stack;
    protected int top;
    protected final int MAX;

    // Конструктор
    // Заполняю поля и выделяю память под массив
    public Stack(int MAX) {
        this.MAX = MAX;
        this.top = 0;
        stack = new int[MAX];
    }

    // Конструктор 2
    // Для удобства с параметром массива чисел
    public Stack(int[] array) {
        this.MAX = array.length;
        this.top = array.length;
        this.stack = array;
    }

    // Конструктор 3
    // Для удобства с параметром массива чисел и максимумом
    public Stack(int[] array, int MAX) {
        this.MAX = MAX;
        this.top = MAX < array.length ? MAX : array.length;
        this.stack = new int[MAX];
        for (int i = 0; i < this.top; i++) {
            this.stack[i] = array[i];
        }
    }

    // Деструктор
    // По сути в Java нет деструктора, но т.к. в задании его нужно сделать
    // Хоть в каком-нибудь виде, то просто очищаю стек
    public void close() {
        for (int i = 0; i < MAX; i++)
            stack[i] = 0;
        top = 0;
    }

    // Положить число в стек
    // Выкидываю исключение, если стек переполнен
    public boolean add(int element) throws StackOverflowError {
        if (this.isFull()) throw new StackOverflowError();
        stack[top] = element;
        top++;
        return true;
    }

    // Удалить число из стека
    // Данный метод просто удаляет верхний элемент, но не возвращает его
    // Выкидываю исключение, если стек пуст
    public boolean remove() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        top--;
        stack[top] = 0;
        return true;
    }

    // Взять число из стека
    // Данный метод возвращает верхний элемент стека и убирает его
    // Выкидываю исключение, если стек пуст
    public int get() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        top--;
        int temp = stack[top];
        stack[top] = 0;
        return temp;
    }

    // Проверить на переполненность
    public boolean isFull() {
        return (top == MAX);
    }

    // Проверить на пустоту
    public boolean isEmpty() {
        return (top == 0);
    }

    // Узнать количество элементов в стеке
    public int size() {
        return top;
    }

    // Узнать максимум элементов в стеке
    public int getMAX() {
        return MAX;
    }

    // Получить максимальный элемент стека
    // Если стек пуст, выкидываю исключение
    public int max() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        int max = stack[0];
        for (int i: stack) {
            if (i > max) {
                max = i;
            }
        }
        return max;
    }

    // Получить минимальный элемент стека
    // Если стек пуст, выкидываю исключение
    public int min() throws EmptyStackException {
        if (this.isEmpty()) throw new EmptyStackException();
        int min = stack[0];
        for (int i: stack) {
            if (i < min) {
                min = i;
            }
        }
        return min;
    }

    // Заменить средний элемент нулем
    // Если в стеке всего 1 или 2 элемента, то заменять нечего
    // Поэтому просто не меняю элемент
    public void replaceMiddle() {
        if (top >= 3) stack[top / 2] = 0;
    }

    // Инвертировать стек
    // Если пустой, просто завершаем метод
    public void invert() {
        if (this.isEmpty()) return;
        for (int i = 0; i < top / 2; i++) {
            int temp = stack[i];
            stack[i] = stack[top - 1 - i];
            stack[top - 1 - i] = temp;
        }
    }

    // Скрытый метод для проверки корректной работы стека
    // Просто выводит всю инфу об объекте
    public void debug() {
        System.out.println("=======================");
        System.out.println("Top = " + top + " MAX = " + MAX + " Empty = " + this.isEmpty() + " Full = " + this.isFull());
        System.out.println("Min = " + this.min() + " Max = " + this.max());
        for (int i: stack) System.out.print(i + " ");
        System.out.print("\n");
        System.out.println("=======================");
    }
}