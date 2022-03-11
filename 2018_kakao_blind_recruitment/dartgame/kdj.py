def solution(dartResult):
    answer = 0
    score_arr = [0,0,0] # 점수 저장 arr
    step = -1  # 몇번째 기회인지 체크
    bonus = ["S","D","T"]
    options = ["*", "#"]
    # 숫자 구분 필요, 
    for i in range(len(dartResult)):
        tmp = dartResult[i]
        if tmp.isdecimal():  # 숫자일 경우,
            if i >=1 and dartResult[i-1].isdecimal():   # 이전 문자도 숫자일 경우, 10이다!
                score_arr[step] = 10
            else: # 1~9인 경우
                step += 1
                score_arr[step] += int(tmp)
        elif tmp in bonus:  # 보너스 문자일 경우,
            score_arr[step] = pow(score_arr[step], bonus.index(tmp)+1)  # 인덱스+1 값이 결국 제곱해야할 값
        elif tmp in options:  # 옵션 문자일 경우,
            if options.index(tmp) == 0:  # "*" 스타상일 경우
                score_arr[step] *= 2
                if step >= 1:
                    score_arr[step-1] *= 2
            else: # "#" 아차상일 경우,
                score_arr[step] *= -1
    answer = sum(score_arr)
    return answer
