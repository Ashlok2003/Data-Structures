import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
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

    @Override
    public String toString() {
        return process + " " + arrival + " " + burst;
    }
}

public class FCFS {

    public static void run(List<Process> x) {
        Collections.sort(x, Comparator.comparingInt(p -> p.arrival));
        int[] ct = new int[x.size()];
        int[] tat = new int[x.size()];
        int[] wt = new int[x.size()];

        int counter = 0;
        for (Process a : x) {
            if (a.arrival > counter) {
                counter = a.arrival; // If the process arrives after the previous one completes
            }
            counter += a.burst;
            ct[a.process] = counter;
            tat[a.process] = ct[a.process] - a.arrival;
            wt[a.process] = tat[a.process] - a.burst; 
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
            System.out.print(wt[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        List<Process> processes = new ArrayList<>();
        processes.add(new Process(0, 6, 5));
        processes.add(new Process(1, 1, 3));
        processes.add(new Process(2, 2, 8));
        processes.add(new Process(3, 3, 6));
        run(processes);
    }
}