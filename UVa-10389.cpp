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

struct Node {
    int x, y, id;
    double cost;
    Node(){}
    Node(int X, int Y, int ID) {
        id = ID;
        x = X;
        y = Y;
        cost = INF;
    }
    bool operator<(const Node &that) const {
        return cost > that.cost;
    }
    bool operator==(const Node &that) const {
        return (x == that.x && y == that.y);
    }
};

const double Vw = 10 * 1000 / 60.0;  //met/minute
const double Vs = 40 * 1000 / 60.0;  //met/minute
double length(Node A, Node B) {
    int a = abs(A.x - B.x);
    int b = abs(A.y - B.y);
    return sqrt(a*a + b*b);
}

vector<Node> Nodes;
map<int, vector<pair<int, double>>> Graph;
// double dijktra(){
//     Nodes[0].cost = 0;
//     priority_queue<Node> PQ;
//     PQ.push(Nodes[0]);
//     while(!PQ.empty()){
//         Node tmp = PQ.top(); PQ.pop();

//     }


// }
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d", &t);
    cin >> t;
    // cout << t;
    cin.ignore(2);
    while (t--) {
        string input;
        stringstream ss;
        // printf("Solution %.02lf\n", Vw);
        Nodes.clear();
        Graph.clear();
        getline(cin, input); ss << input;
        int x, y;
        ss >> x >> y;
        // cout << x << " " << y <<"\n";  
        Nodes.pb(Node(x,y,0)); //idx 0: Home
        ss >> x >> y;
        Nodes.pb(Node(x,y,1)); //idx 1: School
        double w = length(Nodes[0], Nodes[1]) / Vw;
        Graph[0].pb(mp(1, w));
        Graph[1].pb(mp(0, w));
        while (getline(cin, input)) {
            // cout << input << "\n";
            ss.clear(); ss << input;
            bool first = true;
            while (true) {
                ss >> x >> y;
                if (x == -1 && x == -1) break;
                int sz = Nodes.size();
                Nodes.pb(Node(x,y,sz));
                rep(i, 0, sz) {
                    // if(Nodes[sz] == Nodes[i]) continue;
                    if (first) {
                        w = length(Nodes[sz], Nodes[i]) / Vw;
                        first = false;
                    } else {
                        if(i == (sz - 1)) 
                            w = length(Nodes[sz], Nodes[i]) / Vs;
                    }
                    Graph[sz].pb(mp(i, w));
                    Graph[i].pb(mp(sz, w));
                }
            }
        }
        // cout << "Size Nodes " << Graph[7].size();
        rep(i, 0, Nodes.size()){
            cout << "Node " << i << "\n";
            Trav(it, Graph[i]) {
                cout << "   From " << i << " to " << it.first << " W: " << it.second << "\n";
            }
        }
    }
    return 0;
}