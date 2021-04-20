#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef vector<int> vi;
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
#define all(a) (a).begin(), (a).end()
#define rall(x) (x).rbegin(), (x).rend()  //reverse traversal
#define ms(a,x) memset(a, x, sizeof(a))
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
const ll MOD = (ll)1e9 + 7; //Modulo

// const int dr[] = {-1, 0, +1, 0};
// const int dc[] = {0, +1, 0, -1};
const int dr[] = {-1, -1,  0, 0, 1, 1};
const int dc[] = {-1,  0, -1, 1, 0, 1};

/*      Begin   : Declare global input        */
int N;
char Board[201][201];
bool visited[201][201];
/*      END     : Declare global input        */

bool notValid(int a, int b){ //
    return ( a <0 || b < 0 || a >= N ||b >= N);
}

bool bfs(int x, int y){ //check W
    queue<ii> Q;
    Q.push(mp(x,y));
    visited[x][y] = 1;
    bool first= false, last = false;
    while(!Q.empty()){
        ii tmp = Q.front(); Q.pop();
        if(tmp.first == 0) first = true;
        if(tmp.first == N-1) last = true;
        if(first&&last) return true;
        Rep(i, 6){
            int xt = tmp.first + dr[i];
            int yt = tmp.second + dc[i];
            if(!notValid(xt, yt)){
                if((Board[xt][yt] == 'b') && (visited[xt][yt] ==0)){
                    visited[xt][yt] = 1;
                    Q.push(mp(xt, yt));
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    while(true){
        cin >> N;
        if(!N) break;
        char ci;
        Rep(i, N){
            Rep(j, N){
                cin >> ci;
                Board[i][j] = ci;
            }
        }
        ms(visited,0);

        bool Bwin = false;

        //Có thể tối ưu hơn nếu chỉ cho duyệt các phần tử của col 0 và check reaching to col N-1
        Rep(i, N){
            Rep(j, N){
                if(Board[i][j] == 'b') {
                    // cout << "   " <<i <<"    "<<j <<'\n';
                    Bwin = bfs(i,j);
                }
                if(Bwin) break;
            }
            if(Bwin) break;
        }
        cout << tc++ << " "<< (Bwin?"B":"W") << "\n";
    }
    return 0;
}