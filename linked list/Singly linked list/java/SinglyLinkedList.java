/**
 * SinglyLinkedList
 * 
 * @author Ramon Almeida
 * 
 */

public class SinglyLinkedList {

    public static void main(String[] args) throws ListIllegalPositionException {

        ListLinked<String> linked = new ListLinked<String>();

        linked.append("Maria");
        linked.insert(0, "Joseph");
        linked.insert(1, "Chris");
        linked.append("Clarie");
        System.out.println(linked + " - " + linked.getLenght());

        System.out.println(" - POP: " + linked.pop());
        System.out.println(linked + " - " + linked.getLenght());

        linked.append("Victor");
        System.out.println(linked + " - " + linked.getLenght());

        System.out.println(" - REMOVE (0): " + linked.remove(1));
        System.out.println(linked + " - " + linked.getLenght());

        System.out.println(" - REMOVE (2): " + linked.remove(2));
        System.out.println(linked + " - " + linked.getLenght());

        linked.append("Kirk");
        System.out.println(linked + " - " + linked.getLenght());
    }

}

class ListLinked<T> {

    private int lenght;
    private final ItemList<T> head;
    private ItemList<T> last;

    public ListLinked() {
        head = new ItemList<T>(null);
        last = head;
    }

    public int getLenght() {
        return lenght;
    }

    public T getHead() throws ListIllegalPositionException {
        if (head.getNext() == null)
            throw new ListIllegalPositionException("Invalid position.");
        return head.getNext().getData();
    }

    public T getLast() throws ListIllegalPositionException {
        if (head.getNext() == null)
            throw new ListIllegalPositionException("Invalid position.");

        return last.getData();
    }

    public void append(T data) {
        ItemList<T> itemList = newItem(data);
        last.setNext(itemList);
        last = last.getNext();
        lenghtIncrease();
    }

    public T pop() throws ListIllegalPositionException {
        if (isEmpty())
            throw new ListIllegalPositionException("Invalid position.");

        ItemList<T> item_aux = null;
        for (item_aux = head; item_aux.getNext().getNext() != null; item_aux = item_aux.getNext());
        T data = item_aux.getNext().getData();
        item_aux.setNext(item_aux.getNext().getNext());
        last = item_aux;
        lenghtDecrease();
        reallocLast();

        return data;
    }

    public void insert(int posi, T data) throws ListIllegalPositionException {
        if (posi < 0 || posi > lenght)
            throw new ListIllegalPositionException("Invalid position.");

        if (posi == lenght) {
            append(data);
            return;
        }

        ItemList<T> itemList = newItem(data), item_aux = head;
        for (int i = 0; i < posi; ++i, item_aux = item_aux.getNext());
        itemList.setNext(item_aux.getNext());
        item_aux.setNext(itemList);
        lenghtIncrease();
        reallocLast();
    }

    public T remove(int posi) throws ListIllegalPositionException {
        if (isEmpty() || posi < 0 || posi >= lenght)
            throw new ListIllegalPositionException("Invalid position.");

        ItemList<T> item_aux = head;
        for (int i = 0; i < posi; ++i, item_aux = item_aux.getNext());
        T data = item_aux.getNext().getData();
        item_aux.setNext(item_aux.getNext().getNext());
        last = item_aux;
        lenghtDecrease();
        reallocLast();

        return data;
    }

    public boolean isEmpty(){
        return head.getNext() == null;
    }

    private void lenghtDecrease() {
        lenght--;
    }

    private void lenghtIncrease() {
        lenght++;
    }

    private void reallocLast() {
        if (lenght == 0)
            last = head;
    }

    private ItemList<T> newItem(T data) {
        return new ItemList<T>(data);
    }

    @Override
    public String toString() {
        StringBuffer content = new StringBuffer();

        for (ItemList<T> item = head.getNext(); item != null; item = item.getNext())
            content.append(item.getData() + ", ");

        return content.toString();
    }
}

class ItemList<T> {

    private T data;
    private ItemList<T> next;

    public ItemList(T data) {
        this.data = data;
        this.next = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public ItemList<T> getNext() {
        return next;
    }

    public void setNext(ItemList<T> next) {
        this.next = next;
    }
}

class ListIllegalPositionException extends Exception {

    public ListIllegalPositionException(String msg) {
        super(msg);
    }

    public ListIllegalPositionException(String msg, Throwable throwable) {
        super(msg, throwable);
    }

}