public class Main {

    public static void main(String[] args) {

        Matrix m = new Matrix(2, 2);
        m.show();
        System.out.print("================\n");
        m.show(3, 2);
        System.out.print("================\n");
        m.show(1, 2, 1, 3);
        System.out.print("========2========\n");
        m.addRows(2);
        m.show();
        System.out.print(m.getRows());
        System.out.print("========3========\n");
        m.addСols(2);
        m.show();
        System.out.print(m.getCols());

    }
}
