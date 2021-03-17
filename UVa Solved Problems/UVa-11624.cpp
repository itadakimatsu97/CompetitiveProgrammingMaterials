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

int R, C;
const int MS = 1001;
char Graph[MS][MS];
int fire[MS][MS];
int john[MS][MS];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void bfs_fire(vii f) {
    memset(fire, -1, sizeof fire);
    queue<ii> Q;
    Trav(it, f){
        Q.push(it);
        fire[it.fi][it.se] = 0;
    }
    while (!Q.empty()) {
        ii tmp = Q.front();
        Q.pop();
        rep(i, 0, 4) {
            int x = tmp.fi + dr[i];
            int y = tmp.se + dc[i];
            if (x < 0 || y < 0 || x >= R || y >= C) continue;
            if (fire[x][y] != -1 || Graph[x][y] == '#') continue;
            fire[x][y] = fire[tmp.fi][tmp.se] + 1;
            Q.push(mp(x, y));
        }
    }
    // rep(i, 0, R) {
    //     rep(j, 0, C) {
    //         printf("%d ", fire[i][j]);
    //     }
    //     printf("\n");
    // }
}

int bfs_john(ii J) {
    memset(john, -1, sizeof john);
    queue<ii> Q;
    Q.push(J);
    john[J.fi][J.se] = 0;
    while (!Q.empty()) {
        ii tmp = Q.front();
        Q.pop();
        if (tmp.fi == 0 || tmp.fi == R-1 || tmp.se == 0 || tmp.se == C-1) return (john[tmp.fi][tmp.se] + 1);
        rep(i, 0, 4) {
            int x = tmp.fi + dr[i];
            int y = tmp.se + dc[i];
            if (x < 0 || y < 0 || x >= R || y >= C) continue;
            if (john[x][y] != -1 || Graph[x][y] == '#') continue;
            john[x][y] = john[tmp.fi][tmp.se] + 1;
            if (john[x][y] < fire[x][y] || fire[x][y] == -1) {
                // printf("    %d %d\n", x, y);
                Q.push(mp(x, y));
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
        scanf("%d %d", &R, &C);
        // printf("%d %d\n", R, C);
        getchar();
        ii J;
        vii F;
        rep(i, 0, R) {
            rep(j, 0, C) {
                char c;
                scanf("%c", &c);
                Graph[i][j] = c;
                if (c == 'J') J = mp(i, j);
                if (c == 'F') F.pb( mp(i, j));
                // printf("%c", c);
            }
            getchar();
            // printf("\n");
        }
        bfs_fire(F);
        int result = bfs_john(J);
        if( result != -1 )
            printf("%d\n", result);
        else
            printf("IMPOSSIBLE\n");
        // break;
    }
    return 0;
}