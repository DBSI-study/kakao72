#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define Max 110

using namespace std;

const int pillar = 0, beam = 1;
int N;

typedef vector<int>(*parr)[Max];

int find(vector<int>&vec, int data){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == data) return i;
    }
    return -1;
}

int outOfRange(pair<int, int> pos){
    int y = pos.first, x = pos.second;
    return y < 0 || y > N || x < 0 || x > N;
}

int isType(pair<int, int> pos, int type, parr board){
    vector<int>& ref1 = board[pos.first][pos.second];
    vector<int>& ref2 = board[pos.first + (type == pillar)][pos.second + (type == beam)];
    if(find(ref1, type) >= 0 && find(ref2, type) >= 0) return 1;
    return 0;
}

int isPillar(pair<int, int> pos, parr board){
    if(outOfRange(pos)) return 0;
    return isType(pos, pillar, board);     
}

int isBeam(pair<int, int> pos, parr board){
    if(outOfRange(pos)) return 0;
    return isType(pos, beam, board);
}

int canDemolish(pair<int, int> pos, int type, parr board){
    pair<int, int> newPos;
    if(type == pillar){
        newPos = {pos.first+1, pos.second-1};
        if(isBeam(newPos, board)) 
            if(!(isPillar({pos.first, newPos.second}, board) 
                 || isBeam({newPos.first, newPos.second - 1}, board))) return 0;
        newPos = {pos.first + 1, pos.second};
        if(isBeam(newPos, board)) 
            if(!(isPillar({pos.first, pos.second + 1}, board)
                || isBeam({newPos.first, newPos.second + 1}, board))) return 0;
        newPos = {pos.first + 1, pos.second};
        if(isPillar(newPos, board)) 
            if(!(isBeam(newPos, board)||isBeam({newPos.first, newPos.second-1}, board))) return 0;
    }
    else{
        if(isPillar(pos, board)){
            if(!(isBeam({pos.first, pos.second-1}, board) 
                    || isPillar({pos.first-1,pos.second},board))) return 0;
        }
        newPos = {pos.first,pos.second+1};
        if(isPillar(newPos, board)){
            if(!(isBeam(newPos, board) 
                    || isPillar({newPos.first-1,newPos.second},board))) return 0;
        }
        newPos = {pos.first, pos.second-1};
        if(isBeam(newPos, board)){
            if(!(isPillar({newPos.first-1,newPos.second}, board)
                   || isPillar({pos.first-1, pos.second}, board))) return 0;
        }
        newPos = {pos.first, pos.second+1};
        if(isBeam(newPos, board)){
            if(!(isPillar({newPos.first-1,newPos.second}, board)
                   || isPillar({newPos.first-1, newPos.second+1}, board))) return 0;
        }
    }
    return 1;
}

int canBuild(pair<int, int> pos, int type, parr board){
    vector<int>& ref = board[pos.first][pos.second];
    vector<int>& refRight = board[pos.first][pos.second + 1];
    if(type == pillar){
        if(pos.first == 0) return 1;
        if(ref.size() > 0) return 1;
    }
    else{
        if(find(ref, pillar) >= 0 || find(refRight,pillar) >= 0) return 1;
        if(find(ref,beam) >= 0 && find(refRight,beam) >= 0) return 1;
    }
    return 0;
}

void demolish(pair<int, int> pos, int type, parr board){
    vector<int>& ref = board[pos.first][pos.second];
    ref.erase(ref.begin() + find(ref, type));
    ref = board[pos.first + (type == pillar)][pos.second + (type == beam)];
    ref.erase(ref.begin() + find(ref, type));
}

void build(pair<int, int> pos, int type, parr board){
    board[pos.first][pos.second].push_back(type);
    board[pos.first + (type == pillar)][pos.second + (type == beam)].push_back(type);
}

void printBoard(parr board){
    for(int i = N; i >= 0; i--){
        for(int j = 0; j <= N; j++){
            cout << board[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> board[Max][Max];    
    N = n;
        
    for(auto cmd : build_frame){
        pair<int, int> pos = {cmd[1], cmd[0]};
        int type = cmd[2];
        if(cmd[3]){
            if(canBuild(pos, type, board)) {
                build(pos, type, board);
            }
        }
        else{
            if(canDemolish(pos, type, board)) {
                demolish(pos, type, board);
            }
        }
        if(board[0][2].size() == 2) cout << "[" << cmd[0] << " " << cmd[1] << " " << cmd[2] << " " << cmd[3] << "]\n";
        printBoard(board);
    }
    // board 탐색하면서 존재하는 구조물 answer에 넣어주기
    for(int i = 0; i <= n; i++){ 
        for(int j = 0; j <= n; j++){
            vector<int> tmp(3);
            tmp[1] = i; tmp[0] = j;
            if(isPillar({i, j}, board)) {
                tmp[2] = 0;
                answer.push_back(tmp);
            }
            if(isBeam({i, j}, board)){
                tmp[2] = 1;
                answer.push_back(tmp);               
            }
        }
    }
    
    printBoard(board);
    sort(answer.begin(), answer.end());
    return answer;
}