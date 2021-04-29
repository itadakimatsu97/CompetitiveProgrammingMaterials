#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N, M, S;
int d[200000+10];
map<pair<int,int>, int> Edges; // if {u,v} in Graph -> Edges[{u,v}]++;

void input(){
    cin >> N >> M;
    Edges.clear();
    int u,v;
    for(int i =0; i< M; ++i){
        cin >> u >> v;
        //Undirected graph
        Edges[{u,v}]++; Edges[{v,u}]++;
    }
    cin >> S;
}

int solver(){ //bfs in a complement graph
    set<int> unVisited;
    for(int i =1; i <=N; ++i){
        unVisited.insert(i);
        d[i] = INT_MAX;
    }

    queue<int> Q;
    Q.push(S);
    d[S] = 0;
    unVisited.erase(S);

    while ( unVisited.size() && !Q.empty() ) {
        int tmp = Q.front(); Q.pop();
        vector<int> complementVertex;
        for(int v : unVisited){
            // if( !Edges.count({tmp,v}) && !Edges.count({v,tmp})) //For directed Graph
            if( !Edges.count({tmp,v}) ){ //For undirected Graph
                complementVertex.push_back(v);
            } 
        }
        for(int it: complementVertex){
            if(d[it] > d[tmp] + 1){
                d[it] = d[tmp] + 1;
                Q.push(it);
            }
            unVisited.erase(it);
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
        // int ans = solver(); 
        solver(); 
        for(int i =1; i <=N; ++i)
            if(d[i]) fout << d[i] << " ";
        fout << "\n";
    }
    fout.close();
    return 0;
}