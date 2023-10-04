import java.util.Arrays;

public class Bankers {
    public static void main(String[] args) {
        int n = 5; // No. of processes
        int r = 3; // No. of resources

        int[][] allocation = new int[][] {
                { 0, 0, 1 },
                { 3, 0, 0 },
                { 1, 0, 1 },
                { 2, 3, 2 },
                { 0, 0, 3 }
        };
        int[][] max_allocation = new int[][] {
                { 7, 6, 3 },
                { 3, 2, 2 },
                { 8, 0, 2 },
                { 2, 1, 2 },
                { 5, 2, 3 }
        };

        int[] avail = new int[] { 2, 3, 2 };
        int[][] need = new int[n][r];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < r; ++j)
                need[i][j] = max_allocation[i][j] - allocation[i][j];

        int index = 0;
        int[] f = new int[n];
        int[] ans = new int[n];
        Arrays.fill(f, 0);

        for (int k = 0; k < 5; ++k) {
            for (int i = 0; i < n; ++i) {
                if (f[i] == 0) {
                    int flag = 0;

                    for (int j = 0; j < r; ++j) {
                        if (need[i][j] > avail[j]) {
                            // If available is less than the required, then simply break it.
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0) {
                        // If available is less than or equal to required, we can go with the sequence
                        ans[index++] = i;
                        for (int a = 0; a < r; ++a) {
                            avail[a] += allocation[i][a];
                        }
                        f[i] = 1; // Mark the process as finished
                    }
                }
            }
        }

        System.out.println("The Safe Sequence is : ");
        for (int i = 0; i < n - 1; ++i)
            System.out.print(ans[i] + " -> ");

        // Print the last element without " -> "
        System.out.println(ans[n - 1]);
    }
}
