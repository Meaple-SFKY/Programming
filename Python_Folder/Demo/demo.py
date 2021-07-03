import queue
import numpy as np
import prettytable as pt

N = int(input("Please enter the number of missionaries and savages: "))
K = int(input("Please enter the maximum capacity of the ship: "))


class Node:
    def __init__(self, n1, n2, k, parent, step):
        self.data = np.array([n1, n2, k])
        self.n1 = n1
        self.n2 = n2
        self.k = k
        self.step = step
        self.f_loss = self.step + n1 + n2 - K * k
        self.parent = parent


def sorte_by_floss():
    tmp_open = opened.queue.copy()
    length = len(tmp_open)

    for i in range(length):
        for j in range(length):
            if tmp_open[i].f_loss < tmp_open[j].f_loss:
                tmp = tmp_open[i]
                tmp_open[i] = tmp_open[j]
                tmp_open[j] = tmp
            if tmp_open[i].f_loss == tmp_open[j].f_loss:
                if tmp_open[i].step > tmp_open[j].step:
                    tmp = tmp_open[i]
                    tmp_open[i] = tmp_open[j]
                    tmp_open[j] = tmp
    opened.queue = tmp_open


opened = queue.Queue()  # open表
start_node = Node(N, N, 1, None, 0)
end_data = np.array([0, 0, 0])
opened.put(start_node)
closed = {}


def refresh_open(now_node):

    tmp_open = opened.queue.copy()
    for i in range(len(tmp_open)):
        data = tmp_open[i]
        now_data = now_node.data
        if (data == now_data).all():
            data_f_loss = tmp_open[i].f_loss
            now_data_f_loss = now_node.f_loss
            if data_f_loss <= now_data_f_loss:
                return False
            else:
                print('')
                tmp_open[i] = now_node
                opened.queue = tmp_open
                return True
    tmp_open.append(now_node)
    opened.queue = tmp_open
    return True


def data_to_int(num):
    value = 0
    for i in num:
        value = value * 10 + i
    return value


def is_safe(node):
    n1, n2, k = node.data
    if n1 < n2 and n1 != 0:
        return False
    if N - n1 < N - n2 and n1 != N:
        return False
    if n1 < 0 or n2 < 0:  # 人数不得小于0
        return False
    if n1 >= n2 or N - n1 >= N - n2:
        return True


def common_missionary_pro():
    while len(opened.queue) != 0:
        node = opened.get()
        if (node.data == end_data).all():
            return node
        closed[data_to_int(node.data)] = 1
        for i in range(N + 1):
            for j in range(N + 1):
                if i + j == 0 or i + j > K or (i != 0 and i < j):
                    continue
                # a=a+1
                if node.k == 1:
                    child_node = Node(node.n1 - i, node.n2 - j, 0, node, node.step + 1)
                else:
                    child_node = Node(node.n1 + i, node.n2 + j, 1, node, node.step + 1)
                if data_to_int(child_node.data) not in closed:
                    if is_safe(child_node.data):
                        refresh_open(child_node)
        sorte_by_floss()
    return None


result_node = common_missionary_pro()


def output_result(node):
    all_node = [node]
    for i in range(node.step):
        father_node = node.parent
        all_node.append(father_node)
        node = father_node
    return list(reversed(all_node))


def cal_tb_row(node, option):
    data = node.data
    n1, n2, k = data
    return [node.step, n1, n2, option[node.step], N - n1, N - n2]


def cal_option(node_list):
    option = []
    for i in range(len(node_list) - 1):
        now_n1, now_n2, now_k = node_list[i].data
        next_n1, next_n2, next_k = node_list[i + 1].data
        nr1 = abs(next_n1 - now_n1)
        nr2 = abs(next_n2 - now_n2)
        nr1 = f'{nr1}个传教士' if nr1 else ''
        nr2 = f'{nr2}个野人' if nr2 else ''
        status = '向右移动' + nr1 + nr2 if now_k == 1 else '向左移动' + nr1 + nr2
        option.append(status)
    option.append('完成')
    return option


def out_put():
    node_list = output_result(common_missionary_pro())
    option = cal_option(node_list)
    tb = pt.PrettyTable()
    field_names = ['次数', '左边的传教士', '左边的野人', '方案', '右边的传教士', '右边的野人']
    tb.field_names = field_names
    for node in node_list:
        tb.add_row(cal_tb_row(node, option))

    print(tb)


out_put()


