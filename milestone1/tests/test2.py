class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.value < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.value)
        inorder_traversal(root.right)

def preorder_traversal(root):
    if root:
        print(root.value)
        preorder_traversal(root.left)
        preorder_traversal(root.right)

def postorder_traversal(root):
    if root:
        postorder_traversal(root.left)
        postorder_traversal(root.right)
        print(root.value)

def search(root, key):
    if root is None or root.value == key:
        return root
    if root.value < key:
        return search(root.right, key)
    return search(root.left, key)

if __name__ == "__main__":
    root = None
    for key in range (1, 10):
        root = insert(root, key)

    print("Inorder Traversal:")
    inorder_traversal(root)

    print("\nPreorder Traversal:")
    preorder_traversal(root)

    print("\nPostorder Traversal:")
    postorder_traversal(root)

    search_key = 7
    result = search(root, search_key)
    if result:
        print("\n{} found in the tree.".format(search_key))
    else:
        print("\n{} not found in the tree.".format(search_key))
