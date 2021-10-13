/**
 * MainBinaryTree
 * 
 * @author Ramon Almeida
 * 
 */

import java.util.Comparator;

public class MainBinaryTree {
    public static void main(String[] args) throws Exception {

        BinaryTree<String, Integer> binaryTree = new BinaryTree<String, Integer>(new CompatorStringKey());

        // Formate output toString Binary Tree
        // Node ("nodeActual") - F("Father") - {"left", "left"}

        binaryTree.add("a", 1);
        System.out.println(binaryTree);

        binaryTree.remove("a");
        System.out.println(binaryTree);

        binaryTree.add("e", 5);
        binaryTree.add("c", 3);
        binaryTree.add("j", 10);
        binaryTree.add("t", 20);
        binaryTree.add("i", 9);
        binaryTree.add("g", 7);
        binaryTree.add("h", 8);
        System.out.println(binaryTree);
        System.out.println("\n");
        binaryTree.remove("c");
        System.out.println(binaryTree);
    }
}

/**
 * CompatorStringKey
 * 
 * Class Key Comparator
 */
class CompatorStringKey implements Comparator<String> {

    @Override
    public int compare(String obj1, String obj2) {
        return obj1.compareTo(obj2);
    }

}
