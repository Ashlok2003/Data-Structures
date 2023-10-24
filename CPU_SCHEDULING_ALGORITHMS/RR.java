package Practice;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RR {
    public static class Process {
        int process;
        int burst;
        int arrival;
        int complete;
        int waiting;
        int turnaroundTime;

        public Process(int process, int arrival, int burst) {
            this.process = process;
            this.burst = burst;
            this.arrival = arrival;
            this.complete = 0;
            this.waiting = 0;
            this.turnaroundTime = 0;
        }

        @Override
        public String toString() {
            return "Process: " + process + " Arrival: " + arrival + " Burst: " + burst + " Completion Time: " + complete
                    +
                    " Waiting: " + waiting + " Turn Around Time: " + turnaroundTime;
        }
    }

    public static void run(List<Process> x, int timeQuantum) {
        int n = x.size();
        int[] remainingTime = new int[n];

        for (int i = 0; i < n; ++i) {
            remainingTime[i] = x.get(i).burst;
        }

        int currentTime = 0;

        while (true) {
            boolean allCompleted = true;

            for (int i = 0; i < n; ++i) {
                if (remainingTime[i] > 0) {
                    allCompleted = false;

                    if (remainingTime[i] > timeQuantum) {
                        currentTime += timeQuantum;
                        remainingTime[i] -= timeQuantum;
                    } else {
                        currentTime += remainingTime[i];
                        remainingTime[i] = 0;
                        x.get(i).complete = currentTime;
                    }
                }
            }

            if (allCompleted) {
                break;
            }
        }

        for (Process a : x) {
            a.turnaroundTime = a.complete - a.arrival;
            a.waiting = a.turnaroundTime - a.burst;
        }
    }

    public static void main(String[] args) {
        List<Process> x = new ArrayList<>();
        x.add(new Process(1, 0, 8));
        x.add(new Process(2, 5, 2));
        x.add(new Process(3, 1, 7));
        x.add(new Process(4, 6, 3));
        x.add(new Process(5, 8, 5));

        Collections.sort(x, (a, b) -> a.arrival - b.arrival);

        run(x, 3);

        for (Process a : x) {
            System.out.println(a.toString());
        }
    }
}
