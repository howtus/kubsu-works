import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.List;

import static org.junit.Assert.*;

public class StackTest {

    @Test
    public void close() {
    }

    @Test
    public void add() {
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
        // @TODO сделать тест с исключением для max
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
}