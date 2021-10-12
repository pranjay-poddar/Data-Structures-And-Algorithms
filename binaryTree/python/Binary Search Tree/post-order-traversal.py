class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root: TreeNode):
        result = []
        if root is not None:
            result = self.postorderTraversal(root.left)
            result += self.postorderTraversal(root.right)
            result.append(root.val)
        
        return result
        