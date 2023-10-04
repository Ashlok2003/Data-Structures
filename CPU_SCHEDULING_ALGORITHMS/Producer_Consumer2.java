import java.util.LinkedList;
import java.util.Queue;

class SharedBuffer {
    private final int capacity;
    private final Queue<String> buffer;

    public SharedBuffer(int capacity) {
        this.capacity = capacity;
        this.buffer = new LinkedList<>();
    }

    public synchronized void produce() throws InterruptedException {
        while (buffer.size() == capacity) {
            wait(); // Since the buffer is full, we will stop producing;
        }
        String message = new java.util.Date().toString();
        buffer.offer(message);
        System.out.println("Producing: " + message);
        notify();
    }

    public synchronized String consume() throws InterruptedException {
        while (buffer.size() == 0) {
            wait(); // Let the producer produce the item since the buffer is empty
        }
        String message = buffer.poll();
        System.out.println("Consuming: " + message);
        notify();
        return message;
    }
}

class Producer implements Runnable {
    private SharedBuffer buffer;
    private volatile boolean running = true;

    public Producer(SharedBuffer buffer) {
        this.buffer = buffer;
    }

    public void stop() {
        running = false;
    }

    @Override
    public void run() {
        try {
            while (running) {
                buffer.produce();
                Thread.sleep(100);
            }
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private SharedBuffer buffer;
    private volatile boolean running = true;

    public Consumer(SharedBuffer buffer) {
        this.buffer = buffer;
    }

    public void stop() {
        running = false;
    }

    @Override
    public void run() {
        try {
            while (running) {
                String message = buffer.consume();
                System.out.println("Got Message: " + message);
                Thread.sleep(200);
            }
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Producer_Consumer2 {
    // Producer Consumer using the message passing concept
    public static void main(String[] args) {
        SharedBuffer buffer = new SharedBuffer(5);

        Producer producer = new Producer(buffer);
        Consumer consumer = new Consumer(buffer);

        Thread producerThread = new Thread(producer);
        Thread consumerThread = new Thread(consumer);

        producerThread.start();
        consumerThread.start();

        // Let the threads run for some time
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        // Stop the producer and consumer threads gracefully
        producer.stop();
        consumer.stop();
    }
}
