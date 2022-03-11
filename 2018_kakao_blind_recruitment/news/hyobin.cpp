#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> separate(string str){
    vector<string> vec;
    for(int i=0;i<str.size();i++){
        if(str[i]>=97 && str[i]<=122 && str[i+1]>=97 && str[i+1]<=122){
            string tmp;
            tmp.push_back(str[i]);
            tmp.push_back(str[i+1]);
            vec.push_back(tmp);
        }
    }
    return vec;
}
string toLower(string str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>=65 && str[i]<=90){
            str[i]+=32;
        }
    }
    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> vec1;
    vector<string> vec2;
    str1=toLower(str1);
    str2=toLower(str2);
    vec1=separate(str1);
    vec2=separate(str2);
    sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
    
    int cross=0;
    int hap=0; //전체 개수 - 교집합 크기
    
    int i=0,j=0;
    while(true){
        if(i>=vec1.size() || j>=vec2.size()) break;
        if(vec1[i][0]==vec2[j][0]){
            if(vec1[i][1]==vec2[j][1]){
                cross++;
                i++;
                j++;
            }
            else{
                vec1[i][1]>vec2[j][1] ? j++ : i++;
            }
        }
        else{
            vec1[i][0]>vec2[j][0] ? j++ : i++;
        }
  
    }	
    hap=vec1.size()+vec2.size()-cross;
	double tmp;
	if(cross==0 && hap==0)tmp=1;
	else tmp = cross/(double)hap;
    answer=tmp*65536/1;
    return answer;
}
