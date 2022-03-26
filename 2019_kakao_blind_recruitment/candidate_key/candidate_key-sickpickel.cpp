#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int row_size, col_size;
vector<vector<int>> comb;

void generatePossibleCombination(int limit, int cnt, int before, int col_size, vector<int>& tmp){
    
    if(limit == cnt){
        comb.push_back(tmp);
        return;
    }
    
    for(int i = before + 1; i < col_size; i++){
        tmp.push_back(i);
        generatePossibleCombination(limit, cnt + 1, i, col_size, tmp);
        tmp.pop_back();
    }
}

int checkMinimality(vector<int> vec, vector<vector<int>> candidateKeys){
    // 후보키의 원소들 중 vec에 포함될 수 있는게 있는지 확인하는 함수.
    // 존재한다면 0을 반환, 존재하지 않는다면 최소성을 만족하므로 1 반환.
    // std::equal 사용해서 구현.
       
    for(auto candidateKey : candidateKeys){
   		int left = 0, right = 0, samecnt = 0;
		while(left < vec.size() && right < candidateKey.size()){
			if(vec[left] < candidateKey[right]) left++;
			else if(vec[left] > candidateKey[right]) right++;
			else {
				left++; right++; samecnt++;
			}
		}
		if(samecnt == candidateKey.size()) return 0;
    } 
    return 1;
}

int checkUniqueness(vector<string> vec){
    sort(vec.begin(), vec.end());
    
    for(int i = 1; i < vec.size(); i++){
        if(vec[i - 1] == vec[i]) return 0;
    }
    return 1;
}

vector<string> combineVec(vector<int> idx, vector<vector<string>> relation){
    vector<string> ret;
    
    for(int i = 0; i < row_size; i++){
        string tmp;
        for(int j : idx){
            tmp += (relation[i][j]);
        }
        ret.push_back(tmp);
    }
    return ret;
}

void printCandiKeys(vector<vector<int>> keys){
	for(auto vec: keys){
		for(auto elem : vec){
			cout << elem << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    row_size = relation.size();
    col_size = relation[0].size();
    
    vector<int> tmp;
    vector<vector<int>> candidateKeys;
    for(int i = 1; i <= col_size; i++){
        generatePossibleCombination(i, 0, -1, col_size, tmp);
    }
    
    for(auto vec : comb){
        if(!checkMinimality(vec, candidateKeys)) continue;
        if(!checkUniqueness(combineVec(vec, relation))) continue;
        candidateKeys.push_back(vec);
    }
    cout << candidateKeys.size() << "\n"; 
    answer = candidateKeys.size();
    return answer;
}

int main(void){
	
	int n, m;
	cin >> n >> m;
	vector<vector<string>> relation;	
	for(int i = 0; i < n; i++){
		string input;
		vector<string> tmp;
		for(int j = 0; j < m; j++){
			cin >> input;
			tmp.push_back(input);	
		}
		relation.push_back(tmp);
	}
	solution(relation);
}