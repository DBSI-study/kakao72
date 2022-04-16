#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size());
    int start,end,cnt;
    for(int i=0;i<queries.size();i++){
        cnt=0;
        for(int j=0;j<queries[i].size();j++)
            if(queries[i][j]=='?') cnt++;
        
        if(cnt==queries[i].size()){ // 쿼리가 ?로만 이루어진 경우.
            for(int k=0;k<words.size();k++){
                if(words[k].size()==cnt)
                    answer[i]++;
            }
            continue;
        }
        
        else if(queries[i][0]=='?'){
            start=cnt;
            end=queries[i].size()-1;
        }
        else{
            start=0;
            end=queries[i].size()-cnt-1;
        }
        string tmp=queries[i].substr(start,end-start+1);
        for(int j=0;j<words.size();j++){
            if(words[j].size()!=queries[i].size())
                continue;
            bool check=true;
            for(int k=start;k<end+1;k++){
                if(words[j][k]!=tmp[k-start])
                    check=false;
            }
            if(check) answer[i]++;    
        }
    }
    return answer;
}
