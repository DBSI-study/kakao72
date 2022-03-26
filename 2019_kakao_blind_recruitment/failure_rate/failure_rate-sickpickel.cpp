#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
	double save[501] = {};
	double sum = 0;
	
	for(int i = 0; i < stages.size(); i++){
		save[stages[i]]++;
	}
	
	vector<pair<double, int>> temp;
	
	for(int i = N + 1; i >= 1; i--){
		sum += save[i];
		if(i > N) continue;
		temp.push_back({save[i] / sum, -i});
	}
	
	sort(temp.begin(), temp.end(), greater<pair<double, int>>());
	for(auto elem : temp){
		answer.push_back(-elem.second);
		// cout << -elem.second << " ";
	}
    return answer;
}