#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N, M;
vector<pair<int,pair<int,int>>> edges;

class UnionFind {  // OOP style
   private:
    vector<int> p, rank, setSize;  // remember: vi is vector<int>
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

void input(){
    cin >> N >> M;
    int u, v,w;
    for(int i=0; i< M; ++i){
        cin >> u >> v >> w;
        // edges.push_back( make_pair(-w, make_pair(u,v)) );
        edges.push_back({w,{u,v}});
    }
}

int solver(){
    int ans = 0;
    sort(edges.begin(), edges.end());
    UnionFind uf(N+1);
    for(auto it: edges){
        int w = it.first;
        auto pair = it.second;
        if(!uf.isSameSet(pair.first, pair.second)){
            uf.unionSet(pair.first,pair.second);
            ans += w;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifdef LOCAL_JUDGE
    freopen("in", "r", stdin);
    ofstream fout("out");
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    int TESTCASE = 1;
    // cin >> TESTCASE;
    while(TESTCASE--){
        input();
        int ans = solver(); 
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}