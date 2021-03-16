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

// asd
#define MAXE 2500
int E;
map<int, vector<int>> Graph;
vector<int> d;
map<int, vector<int>> m;
pair<int, int> bfs(int s) {
    d.assign(E+1, INF);
    queue<int> Q;
    d[s] = 0;
    Q.push(s);
    int firstBoomDay = 0;
    int maxBoomSize = 0;
    int maxD =0;
    m.clear();
    // m[0].pb(s);
    while(!Q.empty()){
        int tmp = Q.front(); Q.pop();
        Trav(it, Graph[tmp]){
            if( d[it] == INF ){
                d[it] = d[tmp] +1;
                m[d[it]].pb(it);
                // if( d[it] > maxD) maxD = d[it];
                Q.push(it);
            }
        }
    }
    Trav(it, m){
        // printf("Dist %d: ", it.first);
        // Trav(it1, it.second){
        //     printf(", %d", it1);
        // }
        // printf("\n");
        int size = it.second.size();
        if(size > maxBoomSize){
            maxBoomSize = size;
            firstBoomDay = it.first;
        }
    }
    // Trav(it, d) printf( "%d ", it);
    // printf( "MAX %d ", maxD);
    // rep(i, 1, maxD+1){
    //     int c = count(d.begin(), d.end(), i);
    //     if(c > maxBoomSize){
    //         maxBoomSize = c;
    //         firstBoomDay = i;
    //     }
    // }
    // printf( "MAX %d ", maxBoomSize);
    return mp(maxBoomSize, firstBoomDay);
}

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
        int N, f, tc, st;
        scanf("%d", &E);
        rep(i, 0, E) {
            scanf("%d", &N);
            rep(j, 0, N) {
                scanf("%d", &f);
                Graph[i].pb(f);
            }
        }
        scanf("%d", &tc);
        while(tc--){
            scanf("%d", &st);
            pair<int,int> result = bfs(st);
            if(result.second != 0)
                printf("%d %d\n", result.first, result.second );
            else
                printf("0\n");
        }
        // Trav(it, Graph){
        //     printf("Vertex %d: ", it.first);
        //     Trav(it1, it.second){
        //         printf(", %d", it1);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}