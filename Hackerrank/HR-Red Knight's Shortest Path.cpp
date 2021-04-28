#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string dir[6] = {"UL", "UR", "R", "LR", "LL", "L"};
int dr[6] = {-2, -2, 0, 2, 2, 0};
int dc[6] = {-1, 1, 2, 1, -1, -2};
int N, is, js, ie, je;
int type[210][210];
int d[210][210];
vector<string> result;

void input(){
    cin >> N >> is >> js >> ie >> je;
}

bool valid(int a, int b){
    if( a <0 || b<0 || a >=N || b>= N) return false;
    if(d[a][b] != -1) return false;
    return true;
}
int solver(){
    memset(d, -1, sizeof d);
    queue<pair<int,int>> Q;
    Q.push({is,js});
    d[is][js] = 0;
    while(!Q.empty()){
        auto tmp = Q.front(); Q.pop();
        int x = tmp.first;
        int y = tmp.second;
        if(x == ie && y == je) {
            result.clear();
            while(x != is || y != js){
                // cout << x << " " << y <<"\n";
                int t = type[x][y];
                result.push_back(dir[t]);
                x -= dr[ t ];
                y -= dc[ t ];
            }
            reverse(result.begin(), result.end());
            return d[ie][je];
        }
        for (int i = 0; i < 6; i++) {
            x = tmp.first + dr[i];
            y = tmp.second + dc[i];
            if(!valid(x,y)) continue;
            Q.push({x,y});
            type[x][y] = i;
            d[x][y] = d[tmp.first][tmp.second] +1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifdef LOCAL_JUDGE
    freopen("in", "r", stdin);
    ofstream fout("./out");
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    int TESTCASE = 1;
    // cin >> TESTCASE;
    while(TESTCASE--){
        input();
        int ans = solver(); 
        if(ans == -1) fout << "Impossible" << "\n";
        else{
            fout << ans << "\n";
            for(auto it : result) fout << it << " ";
            cout << "\n";
        }
    }
    fout.close();
    return 0;
}