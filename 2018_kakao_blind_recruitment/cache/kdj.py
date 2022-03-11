from collections import deque
def solution(cacheSize, cities):
    answer = 0
    cache = deque([], maxlen=cacheSize)
    if cacheSize == 0:
        answer = len(cities) * 5
    else:
        for i in range(len(cities)):
            present = cities[i].lower()  # 현재도시
            # 캐시에 있을 경우, 캐시 업데이트 및 실행 시간 = 1
            if present in cache:
                cache.remove(present)
                cache.append(present)
                answer += 1
            else:  # 캐시에 없을 경우,
                cache.append(present)
                answer += 5
    return answer
