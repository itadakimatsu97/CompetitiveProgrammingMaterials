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
#define Trav(i,v) for(auto i: (v))
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

map<char, int> M;
map<char, vector<char>> Graph;

bool checkNeibor(int c1, int c2){
    return (abs(c1-c2) == 1 || abs(c1-c2)==19 || abs(c1-c2)==18);
}
void createGraphKeyboard(){
    M['Q'] = 1; 
    M['W'] = 2;
    M['E'] = 3;
    M['R'] = 4;
    M['T'] = 5;
    M['Y'] = 6;
    M['U'] = 7;
    M['I'] = 8;
    M['O'] = 9;
    M['P'] = 10;

    M['A'] = 20;
    M['S'] = 21;
    M['D'] = 22;
    M['F'] = 23;
    M['G'] = 24;
    M['H'] = 25;
    M['J'] = 26;
    M['K'] = 27;
    M['L'] = 28;

    M['Z'] = 39;
    M['X'] = 40;
    M['C'] = 41;
    M['V'] = 42;
    M['B'] = 43;
    M['N'] = 44;
    M['M'] = 45;
    For(i, 65, 90){
        For(j, 65, 90){
            if(checkNeibor(M[(char)i] , M[(char)j])){
                Graph[(char)i].pb((char)j);
            }
        }
    }
    // Trav(it, Graph){
    //     printf("%c :", it.fi);
    //     Trav(it2, it.se){
    //         printf("%c ", it2);
    //     }
    //     printf("\n");
    // }
}
int d[26];
int bfs(char c1, char c2){
    fill( d, d + 26, INF);
    queue<char> Q;
    d[(int)c1-65] = 0;
    Q.push(c1);
    while(!Q.empty()){
        char tmp = Q.front(); Q.pop();
        if( tmp == c2) return d[(int)tmp - 65];
        Trav(it, Graph[tmp]){
            if( d[(int)it-65] == INF){
                d[(int)it-65] = d[(int)tmp - 65] +1;
                Q.push(it);
            }
        }
    }
    return -1;
}

int main() {
    // For Cin/Cout
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif


    createGraphKeyboard();
    int t = 1;
    cin >>t;
    cin.ignore();
    while (t--) {
        
        string str;
        getline(cin, str);
        int size = str.length();
        // cout << size << ":";
        int step = 0;
        For(i, 1, size-1){
            step+=bfs(str[i-1],str[i]);
            // cout << step << ", ";
        }
        cout << step*2+size << "\n";

        // printf("Case %d:\n", t);
        
    }
    return 0;
}