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

const int MAXSIZE = 100;
int M, N;
int Graph[MAXSIZE][MAXSIZE];
int d[MAXSIZE][MAXSIZE];
ii A, B;

int horseJumpR[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horseJumpC[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool valid(int m, int n) {
    if (m < 0 || n < 0 || m >= M || n >= N) return false;
    if (Graph[m][n] == 1) return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        memset(Graph, 0, sizeof(Graph));
        cin >> M >> N;
        // cout << M << " " << N << "\n";
        char c;
        vector<ii> fill;
        rep(i, 0, M) {
            rep(j, 0, N) {
                cin >> c;
                if (c == 'Z') {
                    Graph[i][j] = 1;
                    fill.pb(mp(i, j));
                    continue;
                }
                if (c == 'A') A = mp(i, j);
                if (c == 'B') B = mp(i, j);
                Graph[i][j] = 0;
            }
        }
        // rep(i, 0, M) {
        //     rep(j, 0, N) {
        //         cout << Graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        Trav(it, fill) {
            rep(k, 0, 8) {
                int m1 = it.first + horseJumpR[k];
                int n1 = it.second + horseJumpC[k];
                if (m1 < 0 || n1 < 0 || m1 >= M || n1 >= N) continue;
                // cout <<"        "<< m1 << " " << n1 << "\n";
                Graph[m1][n1] = 1;
            }
        }
        rep(i, 0, M)
            rep(j, 0, N)
                d[i][j] = INF;
        queue<ii> Q;
        d[A.first][A.second] = 0;
        Q.push(A);
        bool finish = false;
        int step = 0;
        // cout << B.first <<" " << B.second <<"\n\n";
        while (!Q.empty() && finish != true) {
            ii tmp = Q.front();
            Q.pop();
            int r = tmp.first;
            int c = tmp.second;
            // cout << r <<" " << c <<"\n";
            // visted[r][c] = true;
            if (r == B.first && c == B.second) break;
            rep(i, 0, 8) {
                if (valid(r + dr[i], c + dc[i]) || ((r + dr[i]) == B.first && (c + dc[i]) == B.second)) {
                    if (d[r + dr[i]][c + dc[i]] == INF) {
                        d[r + dr[i]][c + dc[i]] = d[r][c] + 1;
                        Q.push(mp(r + dr[i], c + dc[i]));
                    }
                }
            }
        }
        if (d[B.first][B.second] != INF)
            cout << "Minimal possible length of a trip is " << d[B.first][B.second] << "\n";
        else
            cout << "King Peter, you can't go now!\n";
        // break;
    }
    return 0;
}