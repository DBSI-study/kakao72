def solution(N, stages):
    answer = []
    failure_rate = []
    temp = len(stages)
    max_stage = max(stages)
    for i in range(1,N+1):  # 스테이지마다 탐색
        if max_stage < i:
            p = (0, i)
        else:
            p = (stages.count(i)/temp, i)
        failure_rate.append(p)
        temp -= stages.count(i)

    for i in range(0,N-1):
        for j in range(i,N):
            if failure_rate[i][0] < failure_rate[j][0]:
                failure_rate[i],failure_rate[j] = failure_rate[j],failure_rate[i]
            elif failure_rate[i][0] == failure_rate[j][0]:
                if failure_rate[i][1] > failure_rate[j][1]:
                    failure_rate[i],failure_rate[j] = failure_rate[j],failure_rate[i]
    for i in failure_rate:
        answer.append(i[1]) 
    return answer
arr = [2,1,2,6,2,4,3,3]
print(solution(5,arr))
