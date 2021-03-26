#include <bits/stdc++.h>
#include <algorithm>    // std::reverse
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

map<char, vector<char>> Graph;
map<char, vector<char>> Graph1;
map<char, double> value;
map<char, double> d;

pair<char, double> bfs() {
    d.clear();
    queue<char> Q;
    Q.push('*');
    d['*'] = 0;
    double maxValue = 0;
    char pl;
    while (!Q.empty()) {
        char tmp = Q.front();
        Q.pop();
        // vector<char> mm = Graph[tmp];
        // sort(mm.begin(), mm.end());
        // Trav(it, mm) {
        Trav(it, Graph1[tmp]) {
            // cout<<it<<" ";
            if (d.count(it) == 0) {
                // cout<<it<<"\n";
                d[it] = d[tmp] + 1;
                double v = value[it] * (1-d[it] * 0.05);
                // cout<<it<< " "<<v<<"\n";
                if (v > maxValue) {
                    pl = it;
                    maxValue = v;
                }
                Q.push(it);
            }
        }
            // cout<<"\n";
    }
    return mp(pl, maxValue);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d", &t);
    string input;
    stringstream ss;
    while (getline(cin, input)) {
        // printf("Solution %d\n", t);
        int N;
        ss << input;
        ss >> N;
        ss.clear();
        value.clear();
        Graph.clear();
        rep(i, 0, N) {
            char planet;
            float val;
            string listEdge;
            getline(cin, input);
            ss << input;
            ss >> planet >> val >> listEdge;
            ss.clear();
            value[planet] = val;
            rep(i, 0, listEdge.size()) {
                Graph[planet].pb(listEdge[i]);
                Graph[listEdge[i]].pb(planet);
            }
        }
        // sort(all(Graph));
        Trav(it, Graph){
            sort(it.second.begin(), it.second.end());
            Graph1[it.first] = it.second;
            // reverse(all(it.second));
            // printf("Planet %c : ",it.first);
            // Trav(i, it.second){
            //     printf(",%c", i);
            // }
            // printf("\n");
        }
        pair<char, double> result = bfs();
        // cout <<"Import from  "<<result.first<< " value " <<result.second <<"\n";
        cout <<"Import from "<<result.first<<"\n";
        // cout <<"size " << Graph.size() <<"\n";
    }
    return 0;
}