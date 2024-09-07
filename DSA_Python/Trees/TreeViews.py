from collections import deque

class treeNode:
    def __init__(self, val: int) -> None:
        self.data = val
        self.left = None
        self.right = None

class tree:
    root : treeNode
    def __init__(self) -> None:
        self.root = None

    # INSERTION IN TREE
    def add(self, val:int) -> None:
        if self.root == None:
            node = treeNode(val)
            self.root = node
        else:
            self.add_recursive(self.root, val)

    def add_recursive(self, node:treeNode, val:int):
        if node.data > val:
            if node.left == None:
                node.left = treeNode(val)
            else:
                self.add_recursive(node.left, val)
        else:
            if node.right == None:
                node.right = treeNode(val)
            else:
                self.add_recursive(node.right, val)

    
    # VIEWS IN TREES
    # Left View
    def left_view(self):
        view = []

        node = self.root

        q = deque()

        q.append(node)

        while len(q) != 0:
            val = q.pop()

            print(val.data, end=' ')

            if val.left != None:
                # print('$' + str(val.left.data), end=' ')
                q.appendleft(val.left)
            
            if val.right != None:
                q.appendleft(val.right)


if __name__ == '__main__':
    a = tree()

    l = [7, 3, 9, 1, 2, 8, 11]

    # a.add(l[0])

    for i in l:
        a.add(i)

    # a.preorder()
    a.inorder()
    a.morris_inorder()