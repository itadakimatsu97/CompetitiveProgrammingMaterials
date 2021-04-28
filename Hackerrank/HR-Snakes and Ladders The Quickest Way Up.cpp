#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int d[101];
map<int,int> events;
map<int, vector<int>> Adjlist;

void input(){
    Adjlist.clear();
    events.clear();
    int n, u, v, run =2; 
    while(run--){
        cin >>n;
        for(int j=0; j<n; ++j){
            cin >> u >> v;
            events[u] = v;
        }
    }
    for(int i= 1; i < 100; i++){
        if(Adjlist.count(i)) continue;
        for(int j =1 ; j <=6; j++){
            int next = i+j;
            if (next <= 100) {
                if(events.count(next))
                    Adjlist[i].push_back(events[next]);
                else
                    Adjlist[i].push_back(next);
            }
        } 
    }
}

int solver(){
    fill(d, d+101, INT_MAX);
    queue<int> Q;
    d[1]=0;
    Q.push(1);
    while(!Q.empty()){
        int t = Q.front(); Q.pop();
        if(t == 100) return d[100];
        for(auto it : Adjlist[t]){
            if(d[it] > d[t] + 1){
                d[it] = d[t] + 1;
                Q.push(it);
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
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}