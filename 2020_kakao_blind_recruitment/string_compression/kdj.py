def solution(s):
    answer = 0
    n = len(s)//2
    result = [len(s)] * (n+1)
    for i in range(1,n+1):
        count = 1
        s2 = ""
        temp = ""
        for j in range(0,len(s),i):
            if s[j:j+i] == s[j+i:j+2*i]:
                count += 1
                temp = s[j:j+i]
            else:
                if count == 1:
                    s2 += s[j:j+i]
                else:
                    s2 += str(count) + temp
                    count = 1
                    
        result[i] = len(s2)
    answer = min(result)
    return answer
