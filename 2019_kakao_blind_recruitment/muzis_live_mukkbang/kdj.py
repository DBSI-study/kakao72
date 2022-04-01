# 시간 초과
def solution(food_times, k):
    answer = 0
    time = 0
    idx = 0
    while time < k:
        num_of_foods = len(food_times) - food_times.count(0)
        if num_of_foods == 0:
            return -1
        if food_times[idx] > 0:
            food_times[idx] -= 1
            time += 1
        idx += 1
        if idx == len(food_times):
            idx = 0
    while food_times[idx] == 0:
        idx += 1
        if idx == len(food_times):
            idx = 0
    answer = idx+1
    return answer
