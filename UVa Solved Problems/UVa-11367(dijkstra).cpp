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

//Define for problem
const int MAX_NODE = 1000;
const int MAX_EDGE = 1000;
const int MAX_CAP = 100;

struct Edge {
    int to, dist;  //u-v weight
    Edge(int V, int W) : to(V), dist(W) {}
};
struct Node {  //State of node
    int id, remainedGas, cost;
    Node(int ID, int RG, int C) : id(ID), remainedGas(RG), cost(C) {}
    bool operator<(const Node &that) const {  //use for priority_queue
        return cost > that.cost;
    }
};
/*BEGIN declare Graph and Algorithm Dijkstra*/
vector<Edge> Graph[MAX_NODE];  // store all connected Edge: u->edge
int d[MAX_NODE][MAX_CAP];      //store money cost at node[u][]
int price[MAX_NODE];
int n, m;  // number of vertex/edge in problem

int dijkstra(int capacity, int start, int end) {
    rep(i, 0, n)  //Reset cost to infinitive;
        rep(j, 0, MAX_CAP) d[i][j] = INF;
    priority_queue<Node> pq;
    d[start][0] = 0;
    pq.push(Node(start, 0, 0));
    while (!pq.empty()) {
        Node nd = pq.top();
        pq.pop();
        if (nd.id == end) return nd.cost;
        Trav(edge, Graph[nd.id]) {
            if (nd.remainedGas >= edge.dist) {
                if (d[edge.to][nd.remainedGas - edge.dist] > d[nd.id][nd.remainedGas]) {
                    d[edge.to][nd.remainedGas - edge.dist] = d[nd.id][nd.remainedGas];
                    pq.push(Node(edge.to, nd.remainedGas - edge.dist, d[edge.to][nd.remainedGas - edge.dist]));
                }
            }
        }
        if (nd.remainedGas < capacity) {
            if (d[nd.id][nd.remainedGas + 1] > d[nd.id][nd.remainedGas] + price[nd.id]) {
                d[nd.id][nd.remainedGas + 1] = d[nd.id][nd.remainedGas] + price[nd.id];
                pq.push(Node(nd.id, nd.remainedGas + 1, d[nd.id][nd.remainedGas + 1]));
            }
        }
    }
    return -1;
}
/*END declare Graph and Algorithm Dijkstra*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d", &t);
    while (t--) {
        // printf("Solution %d\n", t);
        scanf("%d %d", &n, &m);
        rep(i, 0, n) {
            Graph[i].clear();
            scanf("%d", &price[i]);
        }
        int u, v, w;
        rep(i, 0, m) {
            scanf("%d %d %d", &u, &v, &w);
            Graph[u].push_back(Edge(v, w));
            Graph[v].push_back(Edge(u, w));
        }
        int queries;
        scanf("%d", &queries);
        int cap, start, end;
        rep(i, 0, queries) {
            scanf("%d %d %d", &cap, &start, &end);
            ll costResult = dijkstra(cap, start, end);
            if (costResult != -1) {
                printf("%d\n", costResult);
            } else {
                printf("impossible\n");
            }
        }
    }
    return 0;
}
