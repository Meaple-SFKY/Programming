def eightqueen(board, row):
    border = len(board)
    if row >= border:
        print("***********")
        for i, col in enumerate(board):
            print('□ ' * col + '■ ' + '□ ' * (len(board) - 1 - col))
        print("")
    col = 0
    while col < border:
        for col in range(border):
            i = 0
            flag = 1
            for i in range(row):
                if abs(board[i]-col) == 0 or abs(board[i]-col) == abs(i-row):
                    flag = 0
            if flag == 1:
                board[row] = col
                eightqueen(board, row+1)
        col += 1


board = [0 for i in range(1)]
eightqueen(board, 0)
