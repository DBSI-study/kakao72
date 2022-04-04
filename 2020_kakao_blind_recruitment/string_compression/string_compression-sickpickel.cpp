#include <string>
#include <vector>
#include <iostream>

using namespace std;

string compressStringBy(string s, int len){
    int cnt = 1;
    string ret = "";
    string compare = s.substr(0, len);
    for(int i = len; i < s.length(); i += len) {
        
        if(compare == s.substr(i, len)) cnt++;
        else{
            if(cnt > 1) ret += '0' + cnt;
            ret += compare;
            compare = s.substr(i, len);
            cnt = 1;
        }
    }
    if(cnt > 1) ret += '0' + cnt;
    ret += compare;
    return ret;
}

int getStringLen(string s){
    return s.length();
}

int solution(string s) {
    int answer = 1000;
    int max_len = s.length() / 2;
    
    for(int i = 1; i <= max_len; i++){
        answer = min(answer, getStringLen(compressStringBy(s, i)));
    } 
    
    return answer;
}