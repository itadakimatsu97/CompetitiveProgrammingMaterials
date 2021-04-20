#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define HACKER_RANK
const int MAX = 1e5+10;
int N;
int arr[MAX];
void input(){
    cin >> N;
    for(int i =0; i < N; ++i){
        cin >> arr[i];
    }
}
//left + i + right = sum
//2left = sum - i;
string solver(){
    int sum = 0, sumLeft = 0;
    for(int i=0; i < N; ++i){
        sum+=arr[i];
    }
    for(int i =0; i<N; ++i){
        if(2*sumLeft == sum - arr[i]) return "YES";
        sumLeft+=arr[i]; 
    }
    return "NO";
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
        string ans = solver(); 
        fout << ans << "\n";
    }
    fout.close();
    return 0;
}