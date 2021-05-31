# -*- coding:utf-8 -*-
class Solution:
    def __init__(self, n=0):
        self.vis = [[]]  # 用于标记是否存在皇后的二维列表（初始值全为0）
        self.ans = 0  # 用于存储答案（N皇后方案数，初始值0）
        self.n = n  # 用于存储皇后数量n

    def solveNQueens(self):
        """求解N皇后问题（调用self.DFS函数）
        :rtype: self.ans: int    #返回N皇后放置方案数
        """
        # 请在这里补充代码，完成本关任务
        # ********** Begin **********#
        self.vis = []
        if self.n == 1:
            self.ans = 1
            return self.ans
        self.vis = [0] * self.n
        Solution.DFS(self, 0, self.n)
        return self.ans
        # ********** End **********#

    def DFS(self, row, n):
        """深度优先搜索N皇后问题的解空间
        :type: row: int      #NxN棋盘的第row行
        :type: n: int        #皇后数量n
        :rtype: None         #无返回值
        """
        # 请在这里补充代码，完成本关任务
        # ********** Begin **********#
        border = len(self.vis)
        if (row >= border):
            self.ans += 1
        col = 0
        while col < border:
            for col in range(border):
                i = 0
                flag = 1
                for i in range(row):
                    if abs(self.vis[i]-col) == 0 or abs(self.vis[i]-col) == abs(i-row):
                        flag = 0
                if flag == 1:
                    self.vis[row] = col
                    Solution.DFS(self, row + 1, n)
            col += 1
        # ********** End **********#
