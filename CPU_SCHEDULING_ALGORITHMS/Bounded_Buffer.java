import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

class Producer implements Runnable {
    private final BlockingQueue<Integer> buffer;

    public Producer(BlockingQueue<Integer> buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 10; ++i) {
                System.out.println("Producing: " + i);
                buffer.put(i);
                Thread.sleep(100);
            }
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private final BlockingQueue<Integer> buffer;

    public Consumer(BlockingQueue<Integer> buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            while (true) {
                int data = buffer.take();
                System.out.println("Consuming: " + data);
                Thread.sleep(200);
            }
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Bounded_Buffer {
    public static void main(String[] args) {
        // Shared buffer with a capacity 5
        BlockingQueue<Integer> buffer = new ArrayBlockingQueue<>(5);

        Thread ProducerThread = new Thread(new Producer(buffer));
        Thread ConsumerThread = new Thread(new Consumer(buffer));

        ProducerThread.start();
        ConsumerThread.start();
    }
}
/*
 * Certainly! A `BlockingQueue` is a specialized data structure in Java that
 * provides thread-safe operations for adding and removing elements while
 * handling synchronization and blocking when necessary. It's often used in
 * multi-threaded applications to solve producer-consumer problems and
 * coordinate the work of multiple threads.
 * 
 * Here are some important characteristics of `BlockingQueue`:
 * 
 * 1. **Thread Safety:** `BlockingQueue` is designed to be thread-safe. Multiple
 * threads can safely access and modify the queue without external
 * synchronization.
 * 
 * 2. **Blocking Operations:** `BlockingQueue` provides blocking operations for
 * adding (`put`) and removing (`take`) elements. If a producer tries to add an
 * element to a full queue or a consumer tries to remove an element from an
 * empty queue, the thread will block until the condition is satisfied.
 * 
 * 3. **Capacity:** `BlockingQueue` can have a maximum capacity, which limits
 * the number of elements it can hold. This makes it suitable for scenarios like
 * bounded buffers in producer-consumer problems.
 * 
 * 4. **FIFO Order:** Elements are typically processed in a first-in, first-out
 * (FIFO) order.
 * 
 * Common Methods of `BlockingQueue`:
 * 
 * - `put(E e)`: Adds an element to the queue. If the queue is full, it will
 * block until space becomes available.
 * 
 * - `take()`: Removes and returns an element from the queue. If the queue is
 * empty, it will block until an element is available.
 * 
 * - `offer(E e)`: Adds an element to the queue if space is available. Returns
 * `true` if successful; otherwise, `false` (non-blocking).
 * 
 * - `poll()`: Removes and returns an element from the queue if one is
 * available. Returns `null` if the queue is empty (non-blocking).
 * 
 * - `size()`: Returns the number of elements in the queue.
 * 
 * Common Implementations of `BlockingQueue`:
 * 
 * - `ArrayBlockingQueue`: Backed by an array, has a fixed capacity.
 * 
 * - `LinkedBlockingQueue`: Backed by a linked list, can be unbounded or have an
 * optional capacity.
 * 
 * - `PriorityBlockingQueue`: Orders elements based on their natural order or a
 * specified comparator.
 * 
 * - `DelayQueue`: Holds elements until their specified delay time has passed.
 * 
 * Use Cases for `BlockingQueue`:
 * 
 * 1. **Producer-Consumer Problem:** As shown in the previous example,
 * `BlockingQueue` is commonly used to implement solutions to the
 * producer-consumer problem, where multiple producers produce data and multiple
 * consumers consume it concurrently.
 * 
 * 2. **Thread Pooling:** `BlockingQueue` can be used to manage tasks in a
 * thread pool, where worker threads consume tasks from the queue.
 * 
 * 3. **Event Handling:** In event-driven systems, `BlockingQueue` can be used
 * to handle and process events generated by different parts of the application.
 * 
 * 4. **Task Scheduling:** `BlockingQueue` can be used to schedule tasks for
 * execution at specific times or after certain delays.
 * 
 * `BlockingQueue` is a powerful concurrency tool that simplifies the
 * coordination of threads and helps prevent issues like resource contention and
 * race conditions in multi-threaded applications. It's a fundamental building
 * block for concurrent and parallel programming in Java.
 * 
 */