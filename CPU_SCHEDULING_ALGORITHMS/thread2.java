import java.util.Scanner;
/*  Printimg Prime Number using Thread Programming   */
class PrimeNumber implements Runnable {
    private int n;

    public PrimeNumber(int n) {
        this.n = n;
    }

    public boolean isPrime(int a) {
        if (a <= 1)
            return false;

        for (int i = 2; i < a; ++i) {
            if (a % i == 0)
                return false;
        }
        return true;
    }

    @Override
    public void run() {
        System.out.print("Printing Prime Number: ");
        for (int i = 1; i < n; ++i) {
            if (isPrime(i))
                System.out.print(i + " ");

        }
        System.out.println();
    }
}

public class thread2 {
    public static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        PrimeNumber p = new PrimeNumber(n);

        Thread exe = new Thread(p);
        exe.start();
    }
}
