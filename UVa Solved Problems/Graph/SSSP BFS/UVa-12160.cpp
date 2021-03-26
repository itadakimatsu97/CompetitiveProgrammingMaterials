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

int d[10000];
vi RV;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    int tc =1;
    while (true) {
        int L, U, R, rv;
        cin >> L >> U >> R;
        if (U == 0 && R == 0 && R == 0) break;
        RV.clear();
        cin.ignore();
        rep(i, 0, R) {
            cin >> rv;
            RV.pb(rv);
        }
        fill(d, d + 10000, INF);
        // cout << L << " " << U << " " << R << "\n";
        queue<int> Q;
        Q.push(L);
        d[L] = 0;
        while (!Q.empty()) {
            int tmp = Q.front();
            Q.pop();
            if (tmp == U) break;
            Trav(it, RV) {
                int t = (tmp + it) % 10000;
                if (d[t] == INF) {
                    d[t] = d[tmp] + 1;
                    Q.push(t);
                }
            }
        }
        cout << "Case "<<tc<<": ";
        if (d[U] == INF)
            cout << "Permanently Locked\n";
        else
            cout << d[U] << '\n';
        tc++;
            
        // cout<<d[0] << '\n';
        // break;
    }
    return 0;
}