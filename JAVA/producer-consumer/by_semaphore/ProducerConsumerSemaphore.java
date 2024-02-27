import com.sun.source.tree.WhileLoopTree;
import com.sun.tools.javac.Main;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.Semaphore;

public class ProducerConsumerSemaphore {
    static int LIMIT = 500;
    static int N = 50;
    static int id = 0;
    static File record = new File("record_prod_and_cons_sema.txt");
    static OutputStream fileOut;
    static Semaphore empty = new Semaphore(N);
    static Semaphore full = new Semaphore(0);
    static Semaphore mutex = new Semaphore(1);//control visits to critic region
    static int[] buffer = new int[N];
    static int left = 0, hole = 0;
    static Thread prod = new Producer();
    static Thread cons = new Consumer();

    static {
        try {
            fileOut = new FileOutputStream(record);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException {
        System.out.println("Successfully open a record. Now they are producing and consuming...");
        prod.start();
        cons.start();
        while (true) {
            if (prod.getState() == Thread.State.TERMINATED && cons.getState() == Thread.State.TERMINATED) {
                System.out.println("Threads of producing and consuming have terminated, and the record is closed.");
                fileOut.close();

                break;
            }
        }
    }

    static class Producer extends Thread {
        @Override
        public void run() {
            int item = 0;
            while (id < LIMIT) {
                //produceItem
                try {
                    item = produceItem();
                } catch (InterruptedException | IOException e) {
                    e.printStackTrace();
                }

                //empty.acquire
                try {
                    empty.acquire();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                //mutex.acquire
                try {
                    mutex.acquire();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

///////////////////////////////////////////////trans...
//                //mutex.acquire
//                try {
//                    mutex.acquire();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                //empty.acquire
//                try {
//                    empty.acquire();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }

//                -------------------------------
                insertItem(item);
//                -------------------------------

                mutex.release();

                full.release();
//                ///////////////////////trans...
//                full.release();
//
//                mutex.release();
            }
        }

        //produce
        public int produceItem() throws InterruptedException, IOException {
            //return the ID of item
            int randTime = (int) (Math.random() * 10);
            sleep(randTime);//spending 0 - 10 ms (random)
            var time = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS").format(new Date());
            fileOut.write(("producing NO." + id + " item at " + time + '\n').getBytes());
//            System.out.println("producing NO." + id + " item at " + time + '\n');

            return id++;
        }

        //insert
        public void insertItem(int item) {
            buffer[hole] = item;
            hole = (hole + 1) % N;
        }

    }

    static class Consumer extends Thread {
        @Override
        public void run() {
            int item;
            while (true) {
                //full.acquire
                try {
                    full.acquire();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                //mutex.acquire
                try {
                    mutex.acquire();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
//                /////////////////////trans...
//                //mutex.acquire
//                try {
//                    mutex.acquire();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                //full.acquire
//                try {
//                    full.acquire();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }


//                -------------------------------
                item = removeItem();
//                -------------------------------

                mutex.release();

                empty.release();

//              ///////////trans...
//                empty.release();
//                mutex.release();


                //consumeItem
                try {
                    consumeItem(item);
                } catch (InterruptedException | IOException e) {
                    e.printStackTrace();
                }

                if (item == LIMIT - 1) break;
            }
        }

        //remove
        public int removeItem() {
            int item = buffer[left];
            left = (left + 1) % N;
            return item;
        }

        //consume
        public void consumeItem(int item) throws InterruptedException, IOException {
            int randTime = (int) (Math.random() * 10);
            sleep(randTime);//spending 0 - 10 ms(random)
            var time = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS").format(new Date());
            fileOut.write(("consuming NO." + item + " item at " + time + '\n').getBytes());
//            System.out.println("consuming NO." + item + " item at " + time + '\n');
        }

    }
}
