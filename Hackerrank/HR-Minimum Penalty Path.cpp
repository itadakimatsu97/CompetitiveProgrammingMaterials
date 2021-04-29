#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int N, M, S, E;
int d[1000+10][1024];
map<int, vector<pair<int, int>>> Adjlist;

void input(){
    cin >> N >> M;
    int u, v, w;
    for(int i=0; i < M; ++i){
        cin >> u >> v >> w; //an undirected graph
        Adjlist[u].push_back({v,w});
        Adjlist[v].push_back({u,w});
    }
    cin >> S >> E;
}

int solver(){
    memset(d, -1, sizeof d);
    priority_queue<pair<int,int>> PQ;
    d[S][0] = 0;
    PQ.push({0,S});
    while (!PQ.empty()){
        int cost = -PQ.top().first;
        int u = PQ.top().second;
        PQ.pop();
        // cout << u << "  " << cost << "\n";
        if(u == E) return cost;
        for(auto v: Adjlist[u]){
            // cout << "   "<< v.first << "  " << v.second << "\n";
            int neww = (cost|v.second);
            if(d[v.first][neww] == -1){
                d[v.first][neww] = neww;
                PQ.push({-d[v.first][neww], v.first});
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
        int ans = solver(); 
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}