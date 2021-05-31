# def judge(row):  # 判断是否在同一列、同一对角线上
#     if row == 0:
#         return True
#     for i in range(row):
#         if abs(col[row] - col[i]) == row - i or col[row] == col[i]:  # 若在对角线上则两个皇后横轴和纵轴的距离相等
#             return False
#     return True
#
#
# def dfs(row):
#     global map1, col, cnt, n  # 变成全局变量 省的调用
#     if row == n:
#         cnt += 1  # 记录可放置的方式
#         return
#
#     while col[row] < n:  # 如果第(row+1)行还没判断完 判断是否有满足条件的位置
#         if judge(row):  # 如果该位置可放皇后 进行下一行搜索
#             dfs(row + 1)
#             col[row] += 1  # 标记本行位置的下一位 回溯时防止走重复的路
#         else:  # 如果该位置不可放皇后 则移到下一个位置
#             col[row] += 1
#     if col[row] == n:  # 如果一行的位置都遍历了 也没满足条件的 将此位置信息清零 返回上一行
#         col[row] = 0
#         return
#
#
# n = int(input("Queens' number: "))  # 皇后数量
# map1 = [([] * n) for i in range(n)]  # 棋盘
# col = [0] * n  # 记录每一行的皇后在第几列
# cnt = 0  # 可放置的方式记录
# dfs(0)  # 深度优先搜索 采用回溯法 递归法
# print(cnt)

#
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self, n=0):
        self.vis = [[]]             #用于标记是否存在皇后的二维列表（初始值全为0）
        self.ans = 0                #用于存储答案（N皇后方案数，初始值0）
        self.n = n                  #用于存储皇后数量n
        self.col = [0] * self.n  # 记录每一行的皇后在第几列
    def solveNQueens(self):
        """求解N皇后问题（调用self.DFS函数）
        :rtype: self.ans: int    #返回N皇后放置方案数
        """
        #请在这里补充代码，完成本关任务
        #********** Begin **********#

        self.DFS(0,self.n)

        return self.ans
        #********** End **********#
    def DFS(self, row, n):
        """深度优先搜索N皇后问题的解空间
        :type: row: int      #NxN棋盘的第row行
        :type: n: int        #皇后数量n
        :rtype: None         #无返回值
        """
        #请在这里补充代码，完成本关任务
        #********** Begin **********#
        if row == n:
            self.ans += 1  # 记录可放置的方式
            return

        print("row=" + str(row))
        while self.col[row] < n:  # 如果第(row+1)行还没判断完 判断是否有满足条件的位置
            if self.judge(row):  # 如果该位置可放皇后 进行下一行搜索

                self.DFS(row + 1,n)

                self.col[row] += 1  # 标记本行位置的下一位 回溯时防止走重复的路
            else:  # 如果该位置不可放皇后 则移到下一个位置
                self.col[row] += 1
        if self.col[row] == n:  # 如果一行的位置都遍历了 也没满足条件的 将此位置信息清零 返回上一行
            self.col[row] = 0
            return

    def judge(self,row):  # 判断是否在同一列、同一对角线上
        if row == 0:
            return True
        for i in range(row):
            if abs(self.col[row] - self.col[i]) == row - i or self.col[row] == self.col[i]:  # 若在对角线上则两个皇后横轴和纵轴的距离相等
                return False
        return True
        #********** End **********#

a = Solution(1)
print(a.solveNQueens())