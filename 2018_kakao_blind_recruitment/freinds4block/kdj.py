def solution(m, n, board):
    answer = 0
    for i in range(m):
        board[i] = list(board[i])

    while True:
        idxs= []  # 2x2 블록의 첫번째 index 저장
        # 2x2 블록이 있는지 확인한 후 그 첫번째 idx를 idxs 배열에 저장
        for i in range(0,m-1):
            for j in range(0,n-1):
                if board[i][j] != "0" and board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1]:
                    idxs.append((i,j))
        if len(idxs) == 0:   # 2x2 블록이 없으면 while문 중단
            break
        # 2x2 블록에 해당되는 블록들을 "0"로 바꾼다.
        for i,j in idxs:
            for k in range(2):
                for l in range(2):
                    if board[i+k][j+l] != "0":
                        board[i+k][j+l] = "0"
                        answer += 1

        # 블록이 아래로 떨어져 빈 공간을 채운다. -> 자신 밑에 "0"가 있으면 서로 위치를 바꾼다.
        for j in range(n):
            for i in range(m-2,-1,-1):
                for k in range(m-1,i,-1):
                    if board[i][j] != "0" and board[k][j] == "0":
                        board[i][j], board[k][j] = board[k][j], board[i][j]
    return answer
