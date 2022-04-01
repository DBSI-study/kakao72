def solution(board):
    answer = 0
    n = len(board[0])
    visited = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if board[i][j] != 0:
                # 첫 방문 일때,
                if visited[i][j] == 0:
                    block = find_block(i,j,board,n)
                    # 없앨 수 있는 모양이고, 그 위에 다른 블록이 없을 때,
                    chk, idx = check_shape(block, board)
                    if chk:
                        if check_top(block, board, idx):
                            answer += 1
                            for x,y in block:
                                board[x][y] = 0
                    print(answer)
        for j in range(n-1,-1,-1):
            if board[i][j] != 0:
                # 첫 방문 일때,
                if visited[i][j] == 0:
                    block = find_block(i,j,board,n)
                    # 없앨 수 있는 모양이고, 그 위에 다른 블록이 없을 때,
                    chk, idx = check_shape(block, board)
                    if chk:
                        if check_top(block, board, idx):
                            answer += 1
                            for x,y in block:
                                board[x][y] = 0
                        else:
                            for x,y in block:
                                visited[x][y] = 1
                    else:
                        for x,y in block:
                            visited[x][y] = 1
                    print(answer)

                    
    return answer
# block의 맨 좌측 상단의 좌표를 기준으로 같은 block을 담은 arr를 반환
def find_block(a,b,board,n):
    stk = [(a,b)]
    block = [(a,b)]
    num = board[a][b]
    while stk:
        x,y = stk.pop()
        d = [(1,0),(0,-1),(0,1)]    # 다음 가야할 방향 저장. 아래, 왼쪽, 오른쪽 순서.
        for dx,dy in d:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < n and 0 <= ny < n and (nx,ny) not in block:    # board 범위 체크 및 중복 제거
                if board[nx][ny] == num:    # 다음 방향에 같은 블록이 있으면, block에 저장
                    stk.append((nx,ny))
                    block.append((nx,ny))
    print(block)
    return block

# 12가지 모양의 블록 중, 블록의 모양만 봤을 때 없앨 수 있는 블록은 총 5가지이다. 
# 그 블록들을 좌표가 담긴 배열에 저장하여 발견한 블록과 비교해서 5가지에 속하면 True 반환
def check_shape(block, board):
    possible_blocks = [[(0,0),(1,0),(1,1),(1,2)], [(0,1),(1,1),(2,1),(2,0)], [(0,0),(1,0),(2,0),(2,1)],
                    [(0,2),(1,2),(1,1),(1,0)], [(0,1),(1,1),(1,0),(1,2)]]
    for pos in possible_blocks:
        coordinate_difference = []
        chk = True
        # coordinate_difference에 block의 좌표와 possible_blocks들의 좌표의 차이를 저장.
        for i in range(4):
            coordinate_difference.append((block[i][0] - pos[i][0], block[i][1] - pos[i][1]))
        # coordinate_difference 내의 배열 중 0~3까지의 좌표 차이값이 모두 같다면 possible_blocks 중 하나라는 것을 의미
        for i in range(3):
            if coordinate_difference[i] != coordinate_difference[i+1]:
                chk = False
        if chk:
            idx = possible_blocks.index(pos)
            return True, idx
    return False, -1

# block 위 중 '직사각형 모양이 될 수 있는 열에' 다른 block이 있으면 없앨 수 있는 모양이여도 직사각형을 만들지 못하므로 없앨 수 없다.
# block 위에 다른 block이 있는지 확인하는 함수 
def check_top(block, board, idx):
    can_erase_col = [[1,2],[-1],[1],[-1,-2],[-1,0,1]]
    a,b = block[0]
    ran = a
    if 1 <= idx <= 2:
        ran = a+1
    for i in range(0,ran+1):
        for j in can_erase_col[idx]:
            if board[i][b+j] not in [0,board[a][b]]:
                return False
    return True
