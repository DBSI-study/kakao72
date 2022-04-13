def solution(words, queries):
    answer = [0] * len(queries)
    for word in words:
        check_query(word, queries, answer)
    return answer

def check_query(w, queries, answer):
    for i in range(len(queries)):
        q = queries[i]
    
        if len(q) != len(w):
            continue
        else:
            # queries의 ? 인 곳을 w도 ?로 바꾸어 비교한다.
            idx = -1
            temp = w
            while True:
                idx = q.find("?",idx+1)
                if idx == -1:
                    break
                temp = temp[:idx] + "?" + temp[idx+1:]
            if temp == q:
                answer[i] += 1
