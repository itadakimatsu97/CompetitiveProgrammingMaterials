#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/****** Template of MACRO/CONSTANT *****/
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ii> vii;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define present(c, x) ((c).find(x) != (c).end())
#define Rep(i, n) for (int i = 0; i < (n); ++i)
#define Repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define For(i, a, b) for (int i = (a); i <= (b); ++i)
#define Ford(i, a, b) for (int i = (a); i >= (b); --i)
#define Trav(i,v) for(auto i: v)
#define Travd(i,v) for(auto i = (v).rbegin(); i != (v).rend(); ++i)
#define Val(a, b) typeof(b) a(b)
#define all(a) (a).begin(), (a).end()
#define rall(x) (x).rbegin, (x).rend()  //reverse traversal
#define ms(a,x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define last(a) (a)[sz(a)-1]

#define Sort(a) sort(all(a))
#define GSort(a) sort(all(a), greater<typeof(*((x).begin()))>()>)
#define Unique(v) Sort(v); (v).resize(unique(all(v)) - (v).begin())

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;} //UCLN
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; } //BCNN
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }

const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e16 + 5;
const ll MODULO = (ll)1e9 + 7; //Modulo

const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};

/*      Begin   : Declare global input        */

/*      END     : Declare global input        */
#define VISISTED true;
#define UNVISISTED false;
const int  N = 51,M = 51;
int n, m;
bool visited[N][M];
int Graph[N][M];
vii L1;
bool valid(int a, int b){
    return (a >= 0 && b >= 0 && a < n && b < m);
}
int bfs(ii S){
    queue<ii> Q;
    visited[S.fi][S.se] = VISISTED;
    Q.push(S);
    int area = 0;
    while(!Q.empty()){
        ii tmp = Q.front();
        Q.pop();
        int x = tmp.fi;
        int y = tmp.se;
        if (Graph[x][y] == 1) {
            area++;
            Graph[x][y] = 2;
            L1.pb(mp(x,y));
        } else
            continue;
        Rep(i, 4){
            if( !valid(x + dc[i], y + dc[i]) ) continue;
            if (visited[x + dr[i]][y + dc[i]] == false){
                visited[x + dr[i]][y + dc[i]] = true;
                Q.push(mp(x + dr[i], y + dc[i]));
            }
        }
    }
    return area;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
    cin >> n >> m;
    Rep(i, n){
        Rep(j, m){
            int ij;
            cin >> ij;
            Graph[i][j] = ij;
        }
    }
    bool foundL1 = false;
    Rep(i, n){
        Rep(j, m){
            if( bfs(mp(i,j)) != 0) {
                foundL1 = true;
                // cout << "found L1 " << L1.size() << "\n"; 
                break;
            }
        }
        if(foundL1) break;
    }

    int step = 0;
    int found = false;
    ms(visited, 0);
    queue<ii> Q2;
    Trav(it, L1){
        Q2.push(it);
        visited[it.fi][it.se] = VISISTED;
    }

    // Rep(i, n){
    //     Rep(j, m){
    //         cout << Graph[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    while(!Q2.empty() && found == false){
        int size = Q2.size();
        Rep(i, size){
            ii tmp = Q2.front(); Q2.pop();
            // if(Graph[tmp.fi][tmp.se] == 1) found = true;
            Rep(i, 4){
                int x = tmp.fi + dr[i];
                int y = tmp.se + dc[i]; 
                if( !valid(x, y) ) continue;
                if (visited[x][y] == false) {
                    visited[x][y] = true;
                    if(Graph[x][y] == 1) found = true;
                    Q2.push(mp(x, y));
                }
            }
        }
        if(!found) step ++ ;
    }
    cout << step;
    return 0;
}