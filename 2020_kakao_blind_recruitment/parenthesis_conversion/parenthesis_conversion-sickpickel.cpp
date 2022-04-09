#include <string>
#include <vector>
#include <iostream>

using namespace std;

int isRightStringBracket(string p){
    int cnt = 0;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0) return 0;
    }
    return 1;
}

string getRightStringBracket(string p){
    if(p.size() == 0) return p;
    string ret = "", u = "", v = "";
    int openCnt = 0, closeCnt = 0, divideIdx = 0; 
    for(int i = 0; i < p.length(); i++) {
        if(p[i] == '(') openCnt++;
        else closeCnt++;
        
        if(openCnt != 0 && openCnt == closeCnt) {
            divideIdx = i + 1; break;
        }
    }
	
    u = p.substr(0, divideIdx);
	v = p.substr(divideIdx, p.length() - divideIdx + 1);
	
    if(isRightStringBracket(u)) return u + getRightStringBracket(v);
    else{
        ret += '(' + getRightStringBracket(v) + ')';
        for(int i = 1; i < u.length() - 1; i++){
            ret += (u[i] == '(' ? ')' : '(');
        }
        return ret;
    }
    return ret;
}

string solution(string p) {
    string answer = "";
    answer = getRightStringBracket(p);
    return answer;
}