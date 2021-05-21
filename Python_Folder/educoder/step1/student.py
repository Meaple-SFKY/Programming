def PlayMazz(mazz, start, end):
    '''
    走迷宫，从start走到end
    :param mazz: 图
    :param start: 图的起点
    :param end: 图的出口
    '''
    # queue为队列，当队列为空或者当前地点为终点时搜索结束
    visited, queue = set(), [start]
    queue = []
    open = [start]
    close = []
    while open != []:
        n = open.pop(0)
        queue.append(n)
        close.append(n)
        if n == end:
            print(queue)
            return
        visited = mazz[n]
        for i in visited:
            for j in open:
                if i == j:
                    visited.remove(i)
        for i in visited:
            for j in close:
                if i == j:
                    visited.remove(i)
        for i in visited:
            open.append(i)
    # newNode = mazz['A']
    # print(newNode)
    #********* End *********#
