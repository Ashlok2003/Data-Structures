import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class LRU {
    public final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter no. of Frames: ");
        int n = sc.nextInt();
        System.out.println("Enter no. of Pages: ");
        int r = sc.nextInt();

        int[] pages = new int[r];
        System.out.println("Enter the Respective Pages:");
        for (int i = 0; i < r; ++i)
            pages[i] = sc.nextInt();

        List<Integer> arr = new LinkedList<>();

        int page_fault = 0;
        int page_hits = 0;


        for (int page : pages) {
            // If the page is inside the frameset
            if (arr.contains(page)) {
                // Page hit: Move the Page to the Most recently used paosition i.e at the end of
                // arr
                arr.remove(Integer.valueOf(page));
                arr.add(page);
                page_hits++;
            }
            // If the pages is not inside the frames array
            else {
                if (arr.size() >= n) {
                    arr.remove(0);
                }
                arr.add(page);
                page_fault++;
            }
        }
        System.out.println("Total Page Faults: " + page_fault);
        System.out.println("Total Page Hits: " + page_hits);
    }
}
