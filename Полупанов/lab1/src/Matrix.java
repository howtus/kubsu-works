import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Matrix {

    // Поля
    private int rows, cols;
    private  ArrayList<ArrayList<Integer>> matrix;

    // Конструктор
    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;

        Scanner scan = new Scanner(System.in);

        matrix = new ArrayList<ArrayList<Integer>>(rows);
        for (int i = 0; i < rows; i++) {
            ArrayList<Integer> list = new ArrayList<Integer>(cols);
            for (int j = 0; j < cols; j++) {
                System.out.println("Введите " + (i+1) + "-ю строку, " + (j+1) + "-й столбец");
                list.add(scan.nextInt());
            }
            matrix.add(list);
        }
    }

    // Выводит в консоль всю матрицу
    public void show() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    // Выводит в консоль подматрицу от 0 столбца и 0 строки до указанных в параметрах
    public void show(int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    // Выводит в консоль матрицу от и до указанных столбцов и строк
    public void show(int rowStart, int rowEnd, int colStart, int colEnd) {
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                System.out.print(matrix.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    // Добавление строк в конец
    public void addRows(int rows) {
        for (int i = 0; i < rows; i++) {
            ArrayList<Integer> list = new ArrayList<Integer>(cols);
            for (int j = 0; j < cols; j++) {
                list.add(null);
            }
            matrix.add(list);
        }
        this.rows += rows;
    }

    // Добавление столбцов в конец
    public void addСols(int cols) {
        for (int i = 0; i < rows; i++) {
            ArrayList<Integer> list = matrix.get(i);
            for (int j = 0; j < cols; j++) {
                list.add(null);
            }
        }
        this.cols += cols;
    }

    // Получение количества столбцов
    public int getCols() {
        return cols;
    }

    // Получение количества строк
    public int getRows() {
        return rows;
    }
}