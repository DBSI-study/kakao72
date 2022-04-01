def solution(record):
    answer = []
    user = {}
    record_arr = []
    i = 0
    for string in record:
        info = string.split()
        record_arr.append(info)
        if info[0] in ["Enter","Change"]:     # Enter 일때,
            user[info[1]] = info[2]
    for info in record_arr:
        if info[0] == "Enter":
            answer.append("{}님이 들어왔습니다.".format(user[info[1]]))
        elif info[0] == "Leave":
            answer.append("{}님이 나갔습니다.".format(user[info[1]]))
    return answer
