#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define HACKER_RANK

int K, N;
int cost[10000+10];
void input(){
    cin >> K >> N;
    for(int i = 0; i<N;++i){
        cin >> cost[i];
    }
}
// //Array
// pair<int,int> solver(){
//     pair<int,int> tmp;
//     int index[10000+10];
//     memset(index, -1, sizeof index);
//     for(int i = 0 ; i < N ; ++i){
//         int key = K-cost[i];
//         if(key>0){
//             if(index[key] != -1){
//                 tmp = { index[key] +1, i+1};
//                 break;
//             }
//         }
//         index[cost[i]] = i;
//     }
//     return tmp;
// }

//Map
pair<int,int> solver(){
    pair<int,int> tmp;
    map<int,int> dict;
    for(int i = 0 ; i < N ; ++i){
        int key = K-cost[i];
        if(key>0){
            if(dict.count(key)){
                tmp = { dict[key] +1, i+1};
                break;
            }
        }
        dict[cost[i]] = i;
    }
    return tmp;
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
        pair<int,int> ans = solver(); 
        fout << ans.first <<" " << ans.second << "\n";
    }
    fout.close();
    return 0;
}