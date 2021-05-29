def PlayMazz(graph, start, end, visited=None):
    '''
    深度优先搜索，从1走到9
    :param graph: 搜索的空间
    :param start: 开始搜索的起点
    :param visited:  已经搜索过的点集合
    '''
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end='')
    # 当前地点为终点时结束搜索
    if start == end:
        return
    #********* Begin *********#
    # 看看当前位置有哪些路可以走，如果能走并且之前没有走过就走
    Open = [start]
    Closed = []
    demo = []

    while Open != []:
        n = Open.pop(0)
        Closed.append(n)
        if n == end:
            demo.append(end)
            print("".join(demo))
            return

        visited = graph[n]
        for i in visited:
            for j in Open:
                if i == j:
                    visited.remove(i)
        for i in visited:
            for j in Closed:
                if i == j:
                    visited.remove(i)
        visited.reverse()
        for i in visited:
            Open.insert(0, i)
        if n != start:
            demo.append(n)
    #********* End *********#
