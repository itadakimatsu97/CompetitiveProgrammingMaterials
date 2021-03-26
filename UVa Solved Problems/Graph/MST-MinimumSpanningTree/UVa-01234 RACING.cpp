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

class UnionFind {  // OOP style
   private:
    vi p, rank, setSize;  // remember: vi is vector<int>
    int numSets;

   public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i);
            int y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    scanf("%d", &t);
    while (t--) {
        // printf("Solution %d\n", t);
        int V, E;
        int u, v, w;
        int mncost = 0;
        vector<pair<int, ii>> Edges;
        scanf("%d %d", &V, &E);
        rep(i, 0, E) {
            scanf("%d%d%d", &u, &v, &w);
            Edges.pb(mp(-w, mp(u, v)));  //Negative for decreased sort... then -w again
        }
        sort(all(Edges));
        // Trav(it, Edges){
        //     printf("%d %d %d\n", it.second.first, it.second.second, it.first);
        // }
        UnionFind uf(V+1); //V+1 because the first junction =1
        Trav(it, Edges){
            if(!uf.isSameSet(it.second.first, it.second.second)){
                uf.unionSet(it.second.first, it.second.second);
            }
            else{
                mncost += -it.first;
            }
        }
        printf("%d\n", mncost);
    }
    return 0;
}