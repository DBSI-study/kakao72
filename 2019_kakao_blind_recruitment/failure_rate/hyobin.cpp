#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<double,int>a, pair<double,int>b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    else{
        return a.first>b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int bunza[502]={0,};
    int bunmo[502]={0,};
    vector<pair<double,int>> percent(N);

    for(int i=stages.size()-1;i>=0;i--){
        bunza[stages[i]]++;
    }

    for(int i=N+1;i>0;i--){
        bunmo[i]=bunza[i]+bunmo[i+1];
    }

    for(int i=0;i<N;i++){
        if(bunmo[i+1]==0){
            percent[i]={0,i+1};
        }
        else{
            percent[i]={(double)bunza[i+1]/(double)bunmo[i+1],i+1};
        }
    }

    sort(percent.begin(),percent.end(),compare);
    
    for(int i=0;i<N;i++){
        answer.push_back(percent[i].second);
    }
    
    return answer;
}
