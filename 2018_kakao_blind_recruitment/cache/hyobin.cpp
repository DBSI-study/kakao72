#include <string>
#include <vector>

using namespace std;

string lower(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]>=65 && str[i]<=90)
            str[i]+=32;
    }
    return str;
}

int find_value(string value,vector<string> vec){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==value){
            return i;
        }
    }
    return -1;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if(cacheSize==0){
        return cities.size()*5;
    }
    
    for(int i=0;i<cities.size();i++){
        cities[i]=lower(cities[i]);
        int idx=find_value(cities[i],cache);
        
        if(cache.size()<cacheSize){ // cache가 다 안채워진 경우.
            if(idx!=-1){ // cache안에 중복.
                cache.erase(cache.begin()+idx);
                answer++;
            }
            else{
                answer+=5;
            }
            cache.push_back(cities[i]);
        }
        
        else{ // cache가 다 채워진 경우.
            if(idx==-1){
                cache.erase(cache.begin());
                answer+=5;
            }
            else{
                cache.erase(cache.begin()+idx);
                answer++;
            }
            cache.push_back(cities[i]);
        }
    }
    
    return answer;
}
