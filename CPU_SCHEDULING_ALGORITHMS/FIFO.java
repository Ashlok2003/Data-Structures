import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class FIFO {
    public final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter Number of Frames: ");
        int n = sc.nextInt();
        System.out.println("Enter Number of Pages: ");
        int r = sc.nextInt();

        int[] pages = new int[r];
        System.out.println("Enter The Respective Pages: ");
        for (int i = 0; i < r; ++i)
            pages[i] = sc.nextInt();
                                       
        int page_fault = 0;
        int page_hit = 0;

        Set<Integer> s = new HashSet<>();
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < r; ++i) {
            if (!s.contains(pages[i])) {

                if (s.size() >= n) {
                    // Removing the First Page from the Frame Queues .... :)
                    int victimPage = q.poll();
                    s.remove(victimPage);
                }
                q.offer(pages[i]);
                s.add(pages[i]);
                page_fault++;

            } else {
                // If the page is aalready present inside the queue.... :)
                page_hit++;
            }

            /* System.out.println(s.toString()); */
        }
        System.out.println("\nTotal Page Faults: " + page_fault);
        System.out.println("Total Page Hits: " + page_hit);
    }
}
