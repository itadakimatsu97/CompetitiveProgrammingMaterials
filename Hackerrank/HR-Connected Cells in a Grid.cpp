#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N,M;
bool visited[11][11];
int grid[11][11];
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(){
    cin >> N >> M;
    for(int i=0; i<N ; ++i){
        for(int j=0; j< M; ++j){
            cin >> grid[i][j];
        }
    }
}

bool valid(int u, int v){
    if( u < 0 || v <0 || u >=N || v>=M ) return false;
    if( visited[u][v] == true) return false;
    if( grid[u][v] == 0) return false;
    return true;
}

int bfs(int a, int b){
    int cnt = 1;
    queue<pair<int, int>> Q;
    Q.push({a,b});
    visited[a][b] = true;
    while(!Q.empty()){
        auto tmp = Q.front(); Q.pop();
        for(int i =0; i <8; ++i){
            int x = tmp.first + dr[i];
            int y = tmp.second + dc[i];
            if(valid(x,y)){
                cnt++;
                visited[x][y] = true;
                Q.push({x,y});
            }
        }
    }
    return cnt;
}

int solver(){
    memset(visited, 0, sizeof visited);
    int mm =0;
    for(int i=0; i<N ; ++i){
        for(int j=0; j< M; ++j){
            if(valid(i,j)) mm = max(mm, bfs(i,j));
        }
    }
    return mm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifdef LOCAL_JUDGE
    freopen("in", "r", stdin);
    ofstream fout("out");
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    // int TESTCASE = 1;
    // cin >> TESTCASE;
    // while(TESTCASE--){
    input();
    int ans = solver(); 
    fout << ans << "\n";
    // }
    fout.close();
    return 0;
}