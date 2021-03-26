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
#define Travd(i,v) for(auto i = (v).rbegin(); i != (v).rend(); ++i) //*i
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

int binarySearch(vi arr, int target){
    int lo = 0;
    int hi = arr.size()-1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        // cout << "   MID    " << mid << " LO " << lo  << " Hi " << hi<<"\n"; 
        if(arr[mid] == target) return mid;
        else if( arr[mid] < target){
            lo = mid +1;
        }
        else{
            hi = mid -1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int T = 1;
    // cin >> T;
    // string input;
    // while (getline(cin, input)) {
    //     stringstream ss;
    //     ss << input;
    while (!cin.eof()) {
        int n, xi, budget;
        vi costs;
        cin >> n;
        // cout <<"Test case " <<  n<<"\n"; 
        Rep(i, n){
            cin >> xi;
            costs.pb(xi);
        }
        sort(all(costs));
        cin >> budget;
        // cout <<budget<< '\n';
        int p1=INF, p2=0;
        // Rep(i, costs.size()){
        //     cout <<costs[i]<< " ";
        // }
        // cout << '\n';
        Rep(i, costs.size()){
            // cout <<costs[i] << " Tar " << budget-costs[i] <<'\n';

            int index = binarySearch(costs, (budget-costs[i]));
            // cout << index << "\n";
            if(index != -1 && index != i )
                if(abs(p1 - p2) > abs(costs[i] - costs[index])){
                    p1 = costs[i];
                    p2 = costs[index];
                }
        }
        cout << "Peter should buy books whose prices are " << p1 << " and " << p2 << ".\n"; 
        cin.ignore(2);
        // if(!cin.eof()) cout <<"\n";
        cout <<"\n";
    }
    return 0;
}