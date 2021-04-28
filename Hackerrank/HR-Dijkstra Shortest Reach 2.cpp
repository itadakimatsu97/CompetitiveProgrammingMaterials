#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N, M, S;
long d[3000+10];
map<int,int> Adjlist[3000+10]; //Abnormal testcase #7: Tracking duplicated edges


void input(){
    cin >> N >> M;
    for(int i =0; i<=N; i++) Adjlist[i].clear();
    int u, v, w;
    for(int i =0; i<M; i++){
        cin >> u >> v >> w;
        if(Adjlist[u].count(v)){    
            if (Adjlist[u][v] > w) {
                Adjlist[u][v] = w;
                Adjlist[v][u] = w;
            }
        }else{
            Adjlist[u][v] = w;
            Adjlist[v][u] = w;
        }
    }
    // for(int i =1; i<=N; i++){
    //     cout << i <<"\n";
    //     for(auto it:Adjlist[i]){
    //         cout << "   " << it.first << "\t" << it.second<<"\n";
    //     }
    // }
    cin >> S;
}

int solver(){
    fill(d, d+N+1, INT_MAX);
    priority_queue<pair<int,int>> PQ;
    d[S] = 0;
    PQ.push({-d[S],S});
    while(!PQ.empty()){
        auto t = PQ.top(); PQ.pop();
        int cost = -t.first;
        int vertex = t.second;
        for(auto it: Adjlist[vertex]){
            int v = it.first;
            auto w = it.second;
            if(d[v] > cost + w){
                d[v] = cost + w;
                PQ.push({-d[v] , v});
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
    cin >> TESTCASE;
    while(TESTCASE--){
        input();
        int ans = solver();
        for (int i = 1; i <N; ++i) {
            if(S == i) continue;
            fout << (d[i] == INT_MAX ? -1 : d[i]) << " ";
        }
        if(N==S) fout<<"\n";
        else fout << (d[N] == INT_MAX ? -1 : d[N]) << "\n";
        // fout << ans << "\n";
    }
    fout.close();
    return 0;
}