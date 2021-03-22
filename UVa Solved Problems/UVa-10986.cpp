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

const int SIZE = 20000;
int n, m, S, T;
vii Graph[SIZE];
int d[SIZE];

int dijkstra(int start, int end) {
    d[start] = 0;
    priority_queue<ii> PQ;
    PQ.push(mp(0, start));
    while (!PQ.empty()) {
        ii tmp = PQ.top();
        PQ.pop();
        int cost = -tmp.fi;
        if (tmp.se == end) return cost;
        Trav(it, Graph[tmp.se]) {
            if (d[it.fi] > cost + it.se) {
                d[it.fi] = cost + it.se;
                PQ.push(mp(-d[it.fi], it.fi));
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    scanf("%d", &t);
    int tc = 1;
    while (t--) {
        // printf("Solution %d\n", );
        scanf("%d %d %d %d", &n, &m, &S, &T);
        rep(i, 0, n) {
            Graph[i].clear();
            d[i] = INF;
        }
        int u, v, w;
        rep(i, 0, m) {
            scanf("%d %d %d", &u, &v, &w);
            Graph[u].pb(mp(v, w));
            Graph[v].pb(mp(u, w));
        }
        int ans = dijkstra(S, T);
        if (ans != -1)
            printf("Case #%d: %d\n", tc, ans);
        else
            printf("Case #%d: unreachable\n", tc);
        tc++;
        // printf("%d %d %d %d\n", n, m, S, T);
    }
    return 0;
}