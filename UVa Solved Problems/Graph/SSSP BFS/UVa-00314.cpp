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

#define VISISTED
//DIR S-N-E-W
const int M = 50;
const int N = 50;
int R, C;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int Graph[M][N];
bool visisted[M][N][4];  //4 direction
struct Node {
    int r, c;
    int curDir;
    int dist;
    Node(int R, int C, int Cur, int D) : r(R), c(C), curDir(Cur), dist(D) {}
};

bool posOkay(int r, int c) {
    if (r <= 0 || c <= 0 || r >= R || c >= C) return false;
    if (Graph[r][c] == 1) return false;
    if (Graph[r-1][c] == 1) return false;
    if (Graph[r][c-1] == 1) return false;
    if (Graph[r-1][c-1] == 1) return false;

    return true;
}

int bfs(int srcR, int srcC, int destR, int destC, int dir) {
    rep(i, 0, N)
        rep(j, 0, M)
            rep(k, 0, 4)
                visisted[i][j][k] = false;
    if (!posOkay(destR, destC)) return -1;
    queue<Node> Q;
    Q.push(Node(srcR, srcC, dir, 0));
    visisted[srcR][srcC][dir] = true;
    while (!Q.empty()) {
        Node tmp = Q.front();
        Q.pop();
        int r = tmp.r;
        int c = tmp.c;
        int cd = tmp.curDir;
        int d = tmp.dist;

        if (!posOkay(r, c)) continue;
        // cout << "Pos R: " << r << " Pos C: " << c << " Dir: " << cd << " Dist: " << d << "\n";

        if (r == destR && c == destC) return d;
        if (visisted[r][c][(cd + 1) % 4] == false) {  //turn left
            visisted[r][c][(cd + 1) % 4] = true;
            Q.push(Node(r, c, (cd + 1) % 4, d + 1));
        }
        if (visisted[r][c][(cd + 3) % 4] == false) {  //turn right
            visisted[r][c][(cd + 3) % 4] = true;
            Q.push(Node(r, c, (cd + 3) % 4, d + 1));
        }
        rep(i, 1, 4) { //go ahead
            if (!posOkay(r + dr[cd] * i, c + dc[cd] * i)) break;
            if (visisted[r + dr[cd] * i][c + dc[cd] * i][cd] == true) continue;
            visisted[r + dr[cd] * i][c + dc[cd] * i][cd] = true;
            // cout << "   Add Pos R: " << r + dr[cd] * i << " Pos C: " << c + dc[cd] * i << " Dir : " << cd << " Dist: " << d + 1 << "\n";
            Q.push(Node(r + dr[cd] * i, c + dc[cd] * i, cd, d + 1));
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
    // scanf("%d", &t);
    string input;
    stringstream ss;
    while (getline(cin, input)) {
        ss.clear();
        ss << input;
        ss >> R >> C;
        // cout << R << C << "\n";
        if (R * C == 0) break;
        // break;
        rep(i, 0, R) {
            // ss.clear();
            // getline(cin, input);
            // ss << input;
            rep(j, 0, C) {
                int v;
                cin >> v;
                Graph[i][j] = v;
                // cout <<i <<" "<<j<<" "<< Graph[i][j] << "\n";
            }
        }
        ii src, dest;
        int dir;
        string firstCur;
        cin >> src.first >> src.second >> dest.first >> dest.second >> firstCur;
        // cout << src.first << " "
        //      << src.second << " "
        //      << dest.first << " "
        //      << dest.second << " "
        //      << firstCur << "\n";
        //solver
        cin.ignore();
        if (firstCur[0] == 's') dir = 0;
        if (firstCur[0] == 'e') dir = 1;
        if (firstCur[0] == 'n') dir = 2;
        if (firstCur[0] == 'w') dir = 3;
        // rep(i, 0, R) {
        //     rep(j, 0, C) {
        //         cout << Graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << bfs(src.first, src.second, dest.first, dest.second, dir) <<"\n";

        // printf("Solution %d\n", S.first);
    }
    return 0;
}