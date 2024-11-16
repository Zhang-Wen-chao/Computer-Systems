# 定义一个二叉树，进行层次遍历，打印每层中的从左往右的第N个元素，N代表所在层数，
# 比如 第1层打印第1个，第2层打印第2个，第N层打印第N个，假如第N层的元素个数小于N，那么打印最右边的即可

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
def levelOrder(root):
    if not root:
        return []
    result = []
    queue = deque([(root, 1)])
    
    while queue:
        node, level = queue.popleft()
        if level >= len(result):
            result.append([])
        result[level].append(node.val)  

        if node.left:
            queue.append((node.left, level+1))
        if node.right:
            queue.append((node.right, level+1))

    for i in range(len(result)):
        result
