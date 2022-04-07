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
            if(cnt > 1) ret += to_string(cnt);
            ret += compare;
            compare = s.substr(i, len);
            cnt = 1;
        }
    }
    if(cnt > 1) ret += to_string(cnt);
    ret += compare;
	cout << ret << "\n";
    return ret;
}

int getStringLen(string s){
    return s.length();
}

int solution(string s) {
    int answer = 1000;
    int max_len = max((int)s.length() / 2, 1);
    
    for(int i = 1; i <= max_len; i++){
        answer = min(answer, getStringLen(compressStringBy(s, i)));
    } 
    
    return answer;
}

int main(void){
	string input;
	cin >> input;
	cout << solution(input) << "\n";	
	return 0;
}