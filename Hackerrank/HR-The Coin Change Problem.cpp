#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int N, M;
int c[55];
long dp[250+10];

void input(){
    cin >> N >> M;
    for(int i =0; i< M; ++i){
        cin >> c[i];
    }
}

long solver(){
    memset(dp, 0, sizeof dp);
    dp[0]=1;
    for(int i=0; i<M; i++){
        for(int j=c[i]; j<=N; j++){
            dp[j] += dp[j-c[i]];
        }
    }
    return dp[N];
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
        long ans = solver(); 
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}