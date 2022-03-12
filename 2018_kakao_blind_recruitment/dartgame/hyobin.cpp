#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int star=0;
    int nowScore=0;
    
    for(int i=0;dartResult[i]!='\0';i++){
        if(dartResult[i]-'0'>=0 && dartResult[i]-'0'<=9){
            answer+=nowScore;
            star=nowScore;
            if(dartResult[i]=='1' && dartResult[i+1]=='0'){
                nowScore=10;
                i++;
            }
            else nowScore=dartResult[i]-'0';
           
        }
        
        else if(dartResult[i]=='D') nowScore=pow(nowScore,2);
        else if(dartResult[i]=='T') nowScore=pow(nowScore,3);
        else if(dartResult[i]=='*'){
            nowScore*=2;
            answer+=star;
        }
        else if(dartResult[i]=='#') nowScore*=-1;  
    }
    answer+=nowScore;
    return answer;
}
