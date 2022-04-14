#include <string>
#include <vector>
using namespace std;

int m, n;

void keys(vector<vector<int>> &key) {
    vector<vector<int>> rotate(m, vector<int>(m, 0));
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            rotate[i][j] = key[m-j-1][i];
        }
    }
    key = rotate;
}

bool check(vector<vector<int>> board, vector<vector<int>> key, int y, int x) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            board[i+y][j+x] += key[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i+m-1][j+m-1] != 1) {
                return false;
            }
        }
    }    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    m = key.size();
    n = lock.size();
    vector<vector<int>> board(2*m+n-1, vector<int>(2*m+n-1, 1));
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            board[i+m-1][j+m-1] = lock[i][j];
        }
    }    
    
    for(int r=0; r<4; r++) {
        for(int i=0; i<=m+n-1; i++) {
            for(int j=0; j<=m+n-1; j++) {
                if(check(board, key, i, j))
                    return true;
            }
        }
        keys(key);
    }
    return false;
}
