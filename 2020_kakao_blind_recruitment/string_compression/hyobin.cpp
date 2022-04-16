#include <string>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();

    for(int i=1;i<=s.length()/2;i++){
        int cnt=1;
        string recur=s.substr(0,i);
        string tmp,after;

        for(int j=i; j<s.length();j+=i){ 
            tmp = s.substr(j,i);
            if((tmp.compare(recur)==0)) 
                cnt++;
            else{
                if(cnt>1)
                    after+=to_string(cnt);
                after+=recur;
                cnt=1;
                recur = tmp;
            }
            
            if(j + i >= s.length()){ //남은 부분 처리
                if(cnt==1)
                    after+=s.substr(j);
                else
                    after+=to_string(cnt)+recur;
                break;
            }
        }
        if(answer>after.length())
            answer=after.length();
    }
    return answer;
}
