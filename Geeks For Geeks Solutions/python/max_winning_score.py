"""
This problem was asked recently in Geeksforgeeks Interview Series Morgan Stanley
Problem -   In an online game, N blocks are arranged in a hierarchical manner. All the blocks are connected together by a total of N-1 connections.
            Each block is given an ID from 1 to N. A block may be further connected to other blocks.
            Each block is also assigned a specific point value.

            A player starts from Block 1. She must move forward from each block to a directly connected block until she reaches the final block,
            which has no further connection. When the player lands on a block, she collects the point value of that block. 
            The player's score is calculated as the product of point values that the player collects.
            Find the max score a player can achieve.

Test Cases -
1.  I/P -  4
          / \
         2   8
        / \ / \
        2  1 3  4
    O/P - 128
    Explanation - 4*8*4 = 128

2.  I/P - 10
        /    \
        7      5
                \
                1
    O/P - 70
    Explanation - 10*7 = 70

Time Complexity - O(n) n-> number of nodes

"""


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# This function returns overall maximum product in 'res' And returns max path product going through root


def findMaxUtil(root):
    if root is None:
        return 0

    # l and r store maximum path product going through left and right child of root respectively
    l = findMaxUtil(root.left)
    r = findMaxUtil(root.right)

    # Max path for parent call of root. This path must include at most one child of root
    max_single = max(max(l, r) * root.data, root.data)

    # Store the maximum result
    findMaxUtil.res = max(findMaxUtil.res, max_single)

    return max_single

# Return maximum path sum in tree with given root


def findMaxProduct(root):
    findMaxUtil.res = 1

    findMaxUtil(root)
    return findMaxUtil.res


# Driver program
root = Node(10)
root.left = Node(7)
root.right = Node(5)
root.right.right = Node(1)
print("Max path sum is ", findMaxProduct(root))
