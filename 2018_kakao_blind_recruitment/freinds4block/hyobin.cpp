#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    vector<vector<char>> map(n,vector<char>(m,'0'));
    int answer = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            map[j][i]=(board[i][j]);
        }
    }

    bool no_exit_flag=true;
    while(no_exit_flag){
        bool check[31][31]={};
        no_exit_flag=false;
		
        for(int i=0;i<m-1;i++){ // 제거할 블록 표시
            for(int j=0;j<n-1;j++){
                if(map[j][i]!='X' && map[j][i]==map[j+1][i] &&  map[j+1][i]==map[j][i+1] &&  map[j][i+1]==map[j+1][i+1]){
					check[j][i]=check[j+1][i]=check[j][i+1]=check[j+1][i+1]=true;
                    no_exit_flag=true;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check[j][i]){
                    map[j].erase(map[j].begin()+i);
                    map[j].insert(map[j].begin(),'X');
                    answer++;
                }
            }
        }
    }
    
    return answer;
}
