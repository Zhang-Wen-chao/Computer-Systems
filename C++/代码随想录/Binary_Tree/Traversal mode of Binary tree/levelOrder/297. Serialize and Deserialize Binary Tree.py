class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string."""
        def dfs(node):
            if not node:
                return "None,"
            return str(node.val) + "," + dfs(node.left) + dfs(node.right)
        return dfs(root)

    def deserialize(self, data):
        """Decodes your encoded data to tree."""
        def dfs(nodes):
            val = next(nodes)
            if val == "None":
                return None
            node = TreeNode(int(val))
            node.left = dfs(nodes)
            node.right = dfs(nodes)
            return node
        return dfs(iter(data.split(',')))

# 测试用例
codec = Codec()
tree = TreeNode(1, TreeNode(2), TreeNode(3, TreeNode(4), TreeNode(5)))
data = codec.serialize(tree)
print(data)  # 输出序列化的字符串
deserialized_tree = codec.deserialize(data)
print(codec.serialize(deserialized_tree))  # 验证反序列化是否正确
