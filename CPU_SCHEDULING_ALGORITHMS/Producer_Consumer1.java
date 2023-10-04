import java.util.concurrent.Semaphore;
import java.util.*;

class SharedBuffer {
    private final int capacity;
    private final Semaphore mutex;
    private final Semaphore empty;
    private final Semaphore full;
    private final Queue<Integer> buffer;

    public SharedBuffer(int capacity) {
        this.capacity = capacity;
        this.buffer = new LinkedList<>();
        this.mutex = new Semaphore(1); // Mutex for buffer access
        this.empty = new Semaphore(this.capacity); // semaphore for empty slots in the buffer
        this.full = new Semaphore(0); // semaphore for filled slots in the buffer
    }

    public void produce(int item) throws InterruptedException {
        empty.acquire(); // Wait for an empty slot
        mutex.acquire(); // Get Exclusive access to the buffer
        buffer.offer(item); // Add item to the buffer
        System.out.println("Producer produces : " + item);
        mutex.release();
        full.release(); // Signal that the buffer is now not empty
    }

    public int consume() throws InterruptedException {
        full.acquire(); // wait for a filled slot
        mutex.acquire(); // Get exclusive access to the buffer
        int item = buffer.poll();
        System.out.println("Consumer consumes: " + item);
        mutex.release();
        empty.release(); // Signal that the buffer is now not full
        return item;
    }

}

class Producer implements Runnable {
    private SharedBuffer buffer;

    public Producer(SharedBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; ++i) {
                buffer.produce(i);
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private SharedBuffer buffer;

    public Consumer(SharedBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; ++i) {
                System.out.println("Consumer: " + buffer.consume());
                Thread.sleep(200);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Producer_Consumer1 {
    // Producer consumer using the shared memeory
    public static void main(String[] args) {
        SharedBuffer buffer = new SharedBuffer(5); // Shared buffer with a capacity of 5

        Thread producerThread1 = new Thread(new Producer(buffer));
        Thread producerThread2 = new Thread(new Producer(buffer));
        Thread consumerThread1 = new Thread(new Consumer(buffer));
        Thread consumerThread2 = new Thread(new Consumer(buffer));

        producerThread1.start();
        producerThread2.start();
        consumerThread1.start();
        consumerThread2.start();
    }
}
