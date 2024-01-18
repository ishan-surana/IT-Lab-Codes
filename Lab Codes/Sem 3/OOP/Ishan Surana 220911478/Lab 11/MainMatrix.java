class Matrix
{
    int[][] matrix;
    int rows;
    int cols;
    static int a=1;
    Matrix(int rows, int cols)
    {
        this.rows=rows;
        this.cols=cols;
        matrix=new int[rows][cols];
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++) matrix[i][j]=a++;
            System.out.println();
        }
    }

    void displayMatrix()
    {
        System.out.println("Matrix in standard form:");
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++) System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
    }

    void displayTranspose()
    {
        System.out.println("Transpose form:");
        for (int i=0;i<cols;i++)
        {
            for(int j=0;j<rows;j++) System.out.print(matrix[j][i] + " ");
            System.out.println();
        }

    }

    void displayMaxValue()
    {
        int maxVal = matrix[0][0];
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                if (matrix[i][j]>maxVal)
                    maxVal = matrix[i][j];
        }
        System.out.println("Maximum value: " + maxVal);
    }

    void displayPrincipalDiagonal()
    {
        if(rows!=cols) System.out.println("Keep rows and columns same!");
        else
        {
        System.out.println("Principal diagonal: ");
        for (int i=0;i<rows; i++) System.out.print(matrix[i][i] + " ");
        System.out.println();
        }
    }

    void displayNonDiagonal()
    {
        System.out.println("Non-diagonal elements:");
        for (int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        if(i!=j)
        System.out.print(matrix[i][j] + " ");
        System.out.println();
    }
}

class MyThread extends Thread
{
    Matrix matrix;
    int task;

    MyThread(Matrix matrix, int task)
    {
        this.matrix = matrix;
        this.task = task;
    }

    public void run()
    {
        switch(task)
        {
            case 1:
                matrix.displayMatrix();
                break;
            case 2:
                matrix.displayTranspose();
                break;
            case 3:
                matrix.displayMaxValue();
                break;
            case 4:
                matrix.displayPrincipalDiagonal();
                break;
            case 5:
                matrix.displayNonDiagonal();
                break;
            default:
                System.out.println("Invalid task number");
                break;
        }
    }
}

class MainMatrix {
    public static void main(String[] args) throws InterruptedException {
        Matrix matrix = new Matrix(3, 3);

        MyThread t1 = new MyThread(matrix, 1);
        MyThread t2 = new MyThread(matrix, 2);
        MyThread t3 = new MyThread(matrix, 3);
        MyThread t4 = new MyThread(matrix, 4);
        MyThread t5 = new MyThread(matrix, 5);
        System.out.println("t1 is alive: " + t1.isAlive());
	    System.out.println("t2 is alive: " + t2.isAlive());
	    System.out.println("t3 is alive: " + t3.isAlive());
	    System.out.println("t4 is alive: " + t4.isAlive());
	    System.out.println("t5 is alive: " + t5.isAlive());
        t1.start();
        t1.join();
        t2.start();
        t2.join();
        t3.start();
        t3.join();
        t4.start();
        t4.join();
        t5.start();
        t5.join();
        System.out.println("t1 is alive: " + t1.isAlive());
	    System.out.println("t2 is alive: " + t2.isAlive());
	    System.out.println("t3 is alive: " + t3.isAlive());
	    System.out.println("t4 is alive: " + t4.isAlive());
	    System.out.println("t5 is alive: " + t5.isAlive());
    }
}
