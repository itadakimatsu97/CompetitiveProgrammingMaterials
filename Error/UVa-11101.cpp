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

const int MAXS = 2000;
int Mall2[MAXS][MAXS];
bool v[MAXS][MAXS];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d", &t);
    while (true) {
        memset(Mall2, 0, sizeof(Mall2));
        memset(v, 0, sizeof(v));
        queue<ii> Q;
        int n, x, y;
        scanf("%d", &n);
        if (n == 0) break;
        rep(i, 0, n) {
            scanf("%d %d", &x, &y);
            Q.push(mp(x, y));
            v[x][y] = true;
        }
        scanf("%d", &n);
        rep(i, 0, n) {
            scanf("%d %d", &x, &y);
            Mall2[x][y] = 1;
        }
        bool stop = false;
        int footstep = 0;
        while (!stop) {
            int len = Q.size();
            rep(i, 0 ,len){
                ii tmp = Q.front(); Q.pop();
                if (Mall2[tmp.first][tmp.second] == 1) stop = true;;
                rep(i, 0, 4) {
                    if (tmp.first + dr[i] < 0 || tmp.second + dc[i] < 0 || tmp.first + dr[i] >= MAXS || tmp.second + dc[i] >= MAXS) continue;
                    if (v[tmp.first + dr[i]][tmp.second + dc[i]] == false) {
                        v[tmp.first + dr[i]][tmp.second + dc[i]] = true;
                        Q.push(mp(tmp.first + dr[i], tmp.second + dc[i]));
                    }
                }
            }
            if(!stop) footstep++;
        }
        printf("%d\n", footstep);
    }
    return 0;
}