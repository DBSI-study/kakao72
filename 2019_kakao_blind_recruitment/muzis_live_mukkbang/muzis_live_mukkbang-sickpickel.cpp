#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define INF 100000000l

using namespace std;

typedef long long ll;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    ll food_times_sum = 0;
    vector<pair<ll, int>> vec;
    for(int i = 0; i < food_times.size(); i++){
        food_times_sum += food_times[i];
        vec.push_back({food_times[i], i});
    }
    if(food_times_sum < k) return -1;
    
    sort(vec.begin(), vec.end());
    ll nowHeight = vec[0].first, beforeHeight = 0, sum = 0; 
    vec.push_back({INF, 0});
    
    for(int i = 1; i < vec.size(); i++){
        ll tmp;
        if(vec[i].first != nowHeight) {
            tmp = (nowHeight - beforeHeight) * (ll)(food_times.size() - i + 1);
            sum += tmp;
            beforeHeight = nowHeight;
            nowHeight = vec[i].first;
        }
        if(sum >= k){
            
            break;
        }
    }
    return answer;
}