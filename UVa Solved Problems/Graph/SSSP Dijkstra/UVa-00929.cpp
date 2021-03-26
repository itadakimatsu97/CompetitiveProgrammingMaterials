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

const int MAXS = 1000;
int N, M;
int Graph[MAXS][MAXS];
int cost[MAXS][MAXS];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int dijkstra() {
    rep(i, 0 , N)
        rep(j, 0 , M)
            cost[i][j] = INF;
    priority_queue<pair<int, ii>> PQ;
    cost[0][0] = Graph[0][0];
    PQ.push(mp(-cost[0][0], mp(0, 0)));
    while (!PQ.empty()) {
        pair<int, ii> tmp = PQ.top();
        // printf("%d  %d : %d\n", tmp.se.fi, tmp.se.se, tmp.fi);
        PQ.pop();
        int c = -tmp.fi;
        if (tmp.se.fi == N - 1 && tmp.se.se == M - 1) return c;
        rep(i, 0, 4) {
            int x = tmp.se.fi + dr[i];
            int y = tmp.se.se + dc[i];
            if (x < 0 || y < 0 || x >= N || y >= M) continue;
            if (cost[x][y] > c + Graph[x][y]) {
                cost[x][y] = c + Graph[x][y];
                PQ.push(mp(-cost[x][y], mp(x, y)));
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
    while (t--) {
        scanf("%d %d", &N, &M);
        int v;
        rep(i, 0, N) {
            rep(j, 0, M) {
                scanf("%d", &v);
                Graph[i][j] = v;
                // printf("%d ",v);
            }
            // printf("\n");
        }
        printf("%d\n", dijkstra());
    }
    return 0;
}