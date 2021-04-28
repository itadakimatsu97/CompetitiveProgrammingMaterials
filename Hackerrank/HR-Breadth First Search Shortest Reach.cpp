#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N, M;
int d[1000+10];
map<int, vector<int>> Adjlist;


void input(){
    Adjlist.clear();
    cin >> N >> M;
    int u, v;
    for(int i=0; i<M; ++i){
        cin >> u >> v;
        Adjlist[u].push_back(v);
        Adjlist[v].push_back(u);
    }
}

void solver(int start){
    memset(d, -1, sizeof d);
    queue<int> Q;
    Q.push(start);
    d[start] = 0;
    while(!Q.empty()){
        int t = Q.front(); Q.pop();
        for(auto it : Adjlist[t]){
            if(d[it] != -1) continue;
            d[it] = d[t] + 6;
            Q.push(it);
        }
    }
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
        int s;
        cin >> s;
        solver(s); 
        for(int i = 1; i<N; ++i){
            if(i==s) continue;
            fout << d[i] <<" ";
        }
        if(N==s) fout <<"\n";
        else fout << d[N]<<"\n";
        // fout << ans << "\n";
    }
    fout.close();
    return 0;
}