/**
 * BinaryTree
 * 
 * @author Ramon Almeida
 * 
 */

import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree<K, T> {

    private Node<K, T> root;
    private final Comparator<K> comparator;

    public BinaryTree(Comparator<K> comparator) {
        root = null;
        this.comparator = comparator;
    }

    public boolean isEmpty() {
        return subTreeIsEmpty(root);
    }

    public T remove(K key) throws Exception {
        final Node<K, T> node = findNode(key);

        if (node == null)
            throw new Exception("Key not found.");

        Node<K, T> nodeSub = null;

        if (subTreeIsEmpty(node.getRight())) {
            // If the removed node has none or only the left child
            nodeSub = node.getLeft();
        } else {
            // If the removed node has the right child
            // This includes having two children, left and right.
            nodeSub = node.getRight();
            Node<K, T> nodeT = nodeSub;

            // Search the leftmost node of the subtree.
            while (!subTreeIsEmpty(nodeT.getLeft()))
                nodeT = nodeT.getLeft();

            // Linking the rearranged nodes
            if (nodeSub != nodeT) {
                Node<K, T> temp = nodeT.getFather();
                if (subTreeIsEmpty(nodeT.getRight())) {
                    temp.setLeft(null);
                } else {
                    temp.setLeft(nodeT.getRight());
                    changeFather(nodeT.getRight(), temp);
                }

                nodeT.setRight(nodeSub);
                changeFather(nodeSub, nodeT);
                nodeSub = nodeT;
            }

            nodeSub.setLeft(node.getLeft());
            changeFather(nodeSub.getLeft(), nodeSub);
        }

        if (subTreeIsEmpty(node.getFather()))
            root = nodeSub;
        else {
            if (node.getFather().getLeft() == node)
                node.getFather().setLeft(nodeSub);
            else
                node.getFather().setRight(nodeSub);
        }

        changeFather(nodeSub, node.getFather());

        return node.getData();
    }

    public void add(K key, T data) throws Exception {

        if (isEmpty()) {
            root = new Node<K, T>(key, data);
            return;
        }

        int rs = 0;
        Node<K, T> node_aux = null, node_child = root;

        do {
            node_aux = node_child;
            rs = comparator.compare(node_aux.getKey(), key);

            if (rs == 0)
                throw new Exception("Duplicate Key item");

            node_child = (rs > 0 ? node_aux.getLeft() : node_aux.getRight());

        } while (node_child != null);

        final Node<K, T> node = new Node<K, T>(key, data, node_aux);

        if (rs > 0)
            node_aux.setLeft(node);
        else
            node_aux.setRight(node);
    }

    public T find(K key) {
        final Node<K, T> node = findNode(key);

        if (node != null)
            return node.getData();

        return null;
    }

    public T getMin() {
        if (isEmpty())
            return null;

        Node<K, T> node = null;
        for (node = root; node.getLeft() != null; node = node.getLeft());

        return node.getData();
    }

    public T getMax() {
        if (isEmpty())
            return null;

        Node<K, T> node = null;
        for (node = root; node.getRight() != null; node = node.getRight());

        return node.getData();
    }

    private boolean subTreeIsEmpty(Node<K, T> node) {
        return node == null;
    }

    private Node<K, T> findNode(K key) {
        if (isEmpty())
            return null;

        int rs = 0;
        Node<K, T> node = root;

        while (node != null && (rs = comparator.compare(node.getKey(), key)) != 0)
            node = (rs > 0 ? node.getLeft() : node.getRight());

        return node;
    }

    private void changeFather(Node<K, T> node, Node<K, T> newFather) {
        if (subTreeIsEmpty(node))
            return;

        node.setFather(newFather);
    }

    @Override
    public String toString() {
        Queue<Node<K, T>> queue = new LinkedList<Node<K, T>>();
        StringBuffer sBuffer = new StringBuffer("\n++ Tree Status ++\n");
        queue.add(root);

        while (!queue.isEmpty()) {
            Node<K, T> node = queue.remove();

            if (!subTreeIsEmpty(node)) {
                String r = (node.getFather() != null ? node.getFather().getData().toString() : "null"),
                        s = (node.getLeft() != null ? node.getLeft().getData().toString() : "null"),
                        t = (node.getRight() != null ? node.getRight().getData().toString() : "null");
                sBuffer.append("Node (" + node.getData() + ") - F(" + r + ")" + " - {" + s + ", " + t + "}\n");
                queue.add(node.getLeft());
                queue.add(node.getRight());
            }
        }

        T vMin = getMin(), vMax = getMax();

        sBuffer.append(vMin != null ? "Min: " + vMin + ", Max: " + vMax : "Empty");
        return sBuffer.toString();
    }

}