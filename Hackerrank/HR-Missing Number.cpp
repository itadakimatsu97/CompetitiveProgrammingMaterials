#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define HACKER_RANK

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifdef HACKER_RANK
    freopen("input.txt", "r", stdin);
    ofstream fout("output.txt");
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif
    int N, tmp, M;
    int arr[10001];
    cin >> N;
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < N; i++){
        cin >> tmp;
        arr[tmp]--;
    }
    cin >> M;
    for (int i = 0; i < M; i++){
        cin >> tmp;
        arr[tmp]++;
    }
// #ifndef HACKER_RANK
    bool first = true;
    for (int i = 0; i <10001; i++){
        if(arr[i] > 0 ){
            if(first){ 
                fout << i;
                first = false;}
            else
                fout << " " << i;
        }
    }

    fout.close();
    return 0;
}