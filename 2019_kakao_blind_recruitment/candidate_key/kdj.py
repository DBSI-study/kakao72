from itertools import combinations

def solution(relation):
    col_idx_arr = [i for i in range(len(relation[0]))]
    candidate_key = []
    for i in range(1,len(relation[0])+1):
        find_candidate_key(col_idx_arr, i, relation, candidate_key)
    return len(candidate_key)

# 후보키 찾아 candidate_key에 넣기
def find_candidate_key(arr, num, relation, candidate_key):
    # 후보키가 될 수 있는 idx 리스트 (arr)C(num)
    kinds = list(combinations(arr, num))
    for idx_tuple in kinds:
        if idx_tuple not in candidate_key:
            # 유일성 확인
            if check_uniqueness(idx_tuple, relation):
                # 최소성 확인
                if check_minimality(candidate_key, idx_tuple):
                    candidate_key.append(idx_tuple)
                    print("candidate_key:", candidate_key)

# 유일성 확인
def check_uniqueness(idxs, relation):
    using_relation = []
    # 사용할 관계만 using_relation에 담기
    for i in range(len(relation)):
        temp = []
        for j in idxs:
            temp.append(relation[i][j])
        using_relation.append(temp)
    
    # 유일성 찾기
    for i in range(0,len(using_relation)-1):
        for j in range(i+1, len(using_relation)):
            if using_relation[i] == using_relation[j]:
                return False
    return True

# idx_tuple을 candidate_key에 추가하기 전에 최소성을 확인
def check_minimality(candidate_key, idx_tuple):
    # idx_tuple에서 candidate_key_tuple의 idx가 모두 존재해야 False
    for candidate_key_tuple in candidate_key:
        cnt = 0
        for idx in candidate_key_tuple:
            if idx in idx_tuple:
                cnt += 1
        if cnt == len(candidate_key_tuple):
            return False
    return True
