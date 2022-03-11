import numpy as np
def solution(n, arr1, arr2):
    arr1 = change_10_2(arr1,n)
    arr2 = change_10_2(arr2,n)
    arr = arr1+arr2
    answer = solve(arr,n)
    
    return answer
    
# 10진수를 2진수로 바꿔서 arr에 저장.    
def change_10_2(arr,n):
    for i in range(n):
        arr[i] = int(bin(arr[i])[2::])
    return np.array(arr)

def solve(np_arr,n):
    result = []
    for i in range(n):
        temp2 = str(np_arr[i])
        null_cnt = n - len(temp2) # 공백 개수
        temp = " " * null_cnt
        for j in range(len(temp2)):
            if temp2[j] == "0":
                temp += " "
            else:
                temp += "#"
        result.append(temp)
    return result
