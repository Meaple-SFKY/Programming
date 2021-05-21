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

    #********* End *********#
