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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

//for problem
const int MAX_V = 30;
vector<string> vetex;
map<string, vector<string>> Graph;
map<string, int> d;
int bfs(string src, string dst) {
    if (!src.compare(dst)) return 0;
    d.clear();
    queue<string> Q;
    Q.push(src);
    d[src] = 0;
    while (!Q.empty()) {
        string tmp = Q.front();
        Q.pop();
        Trav(it, Graph[tmp]) {
            // count
            if (d.count(it) == 0) {
                d[it] = d[tmp] + 1;
                if (!it.compare(dst)) return d[it];
                Q.push(it);
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
    cin >> t;
    int set = 1;
    cout << "SHIPPING ROUTES OUTPUT\n\n";
    while (t--) {
        // printf("Solution %s\n", tmp);
        int M, N, P;
        cin >> M >> N >> P;
        Graph.clear();
        string tmp1, tmp2;
        rep(i, 0, M) {
            cin >> tmp1;
            // cout << tmp1 << "\n";
            vetex.pb(tmp1);
        }
        rep(i, 0, N) {
            cin >> tmp1 >> tmp2;
            // cout << tmp1 << tmp2 << "\n";
            Graph[tmp1].pb(tmp2);
            Graph[tmp2].pb(tmp1);
        }
        cout << "DATA SET  "
             << set
             << "\n\n";
        int size;
        rep(i, 0, P) {
            cin >> size >> tmp1 >> tmp2;
            int result = bfs(tmp1, tmp2);
            if (result != -1) {
                cout << "$" << size * result * 100 << "\n";
            } else {
                cout << "NO SHIPMENT POSSIBLE\n";
            }
            //solver
        }
        cout << "\n";
        set++;
    }
    cout << "END OF OUTPUT\n";
    return 0;
}