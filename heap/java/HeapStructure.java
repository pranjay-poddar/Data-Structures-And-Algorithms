/**
 * HeapStructure
 * 
 * @author Ramon Almeida
 * 
 */

package heap.java;

import java.lang.reflect.Array;
import java.util.Comparator;

/**
 * HeapStructure
 */
public class HeapStructure {

    public static void main(String[] args) throws Exception {

        // Test 1: length=8
        Integer[] data = { 5, 10, 3, 8, 1, 0, -1, 4, 0, 0 };

        // Test 2: length=10
        // Integer[] data = { 2, 7, 26, 25, 19, 17, 1, 90, 3, 36 };

        /**
         * To Run Max Heap.
         * 
         * To run Min Heap: change ComparatorMaxHeap() by
         * ComparatorMinHeap() the in line 33.
         *
         */
        Heap<Integer> heap = new Heap<Integer>(data, 8, new ComparatorMaxHeap());

        // Run the constructor with empty array.
        // Heap<Integer> heap = new Heap<Integer>(Integer.class, 10, new
        // ComparatorMaxHeap());

        System.out.println(heap);

        System.out.println("- ADD (-10)");
        heap.add(-10);
        System.out.println(heap);

        System.out.println("- REMOVE: " + heap.remove());
        System.out.println(heap);

        System.out.println("- ADD (15)");
        heap.add(15);
        System.out.println(heap);

        System.out.println("- ADD (7)");
        heap.add(7);
        System.out.println(heap);

        System.out.println("- REMOVE: " + heap.remove());
        System.out.println(heap);
    }

}

class Heap<T> {

    private T[] arr;
    private int length;
    private Comparator<T> comparator;

    @SuppressWarnings("unchecked")
    public Heap(Class<T> typeData, int size, Comparator<T> comparator) {
        arr = (T[]) Array.newInstance(typeData, size);
        length = 0;
        this.comparator = comparator;
    }

    public Heap(T[] arr, int length, Comparator<T> comparator) {
        this.arr = arr;
        this.length = length;
        this.comparator = comparator;
        build();
    }

    public int getLength() {
        return length;
    }

    public int getSize() {
        return arr.length;
    }

    public boolean isEmpty() {
        return length == 0;
    }

    public boolean isFull() {
        return length >= getSize();
    }

    public void add(T obj) throws Exception {
        if (isFull())
            throw new Exception("Heap is full.");

        arr[length] = obj;
        heapfyUp(length);
        lengthIncrease();
    }

    public T remove() throws Exception {
        if (isEmpty())
            throw new Exception("Heap is empty.");

        T obj = arr[0];
        arr[0] = arr[length - 1];
        lengthDecrease();
        heapfyDown(0);

        return obj;
    }

    private int father(int i) {
        // Index of the father of node is in: (i - 1) / 2 == (i - 1) >>> 1
        return (i - 1) >>> 1;
    }

    private int left(int i) {
        // The left child of a node is in: (i * 2) + 1 == (i << 1) + 1
        return (i << 1) + 1;
    }

    private int right(int i) {
        // The right child of a node is in: (i * 2) + 1 == (i << 1) + 1
        return (i << 1) + 2;
    }

    private void lengthDecrease() {
        length--;
    }

    private void lengthIncrease() {
        length++;
    }

    private void build() {
        if (length < 2)
            return;

        for (int i = father(length - 1); i >= 0; --i)
            heapfyDown(i);
    }

    private void heapfyUp(int i) {
        T aux = null;
        int father = father(i);

        while (i > 0 && comparator.compare(arr[i], arr[father]) < 0) {
            aux = arr[i];
            arr[i] = arr[father];
            arr[father] = aux;
            i = father;
            father = father(i);
        }
    }

    private void heapfyDown(int i) {
        int idxMinChild = 0;
        T aux = null;

        while (left(i) < length) {
            idxMinChild = left(i);
            if (right(i) < length)
                idxMinChild = (comparator.compare(arr[idxMinChild], arr[right(i)]) <= 0 ? idxMinChild : right(i));

            if (comparator.compare(arr[i], arr[idxMinChild]) <= 0)
                return;

            aux = arr[idxMinChild];
            arr[idxMinChild] = arr[i];
            arr[i] = aux;

            i = idxMinChild;
        }
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer("\n");
        for (int i = 0; i < length; ++i)
            buffer.append("" + arr[i] + ", ");
        buffer.append("\n");
        return buffer.toString();
    }
}

/**
 * Class Comparator to MinHeap
 */
class ComparatorMinHeap implements Comparator<Integer> {

    @Override
    public int compare(Integer obj1, Integer obj2) {
        return obj1 - obj2;
    }
}

/**
 * Class Comparator to MaxHeap
 */
class ComparatorMaxHeap implements Comparator<Integer> {

    @Override
    public int compare(Integer obj1, Integer obj2) {
        return -(obj1 - obj2);
    }
}
