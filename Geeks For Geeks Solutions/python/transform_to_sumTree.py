
"""
Transform to Sum Tree
This Problem was asked in Geeksforgeeks Interview Series Samsung
Problem -   Given a Binary Tree of size N, where each node can have positive and negative values. 
            Convert this to a tree where each node contains the sum of left and right sub trees of the original tree.
            The values of leaf nodes are changed to 0.

Idea -
1. We will do a traversal of the given tree.
2. In the traversal, store the old value of the current node, recursively call for left and right subtrees and change the value of current node as sum of the values returned by the recursive calls.
3. Return the sum of new value and value.

This will print Inorder Traversal of Sum Tree

Test cases -
1.  I/P - 
                    10
                /       \
            -2              6
           /   \          /  \ 
         8     -4       7     5
    O/P - 
            20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0

Time Complexity - O(n) n=number of nodes in Binary Tree
"""


class node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


def toSumTree(Node):
    if(Node == None):
        return 0

    old_val = Node.data

    Node.data = toSumTree(Node.left) + \
        toSumTree(Node.right)

    return Node.data + old_val


def printInorder(Node):
    if (Node == None):
        return
    printInorder(Node.left)
    print(Node.data, end=" ")
    printInorder(Node.right)


def newNode(data):
    temp = node(0)
    temp.data = data
    temp.left = None
    temp.right = None

    return temp


# Driver Code
if __name__ == "__main__":
    root = None
    x = 0

    root = newNode(10)
    root.left = newNode(-2)
    root.right = newNode(6)
    root.left.left = newNode(8)
    root.left.right = newNode(-4)
    root.right.left = newNode(7)
    root.right.right = newNode(5)

    toSumTree(root)

    print("Inorder Traversal of the resultant tree is: ")
    printInorder(root)
