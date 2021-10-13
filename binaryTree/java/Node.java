/**
 * Node
 * 
 * @author Ramon Almeida
 * 
 */
public class Node<K, T> {

    private final K key;
    private final T data;
    private Node<K, T> father;
    private Node<K, T> left;
    private Node<K, T> right;

    public Node(K key, T data) {
        this.key = key;
        this.data = data;
        father = left = right = null;
    }

    public Node(K key, T data, Node<K, T> father) {
        this.key = key;
        this.data = data;
        this.father = father;
        left = right = null;
    }

    public K getKey() {
        return key;
    }

    public T getData() {
        return data;
    }

    public Node<K, T> getFather() {
        return father;
    }

    public void setFather(Node<K, T> father) {
        this.father = father;
    }

    public Node<K, T> getLeft() {
        return left;
    }

    public void setLeft(Node<K, T> left) {
        this.left = left;
    }

    public Node<K, T> getRight() {
        return right;
    }

    public void setRight(Node<K, T> right) {
        this.right = right;
    }
}
