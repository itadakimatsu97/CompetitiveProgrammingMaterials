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

const int ALPHABET_SIZE = 2;
const int NUMBITS = 31;

int COUNT = 0;
bool check(int n, int pos) {
    return ((bool)(n & (1 << pos)));
}

struct TrieNode {
    TrieNode *children[2];
    bool isLeaf;
};

struct TrieNode *getNode(void) {
    TrieNode *cur = new TrieNode;
    cur->children[0] = NULL;
    cur->children[1] = NULL;
    cur->isLeaf = false;
    return cur;
}

void add(TrieNode *root, int key) {
    TrieNode *cur = root;
    bool newNode = false;
    for (int i = NUMBITS; i >= 0; i--) {
        int index = (int)check(key, i); 
        if(index == 0){
            if(!cur->children[0]){
                cur->children[0] = getNode();
                newNode = true;
            }
            cur = cur->children[0];
        }
        else{
            if(!cur->children[1]){
                cur->children[1] = getNode();
                newNode = true;
            }
            cur = cur->children[1];
        }
    }
    cur->isLeaf = true;
    if(newNode) COUNT++;
}
// int count(TrieNode *root, int index = 0){
//     int countt = 0;
//     if(index > NUMBITS+1) return 0;
//     TrieNode *cur = root;
//     if(cur->isLeaf) return 1;
//     if(cur->children[1] != NULL){
//         countt += count(cur->children[1], index + 1);
//     }
//     if(cur->children[0] != NULL){
//         countt += count(cur->children[0], index + 1);
//     }
//     return countt;
// }

bool isEmpty(TrieNode* root) { 
    if (root->children[0]) 
        return false; 
    if (root->children[1]) 
        return false; 
    return true; 
} 
TrieNode* rem(TrieNode* root, int key, int index = NUMBITS+1){
    if(!root) return NULL;
    int b = (int)check(key, index-1);
    if (index == 0) { 
        if (root->isLeaf) 
            COUNT --;
            root->isLeaf = false; 
        if (isEmpty(root)) { 
            delete (root); 
            root = NULL; 
        } 
        return root; 
    } 

    if(b==0){
        root->children[0] = rem(root->children[0], key, index-1);
    }
    else{
        root->children[1] = rem(root->children[1], key, index-1);
    }
    if (isEmpty(root) && root->isLeaf == false) { 
        delete (root); 
        root = NULL; 
    } 
    return root; 
}

int find_max(struct TrieNode *root, int key) {
    struct TrieNode *cur = root;
    int mx_val = 0;
    for (int i = NUMBITS; i >= 0; i--) {
        int index = check(key, i);
        if (cur->children[index ^ 1])  /// when index is 0, then we will choose 1 (0^1)=1 or we will choose 0 when index is 1 (1^1)=0
        {
            mx_val += (1 << i);  /// here xor will give value 1 so take this one
            cur = cur->children[index ^ 1];
        } else {
            cur = cur->children[index];  /// the index^1 is null , so we have to index
        }
    }
    return (mx_val);
}

int find_min(struct TrieNode *root, int key) {
    struct TrieNode *cur = root;
    int min_val = 0;
    for (int i = NUMBITS; i >= 0; i--) {
        int index = check(key, i);
        if (cur->children[index])  /// First we will choose , to go as index ,if index is 1 we will go 1 or 0 go o
        {
            cur = cur->children[index];
        } else {
            min_val += (1 << i);  /// it will cause value ,so take this
            cur = cur->children[index ^ 1];
        }
    }
    return (min_val);
}

int main() {
    // For Cin/Cout
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int T = 1;
    cin >> T;
    while (T--) {
        // cout << "NEW TEST CASE \n";
        bool first = true;
        COUNT = 0;
        int n, q, e;
        TrieNode* root = getNode(); 
        cin >>n >> q;
        // cout << n << q << "\n";
        Rep(i,n){
            cin >> e;
            add(root, e);
            // cout << "COUNT:"<<COUNT << '\n'; //minXOR
        }
        // cout << "COUNT:"<<COUNT << '\n'; //minXOR
        Rep(i, q){
            int query, para =-1;
            cin >> query; 

            
            switch (query){
                case 1:
                {
                    cin >> para;
                    // if(para == -1) cout << "   QUERY: (" << query << "  "  <<")\n";
                    // else cout << "   QUERY: (" << query << " " <<para <<")\n";
                    cout << find_min(root, para) << '\n'; //maxXOR
                }
                break;

                case 2:
                {
                    cin >> para;
                    // if(para == -1) cout << "   QUERY: (" << query << "  "  <<")\n";
                    // else cout << "   QUERY: (" << query << " " <<para <<")\n";
                    cout << find_max(root, para) << '\n'; //minXOR
                }
                break;
            case 3:
                {
                    cin >> para;
                    // if(para == -1) cout << "   QUERY: (" << query << "  "  <<")\n";
                    // else cout << "   QUERY: (" << query << " " <<para <<")\n";
                    add(root, para);
                    // cout << count(root) << '\n'; //minXOR
                    // if(first){
                    //     cout << COUNT << '\n'; //minXOR
                    //     first = false;
                    // }
                    // else
                    cout << COUNT << '\n'; //minXOR
                }
                break;
            case 4:
                {
                    // if(para == -1) cout << "   QUERY: (" << query << "  "  <<")\n";
                    // else cout << "   QUERY: (" << query << " " <<para <<")\n";
                    int mm = find_min(root, 0);
                    rem(root, mm);
                    cout << mm << '\n'; //maxXOR
                }
                break;
            case 5:
                {
                    // if(para == -1) cout << "   QUERY: (" << query << "  "  <<")\n";
                    // else cout << "   QUERY: (" << query << " " <<para <<")\n";
                    int mm = find_max(root, 0);
                    rem(root, mm); 
                    cout <<  mm << '\n'; //maxXOR
                }
                break;
                default:
                break;
            }
        }
        delete(root);
    }
    return 0;
}