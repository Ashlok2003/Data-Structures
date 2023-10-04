import java.util.Scanner;
/* Summition of First n non-neagative numbers using Thread Programming. */
class Summition implements Runnable {
    private int n;
    private long sum;

    public Summition(int n) {
        this.n = n;
    }

    @Override
    public void run() {
        this.sum = 0;
        for (int i = 1; i <= this.n; ++i) {
            this.sum += i;
        }
        System.out.println("Summition of First n non -negative: " + sum);
    }

    public Long getSum() {
        return this.sum;
    }
}

public class thread1 {
    public final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();

        Summition s = new Summition(n);
        Thread thread = new Thread(s);

        thread.start();
        /* System.out.println(s.getSum()); */
    }
}
