import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Process {
    public int process;
    public int arrival;
    public int burst;

    public Process(int process, int arrival, int burst) {
        this.process = process;
        this.arrival = arrival;
        this.burst = burst;
    }
}

public class SJF {
    public static void run(List<Process> x) {
        Collections.sort(x, (a, b) -> a.burst - b.burst);
        /* Collections.sort(x, Comparator.comparingInt(a -> a.burst)); */

        int[] ct = new int[x.size()];
        int[] tat = new int[x.size()];
        int[] wat = new int[x.size()];

        int counter = x.get(0).arrival; // Initialize counter with the arrival time of the first process
        for (Process a : x) {
            System.out.println(a.toString());
            if (counter < a.arrival)
                counter = a.arrival;

            counter += a.burst;
            ct[a.process] = counter;
            tat[a.process] = ct[a.process] - a.arrival;
            wat[a.process] = tat[a.process] - a.burst;
        }

        System.out.println("Completion Time:");
        for (int i = 0; i < x.size(); i++) {
            System.out.print(ct[i] + " ");
        }
        System.out.println();

        System.out.println("Turn Around Time:");
        for (int i = 0; i < x.size(); i++) {
            System.out.print(tat[i] + " ");
        }
        System.out.println();

        System.out.println("Waiting Time:");
        for (int i = 0; i < x.size(); i++) {
            System.out.print(wat[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        List<Process> processes = new ArrayList<>();
        processes.add(new Process(0, 0, 6));
        processes.add(new Process(1, 1, 3));
        processes.add(new Process(2, 2, 8));
        processes.add(new Process(3, 3, 6));

        run(processes);
    }
}
