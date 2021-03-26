#include <bits/stdc++.h>
using namespace std;

/****** Template of MACRO/CONSTANT *****/
#define INF INT_MAX
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()   //Forward traversal
#define rall(x) (x).rbegin, (x).rend()  //reverse traversal
#define present(c, x) ((c).find(x) != (c).end())
#define sz(x) (x.size())
#define rep(i, from, end) for (int i = from; i < end; i++)
#define REP(i, from, end) for (int i = from; i <= end; i++)
#define Trav(it, x) for (auto it : x)
#define TRAV(it, x) for (auto it = (x).begin(); it != (x).end(); it++)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

#define NC_MAX 30
#define VISITED true
#define UNVISITED false
map<int, vector<int>> Graph;
map<int, int> d;
map<int, bool> visited;

void bfs(int s) {
    Trav(it, Graph) {
        d[it.first] = INT_MAX;
        visited[it.first] = UNVISITED;
    }
    queue<int> Q;
    d[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int tmp = Q.front();
        Q.pop();
        if (visited[tmp] == UNVISITED) visited[tmp] = VISITED;
        Trav(it, Graph[tmp]) {
            if (visited[it] == UNVISITED) {
                Q.push(it);
                if(d[tmp] + 1 < d[it])
                    d[it] = d[tmp] + 1;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d", &t);
    // while (t--) {
    int tc = 1;
    while (1) {
        // printf("Solution %d\n", t);
        int NC;
        int u, v;
        int start = INF, ttl = INF;
        Graph.clear();
        scanf("%d", &NC);
        if (NC == 0) break;

        int pos = 0;
        rep(i, 0, NC) {
            scanf("%d %d", &u, &v);
            Graph[u].pb(v);
            Graph[v].pb(u);
        }
        // printf("size V %d\n", Graph.size());
        // Trav(it, Graph){
        //     printf("Vertex %d: ", it.first);
        //     Trav(i, it.second){
        //         printf(", %d ", i);
        //     }
        //     printf("\n");
        // }
        while (1) {
            scanf("%d %d", &start, &ttl);
            if(start == 0 && ttl == 0) break;
            d.clear();
            visited.clear();
            bfs(start);
            // int result =0;
            // Trav(it, d)
            //     if(it.second > ttl) result++;
            int result = count_if(all(d), [&ttl ](auto i){return i.second> ttl;});  
            // Count distance > ttl
            // For C++14 or higher, "auto" is not supported in C++11
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc, result, start, ttl);
            tc++;
            // Trav(it, d) {
            //     printf("Distance from %d to %d : %d\n", start, it.first, it.second);
            // }
        }
    }
    return 0;
}