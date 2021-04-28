#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
long long N, M, K;
struct Interval {
    long start, end;
    inline bool operator < (const Interval &that) const{
        return start < that.start;
    }
};

map<int, vector<Interval>> MAP;
void input(){
    cin >> N >> M >> K;
    int r, c1, c2;
    for(int i =0; i <K; i++){
        cin >> r >> c1 >> c2;
        MAP[r].push_back({c1, c2});
    }
    // for(auto it : MAP){
    //     for(auto it2: it.second){
    //         cout << it.first << " " << it2.start << " " << it2.end << "\n";
    //     }
    // }
}

long long mergeOverlappingInterval(vector<Interval> A){
    long long cnt = 0;
    sort(A.begin(), A.end());
    stack<Interval> S;
    S.push(A[0]);
    for(int i =1; i < A.size(); i++){
        auto tmp = S.top();
        if(tmp.end < A[i].start) S.push(A[i]);
        else if(tmp.end < A[i].end){
            tmp.end = A[i].end;
            S.pop();
            S.push(tmp);
        }
    }
    while(!S.empty()){
        auto tmp = S.top(); S.pop();
        cnt += (tmp.end - tmp.start+1);
    }
    return cnt;
}

unsigned long long solver(){
    unsigned long long ans = N*M;
    for(auto it : MAP){
        ans -= mergeOverlappingInterval(it.second);
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
        long long ans = solver(); 
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}