// Hello ashlok keep going....
#include <iostream>
using namespace std;

struct Process
{
    int id;
    int burstTime;
    int arrivalTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(Process processes[], int n, int timeQuantum)
{
    int remainingTime[n];
    // Storing the original burst time for final usage
    for (int i = 0; i < n; ++i)
        remainingTime[i] = processes[i].burstTime;

    int currentTime = 0;
    bool isCompleted = false; // while all processes are completed tracking variable

    while (!isCompleted)
    {
        isCompleted = true;
        for (int i = 0; i < n; ++i)
        {
            if (remainingTime[i] > 0)
            {
                isCompleted = false;
                if (remainingTime[i] > timeQuantum)
                {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
                else
                {
                    currentTime += remainingTime[i];
                    remainingTime[i] = 0;
                    processes[i].completionTime = currentTime;
                }
            }
        }
    }
}

void calculateTurnAroundTime(Process processes[], int n)
{
    for (int i = 0; i < n; ++i)
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
}

void calculateWaitingTime(Process processes[], int n)
{
    for (int i = 0; i < n; ++i)
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
}

void printTable(Process processes[], int n)
{
    cout << "Processes: ";
    for (int i = 0; i < n; ++i)
        cout << processes[i].id << " ";
    cout << '\n';
    cout << "Arrival Time: ";
    for (int i = 0; i < n; ++i)
        cout << processes[i].arrivalTime << " ";
    cout << '\n';
    cout << "Burst Time: ";
    for (int i = 0; i < n; ++i)
        cout << processes[i].burstTime << " ";
    cout << '\n';
    cout << "Completion Time: ";
    for (int i = 0; i < n; ++i)
        cout << processes[i].completionTime << " ";
    cout << '\n';
    cout << "Turn Around Time: ";
    for (int i = 0; i < n; ++i)
        cout << processes[i].turnaroundTime << " ";
    cout << '\n';
    cout << "Waiting Time: ";
    for (int i = 0; i < n; ++i)
        cout << processes[i].waitingTime << " ";
    cout << '\n';
}

int main()
{
    int n, timeQuantum;
    cout << "Enter No. of Processes and Time Quantum: ";
    cin >> n >> timeQuantum;

    Process processes[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Process " << (i + 1) << " \n";
        processes[i].id = i + 1;
        cout << "Enter Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Enter Burst Time: ";
        cin >> processes[i].burstTime;
    }

    calculateTimes(processes, n, timeQuantum);
    calculateTurnAroundTime(processes, n);
    calculateWaitingTime(processes, n);

    cout << "Round Robin Results: \n";
    printTable(processes, n);
    return 0;
}

/*
1. Implementing FCFS scheduling algorithm in Java
2. Implementing SJF (with no premtion) scheduling alogithm
3. Implementing RR Scheduling Algorithm in Java
4. Write a Java program that implements banker's alogithm
5. Write a Java program that impolements FIFO page replacement algorithm
6. Write a Java Program that implements LRU Page replacement algorithm
7. Design a File System in Java
8. Process Commmunication
    1. Implement the producer - consumer problem using shared memory
    2. Implement the producer - consumer problem using message passing
    3. One form of communiaction in a client - server systems environment in Remote Method invocation
9. Threads
    1.
    2.
10. Synchronization
    1. Implementing Bounded buffer problem in Java
    2. Implementing the reader - writers using Java synchronisation
    3. The sleeping barber problem
*/