import java.util.concurrent.Semaphore;

class ReaderWriter {
    private int readers;
    private Semaphore mutex;
    private Semaphore rwLock;

    public ReaderWriter() {
        this.readers = 0;
        this.mutex = new Semaphore(1);
        this.rwLock = new Semaphore(1);
    }

    public void startReading(int readerId) throws InterruptedException {
        mutex.acquire(); // Acquiring the Lock to avoid writing while reading
        readers++;
        if (readers == 1) {
            rwLock.acquire();
        }
        mutex.release();

        System.out.println("Reader: " + readerId + " is reading!");

        // Again Acquiring the lock because there might be some reader is readig the
        // book
        mutex.acquire();

        readers--;
        if (readers == 0) {
            rwLock.release();
            // Since There is no reader is reading now then remove the Lock
        }
        // Releasing the lock now
        mutex.release();
    }

    public void startWriting(int writerId) throws InterruptedException {
        rwLock.acquire();
        System.out.println("Writer: " + writerId + " is Writing !");
        rwLock.release();
    }
}

class Reader implements Runnable {
    private ReaderWriter readerWriter;
    private int readerId;

    public Reader(ReaderWriter readerWriter, int readerId) {
        this.readerId = readerId;
        this.readerWriter = readerWriter;
    }

    @Override
    public void run() {
        try {
            while (true) {
                Thread.sleep(1000); // Simulating Reading work
                readerWriter.startReading(readerId);
            }
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}

class Writer implements Runnable {
    private ReaderWriter readerWriter;
    private int writerId;

    public Writer(ReaderWriter readerWriter, int writerId) {
        this.writerId = writerId;
        this.readerWriter = readerWriter;
    }

    @Override
    public void run() {
        try {
            while (true) {
                Thread.sleep(2000); // Simulating writing work
                readerWriter.startWriting(writerId);
            }
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Reader_Writer_Synchronisation {
    public static void main(String[] args){
        ReaderWriter readerWriter = new ReaderWriter();

        for(int i = 0; i < 3; ++i){
            Thread readerThread = new Thread(new Reader(readerWriter, i));
            readerThread.start();
        }
        for(int i = 0; i < 3; ++i){
            Thread writerThread = new Thread(new Writer(readerWriter, i));
            writerThread.start();
        }
    }
}
