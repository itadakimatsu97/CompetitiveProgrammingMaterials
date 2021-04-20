#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define HACKER_RANK

int N, K;
int arr[100000+10];
map<int,int> dict;

void input(){
    cin >> N >> K;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
        dict[arr[i]] = i;
    }
}

// Greedy-dictionary method
// int solver(){
//     int cnt = 0;
//     sort(arr, arr+N);
//     for(int i =0; i<N; i++){
//         int tmp = arr[i] + K;
//         if(dict.count(tmp)) cnt++;
//     }
//     return cnt;
// }


// 2 pointers method
int solver(){
    int cnt = 0, i =0, j =1;
    sort(arr, arr+N);
    while (j < N) {
        int diff = arr[j] - arr[i];
        if (diff == K) {
            cnt++;
            j++;
        } else if (diff > K) {
            i++;
        } else if (diff < K) {
            j++;
        }
    }
    return cnt;
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
    input();
    int ans = solver(); 
    fout << ans << "\n";
    fout.close();
    return 0;
}