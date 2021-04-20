#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    long long price[200000+10];
    unordered_map<long long,int> HMap;
    long long ans = 1e16;
    cin >> n;
    for(int i =0; i <n ; ++i){
        cin >> price[i];
        HMap[price[i]] = i;
    }
    sort(price, price+n);

    for (int i = 1; i < n; ++i) {
        if (HMap[price[i]] < HMap[price[i - 1]])
            ans = min(ans, price[i] - price[i - 1]);
    }
    // cout << ans << '\n';
    fout << ans << '\n';
    fout.close();
    return 0;
}