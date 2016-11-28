class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = 0
        self.left = left
        self.right = right
    def __add__(self, treeNode):
        if(self.val > treeNode.val):
            self.left = treeNode
        else:
            self.right = treeNode
        return

class BST:
    def __init__(self, root):
        self.root = root

    def insert(val):
        if self
