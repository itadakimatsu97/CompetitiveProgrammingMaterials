#include <bits/stdc++.h>

#include <algorithm>

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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;
typedef map<int, vector<int>> mivi;

const int MAXC = 101;

// struct Node{
//     int cost = INF
// }
int N, E, T, M;
int d[MAXC];
vector<ii> Edges[MAXC];

int dijkstra( int dest) {
    fill(d, d+N+1, INF);
    priority_queue<ii> PQ;
    d[dest] = 0;
    PQ.push(mp(-d[dest], dest));
    // printf("Dest %d:    T: %d\n",dest, T);
    while (!PQ.empty()) {
        ii tmp = PQ.top();
        PQ.pop();

        Trav(it, Edges[tmp.se]){
            if( d[it.fi] > d[tmp.se] + it.se){
                d[it.fi] = d[tmp.se] + it.se;
                PQ.push(mp(-d[it.fi], it.fi));
            }
        }

    }
    int count = 0;  //1 mice at dest always exit at cost = 0;
    REP(i, 0, N) {
        // printf("    %d\n", d[i]);
        if (d[i] <= T) count++;
    }
    return count;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &N, &E, &T, &M);
        // printf("%d %d %d %d\n",N, E, T, M);
        REP(i,0,N) Edges[i].clear();
        rep(i, 0, M) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            // printf("%d %d %d\n",u, v, w);
            Edges[v].pb(mp(u, w));
        }
        // REP(i,0,N){
        //     printf("Vertex:%d \n", i);
        //     Trav(it, Edges[i]) {
        //         // printf("    %d %d\n", it.first, it.second);
        //     }
        // }
        printf("%d\n", dijkstra(E));
        if(t) printf("\n");
    }
    return 0;
}