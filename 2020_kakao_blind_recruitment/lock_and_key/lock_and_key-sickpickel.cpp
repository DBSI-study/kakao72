#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rotateVecRight(vector<vector<int>> vec){
   	vector<vector<int>> ret; 
    ret.assign(vec.size(), vector<int>(vec.size()));
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[0].size(); j++){
            ret[j][vec.size() - i - 1] = vec[i][j];
        }
    }
    return ret;
}

bool doesItFit(vector<vector<int>> key, vector<vector<int>> lock){
    int N = lock.size(), M = key.size();
   	for(int addy = M - 1; addy > -N; addy--) {
        for(int addx = M - 1; addx > -N; addx--){
            int flag = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    int keyWay = 0;
                    if(addy + i >= M || addy + i < 0 || addx + j >= M || addx + j < 0) keyWay = 0;
                    else keyWay = key[addy + i][addx + j];
                    if(lock[i][j] == keyWay) { flag = 1; break; }
                }
                if(flag) break;
            }
            if(flag == 0) return 1;
        }
    }
    return 0;
}

void printKey(vector<vector<int>> key){
    for(auto vec : key){
        for(auto elem : vec){
            cout << elem << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
  	for(int i = 0; i < 4; i++){
       printKey(key);   
       if(doesItFit(key, lock)) { answer = true; break; }
       key = rotateVecRight(key);
    }
    return answer;
}