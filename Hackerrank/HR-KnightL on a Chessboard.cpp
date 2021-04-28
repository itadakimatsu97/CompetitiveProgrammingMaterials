#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N;
int d[30][30];

void input(){
    cin >> N;
}
bool valid(int u, int v){
    if ( u<0 || v < 0 || u  >= N || v >= N) return false;
    if (d[u][v] != -1) return false;
    return true;
}

int solver(int a, int b){
    const int dr[]={-a,a,-a,a,-b,b,-b,b};
    const int dc[]={b,b,-b,-b,-a,-a,a,a};
    memset(d, -1, sizeof d);
    queue<pair<int,int>> Q;
    d[0][0]=0;
    Q.push({0,0});
    while(!Q.empty()){
        auto tmp = Q.front(); Q.pop();
        int x = tmp.first;
        int y = tmp.second;
        if( x==N-1 && y == N-1) return d[N-1][N-1];
        for(int i = 0; i <8 ; ++i){
            int x1 = x + dr[i];
            int y1 = y + dc[i];
            if(valid( x1, y1) ){
                Q.push( {x1, y1} ); d[x1][y1] = d[x][y]+1;
            }
        }
    }
    return -1;
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

    int TESTCASE = 1;
    // cin >> TESTCASE;
    while(TESTCASE--){
        input();
        for(int i=1; i<N ; ++i){
            for(int j=1; j<N ; ++j){
                int ans = solver(i, j); 
                fout << ans << " ";
            }
            fout << "\n";
        }
    }
    fout.close();
    return 0;
}