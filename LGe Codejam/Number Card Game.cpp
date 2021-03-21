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
#define Trav(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Travd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define ms(a, x) memset(a, x, sizeof(a))
#define Val(a, b) typeof(b) a(b)
#define all(a) (a).begin(), (a).end()
#define rall(x) (x).rbegin, (x).rend()  //reverse traversal
#define ms(a,x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define last(a) (a)[sz(a)-1]

#define Sort(a) sort(all(a))
#define GSort(a) sort(all(a), greater<typeof(*((x).begin()))>()>)
#define Unique(v) Sort(v); (v).resize(unique(all(v)) - (v).begin())
#define Enum(v) Trav(it, (v)) cout << *it << " "; cout << endl

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
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e16 + 5;
const ll MOD = (ll)1e9 + 7;

ll findMaximum(vector<ll> input) {
    sort(input.rbegin(), input.rend());
    ll Greatest = 0;
    int size = input.size();
    // for(int j =1; j <= (size/2); j++ ){
    //     ll x = 0;
    //     for (int i = 0; i < j; i++) {
    //         x = x * 10 + input[i*2];
    //     }
    //     ll y = 0;
    //     for (int i = 0; i < j; i++) {
    //         y = y * 10 + input[i*2+1];
    //     }
    //     for (int i = j*2; i < size; i++) {
    //         y = y * 10 + input[i];
    //     }
    //     if(x*y > Greatest) {
    //         Greatest = x*y;
    //     }
    // }
    ll x = input[0];
    ll y = 0;
    for (int i = 1; i < size; i++) {
        if (input[i] == 0) {
            y = y * 10 + input[i];
        } else {
            if (x > y) {
                y = y * 10 + input[i];
            } else {
                x = x * 10 + input[i];
            }
        }
        // cout << "   " << input[i] << ":" <<x<< " "<< y <<"\n";
    }
        // cout <<"    "<< a << " " << b << "\n";
    return x*y;
}

int main() {
    // For Cin/Cout
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        vector<ll> in;
        Rep(i, str.length()){
            int x = (int)str[i] - 48;
            if( x == 6){
                in.pb(9);
            }
            else{
                in.pb(x);
            }
        }
        // findMaximum(in);
        // Trav(it, in){
        //     cout << *it <<" ";
        // }
        cout << findMaximum(in) << "\n";
    }
    return 0;
}