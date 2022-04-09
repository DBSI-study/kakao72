import copy
def solution(key, lock):
    m = len(key)
    n = len(lock)
    size = m-1 + n + m-1            
    # 배열 확장
    expansion_lock = [[0] * size for _ in range(size)]
    for i in range(n):
        for j in range(n):
            expansion_lock[i+m-1][j+m-1] = lock[i][j]
    for i in range(4):
        if explore(key, expansion_lock,n):
            return True
        key = rotation_90(key)
    return False

# 배열 90도 회전    
def rotation_90(key):
    return list(i[::-1] for i in zip(*key))

# key로 탐색
def explore(key, arr,n):
    m = len(key)
    s = len(arr)
    for i in range(s-m+1):
        for j in range(s-m+1):
            if check(i,j,key,arr,n):
                return True
    return False
# key가 lock과 맞았는지 확인
def check(x,y,key,arr,n):
    temp = copy.deepcopy(arr)
    for i in range(len(key)):
        for j in range(len(key)):
            temp[x+i][y+j] += key[i][j]
    m = len(key)
    for i in range(n):
        for j in range(n):
            if temp[i+m-1][j+m-1] != 1:
                return False
    return True
