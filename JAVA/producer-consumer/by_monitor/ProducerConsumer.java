import com.sun.source.tree.WhileLoopTree;

import javax.imageio.plugins.tiff.TIFFImageReadParam;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class ProducerConsumer {
    static final int N = 50;//size of buffer
    static final int LIMIT = 500;//limit of number of items produced
    static Thread prod = new Producer();
    private static Thread consu = new Consumer();
    private static MonitorForProduceAndConsume moni = new MonitorForProduceAndConsume();
    //    static CountTime ct = new CountTime();
    static int id = 0;

    static File record = new File("record_prod_and_cons.txt");
    static OutputStream fileOut;

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
        consu.start();
        while (true) {
            if (prod.getState() == Thread.State.TERMINATED && consu.getState() == Thread.State.TERMINATED) {
                System.out.println("Threads of producing and consuming have terminated, and the record is closed.");
                fileOut.close();
                break;
            }
        }


    }


    static class Producer extends Thread {
        @Override
        public void run() {
            int item;
            while (id < LIMIT) {

                try {
                    item = produceItem();
                    moni.insert(item);//this process is in monitor
                } catch (IOException | InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        public int produceItem() throws IOException, InterruptedException {
            //return ID of item
            int randTime = (int) (Math.random() * 10);
            sleep(randTime);//spending 0 - 10 ms (random)
            var time = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS").format(new Date());

            fileOut.write(("producing NO." + id + " item at " + time + '\n').getBytes());

            return id++;

        }
    }

    static class Consumer extends Thread {
        @Override
        public void run() {
            int item;
            while (true) {
                item = moni.remove();//this process is in monitor
                try {
                    consumeItem(item);
                } catch (IOException | InterruptedException e) {
                    e.printStackTrace();
                }
                if (item == LIMIT - 1) break;
            }

        }

        public void consumeItem(int item) throws IOException, InterruptedException {
            int randTime = (int) (Math.random() * 10);
            sleep(randTime);//spending 0 - 10 ms (random)
            var time = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS").format(new Date());
            fileOut.write(("consuming NO." + item + " item at " + time + '\n').getBytes());
        }
    }

    static class MonitorForProduceAndConsume {
        static int[] buffer = new int[N];

        private int count = 0, left = 0, hole = 0;

        public synchronized void insert(int val) {
            //producing...
            if (count == N) {
                //now waiting...
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            buffer[hole] = val;
            hole = (hole + 1) % N;
            count++;
            if (count == 1) notify();
        }

        public synchronized int remove() {
            //consuming...
            int val;
            if (count == 0) {
                //now waiting...
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
            val = buffer[left];//remove to consume
            left = (left + 1) % N;
            count--;
            if (count == N - 1) notify();
            return val;
        }
    }

}
