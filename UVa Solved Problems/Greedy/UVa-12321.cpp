#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

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
// template<typename ...Args> void log(Args && ...args){(std::cout << ... << args);}
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e16 + 5;
const ll MODULO = (ll)1e9 + 7; //Modulo

const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};

/*      Begin   : Declare global input        */
int L, G,  xi, ri;
struct Interval {
    int left, right;
    Interval(){}
    Interval(int a, int b){
        left = a;
        right = b;
    }
    inline bool operator<(Interval const &that) const{
        return left < that.left;
    }
};
vector<Interval> GS;
/*      END     : Declare global input        */




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    while(true){
        cin >> L >> G;
        if((L+G) == 0) break;
        // cout << L << " " << G << '\n';
        GS.clear();
        // ms(road, 0);
        int x1, x2;
        Rep(i, G){
            cin >> xi >> ri;
            // cout << "   "<<xi << " " << ri << '\n';
            // x1 = (xi-ri) < 1 ? 1 : (xi-ri);
            x1 = (xi-ri) ;
            // x2 = (xi+ri) > L ? L : (xi+ri);
            x2 = (xi+ri) ;
            // cout << "   "<<x2-x1+1 << "\t" << x1 << "\t" << x2 << "\n";
            GS.pb(Interval(x1, x2));
        }
        sort(all(GS));
        // Trav(it, GS){
        //     cout << "\t" << it.left << "\t" << it.right << "\n";
        // }
        int pos = 0,aux,i = 0,ans = G;
        
        while(pos < L){
            aux = pos;
            // cout << "\tPos " << aux << " i "<< i<<   '\n'; 
            while (i < G && GS[i].left <= pos) {
                // cout << "\t\tI "<< i << "   " << aux << "\n";
                aux = max(aux, GS[i++].right);
            }

            if(aux == pos) break;
            
            pos = aux;
            --ans;
        }
        cout << (pos < L? -1 : ans) << '\n';
        // log((pos < L? -1 : ans));
            
    }

    return 0;
}