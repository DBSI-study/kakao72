def check(p):
    if p[0] != "(" and p[-1] != ")":
        return False
    stack = []
    for i in p:
        if i == "(":
            stack.append(i)
        else:
            # ")"일 때 stack이 비었으면, False
            if not stack:
                return False
            stack.pop()
    
    return True
def solution(p):
    # 1. 빈 문자열일 경우 빈 문자열 반환,
    if not p:
        return p
    else:
        # 2. 문자열을 u,v로 분리
        left, right = 0,0
        u, v = "",""
        for i in range(len(p)):
            if p[i] == "(":
                left += 1
            elif p[i] == ")":
                right += 1
            if left == right:
                u += p[:i+1]
                v += p[i+1::]
                break
        # 3. u가 올바른 문자열일때,
        if check(u):
            return u + solution(v)
        # 4. u가 올바른 문자열이 아닐때,
        else:
            s = "(" + solution(v) + ")"
            for i in u[1:-1]:
                if i == "(":
                    s += ")"
                else:
                    s += "("
            return s
