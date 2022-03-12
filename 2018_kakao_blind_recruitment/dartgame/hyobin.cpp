#include <string>
#include <vector>
#include <cmath>

using namespace std;

string toBinary(int n, int x){
    string ans;
    for(int i=n-1;i>=0;i--){
        int tmp=pow(2,i);
        if(x>=tmp){
            ans+='1';
            x-=tmp;
        }
        else ans+='0';
    }
    return ans;
}

string comp(int n, string x, string y){
    string ans;
    for(int i=0;i<n;i++){
        if(x[i]=='1' || y[i]=='1')
            ans+='#';
        else ans+=' ';
    }
    return ans;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<n;i++){
        string x=toBinary(n,arr1[i]);
        string y=toBinary(n,arr2[i]);
        string tmp=comp(n,x,y);
        answer.push_back(tmp);
        
    }
    return answer;
}
