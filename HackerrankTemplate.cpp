#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void input(){

}

int solver(){
    return -1;
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