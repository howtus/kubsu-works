import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.List;

import static org.junit.Assert.*;

public class StackTest {

    // Тест для метода добавление элемента на верхушку стека
    // Ожидаем что наверху стека число 110
    @Test
    public void add() {
        int[] array = {1,2,3};
        Stack stack = new Stack(array, 10);
        int expected = 110;
        stack.add(expected);
        int actual = stack.get();

        Assert.assertEquals(expected, actual);
    }

    // Тест для метода добавление элемента на верхушку стека
    // Ожидаем возвращение исключения
    @Test (expected = StackOverflowError.class)
    public void addWithException() throws StackOverflowError {
        int[] array = {1,2,3};
        Stack stack = new Stack(array);
        stack.add(100);
    }

    // Тест для метода удаления элемента с верхушки стека
    // Ожидаем возвращение true
    @Test
    public void remove() {
        Stack stack = new Stack( 10);
        stack.add(10);
        stack.add(11);
        stack.add(12);

        boolean expected = true;
        boolean actual = stack.remove();

        Assert.assertEquals(expected, actual);
    }

    // Тест для метода удаления элемента с верхушки стека
    // Ожидаем возвращение исключения
    @Test(expected = EmptyStackException.class)
    public void removeWithException() throws EmptyStackException {
        Stack stack = new Stack( 10);
        stack.remove();
    }

    // Тест для метода получения элемента с верхушки стека
    // Ожидаем получить число, которое положили последним
    @Test
    public void get() {
        Stack stack = new Stack( 10);
        stack.add(10);
        stack.add(11);
        stack.add(12);

        int expected = 12;
        int actual = stack.get();

        Assert.assertEquals(expected, actual);
    }

    // Тест для метода получения элемента с верхушки стека
    // Ожидаем возвращение исключения
    @Test(expected = EmptyStackException.class)
    public void getWithException() throws EmptyStackException {
        Stack stack = new Stack( 10);
        int temp = stack.get();
    }

    // Тест для метода получения максимального элемента
    // Ожидаем получить максимальный элемент = 110
    @Test
    public void max() {
        Stack stack = new Stack( 10);
        stack.add(10);
        stack.add(110);
        stack.add(12);

        int expected = 110;
        int actual = stack.max();

        Assert.assertEquals(expected, actual);
    }

    // Тест для метода получения максимального элемента
    // Ожидаем получить исключение
    @Test(expected = EmptyStackException.class)
    public void maxWithException() throws EmptyStackException {
        Stack stack = new Stack( 10);
        int temp = stack.max();
    }

    // Тест для метода получения минимального элемента
    // Ожидаем получить максимальный элемент = 110
    @Test
    public void min() {
        Stack stack = new Stack( 10);
        stack.add(10);
        stack.add(-110);
        stack.add(12);

        int expected = -110;
        int actual = stack.min();

        Assert.assertEquals(expected, actual);
    }

    // Тест для метода получения минимального элемента
    // Ожидаем получить исключение
    @Test(expected = EmptyStackException.class)
    public void minWithException() throws EmptyStackException {
        Stack stack = new Stack( 10);
        int temp = stack.min();
    }

    // Тест для метода замены среднего по индексу числа на 0 в стеке
    @Test
    public void replaceMiddle() {
        Stack stack = new Stack( 10);
        stack.add(10);
        stack.add(-110);
        stack.add(12);

        stack.replaceMiddle();
        int expected = stack.get();
        expected = stack.get();
        int actual = 0;

        Assert.assertEquals(expected, actual);
    }

    // Тест для метода инвертирования стека
    @Test
    public void invert() {
        int[] arr = {1,2,3,4,5};
        Stack stack = new Stack(arr);

        stack.invert();
        int expected = 1;
        int actual = stack.get();

        Assert.assertEquals(expected, actual);
    }
}