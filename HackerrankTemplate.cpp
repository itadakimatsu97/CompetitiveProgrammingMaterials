#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define HACKER_RANK

void input(){

}

int solver(){
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifdef HACKER_RANK
    freopen("input.txt", "r", stdin);
    ofstream fout("output.txt");
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    int TESTCASE = 1;
    cin >> TESTCASE;
    while(TESTCASE--){
        input();
        int ans = solver(); 
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}