import sys
sys.setrecursionlimit(10**6)

class Node:
    def __init__(self, value, info):
        self.value = value
        self.info = info
        self.left, self.right = None, None

class Binary_tree:
    def __init__(self):
        self.root = None
    
    def insert(self, value, info):
        self.current_node = self.root
        if self.current_node == None:
            self.root = Node(value,info)
        else:
            while True:
                # x값이 current_node보다 작을 경우
                if info[0] < self.current_node.info[0]:
                    if self.current_node.left == None:
                        self.current_node.left = Node(value, info)
                        break
                    else:
                        self.current_node = self.current_node.left
                # x값이 current_node보다 클 경우
                else:
                    if self.current_node.right == None:
                        self.current_node.right = Node(value, info)
                        break
                    else:
                        self.current_node = self.current_node.right
    
    # 전위 순회 - root->left->right
    def pre_order(self, node, arr):
        if node != None:
            arr.append(node.value)
            if node.left != None:
                self.pre_order(node.left, arr)
            if node.right != None:
                self.pre_order(node.right, arr)
        return arr

    # 후위 순회 - left->right->root
    def post_order(self, node, arr):
        if node != None:
            if node.left != None:
                self.post_order(node.left, arr)
            if node.right != None:
                self.post_order(node.right, arr)
            arr.append(node.value)
        return arr   

def make_sorted_info(nodeinfo):
    arr = []
    for idx, info in enumerate(nodeinfo):
        arr.append((idx+1,info))
    arr.sort(key = lambda x:x[1][1], reverse=True)
    return arr

def solution(nodeinfo):
    answer = []
    sorted_info_arr = make_sorted_info(nodeinfo)
    bin_tree = Binary_tree()
    for val, info in sorted_info_arr:
        bin_tree.insert(val, info)
    pre_order_arr = bin_tree.pre_order(bin_tree.root, [])
    post_order_arr = bin_tree.post_order(bin_tree.root, [])
    answer.append(pre_order_arr)
    answer.append(post_order_arr)
    return answer
