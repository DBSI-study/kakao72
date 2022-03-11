def solution(str1, str2):
    arr1 = changeMultipleSet(str1)
    arr2 = changeMultipleSet(str2)
    if len(arr1) + len(arr2) == 0 or arr1 == arr2:
        return 65536
    else:
        answer = similarityCheck(arr1, arr2)
        return answer
    
# 문자열을 다중집합 arr로 변환하는 함수
def changeMultipleSet(s):
    s = s.lower()
    arr = []
    for i in range(len(s)-1):
        arr.append(s[i:i+2])
    new_arr = []
    for i in arr:  # "문자가 아니면 제거"
        if 97 <= ord(i[0]) <= 122 and 97 <= ord(i[1]) <= 122:
            new_arr.append(i)
    new_arr.sort()

    return new_arr


# arr의 원소 개수를 저장하는 dictionary 반환
def counter(arr):
    dic = {}
    for i in arr:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1

    return dic

# 두 다중집합의 유사도 검사
def similarityCheck(arr1, arr2):
    dic1 = counter(arr1)
    dic2 = counter(arr2)
    set1 = set(arr1)
    set2 = set(arr2)
    intersection = set1&set2
    sum_of_sets = set1|set2
    size_multiple_intersection = 0
    size_multiple_sum_of_sets = len(sum_of_sets)
    for i in intersection:
        size_multiple_intersection += min(dic1[i],dic2[i])
    for i in sum_of_sets:
        if i in dic1 and i in dic2:
            size_multiple_sum_of_sets += max(dic1[i],dic2[i]) - 1
        elif i in dic1 and i not in dic2:
            size_multiple_sum_of_sets += dic1[i] - 1
        elif i not in dic1 and i in dic2:
            size_multiple_sum_of_sets += dic2[i] - 1
    similarity = int((size_multiple_intersection/size_multiple_sum_of_sets) * 65536)
    return similarity
