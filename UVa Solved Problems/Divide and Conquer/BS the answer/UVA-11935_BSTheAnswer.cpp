#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<pair<int,int>> events;

bool can(double f){
    int curN = 0, leak = 0, curC =0;
    double initial = f;
    for(auto it : events){
        f -= (it.first-curN)*(leak + curC/100.0);
        if(f<0) return false;
        if(it.second <= 0) curC = -it.second;
        if(it.second == 1) leak++;
        else if(it.second == 2) f = initial;
        else if(it.second == 3) leak=0;
        else if(it.second == 4) break;
        curN=it.first;
    }
    return (f >= 0.0);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    while (scanf("0 Fuel consumption %d\n", &n), n) {
        events.clear();
        events.emplace_back(0, -n); // first event
        while (1) {
            int d; char line[100]; scanf("%d ", &d); gets(line);
            if (strncmp(line, "Fuel", 4) == 0) { // the first four characters are "Fuel"
                sscanf(line, "Fuel consumption %d", &n);
                events.emplace_back(d, -n);
            }
            else if (strcmp(line, "Leak") == 0)
                events.emplace_back(d, 1);
            else if (strcmp(line, "Gas station") == 0)
                events.emplace_back(d, 2);
            else if (strcmp(line, "Mechanic") == 0)
                events.emplace_back(d, 3);
            else if (strcmp(line, "Goal") == 0) {
                events.emplace_back(d, 4);
                break;
            }
        }
        // Binary Search the Answer (BSTA), then simulate
        double lo = 0.0, hi = 10000.0;
        while (fabs(hi-lo) > 1e-9) {                 // answer is not found yet
            double mid = (lo+hi) / 2.0;                // try the middle value
            can(mid) ? hi = mid : lo = mid;            // then continue
        }
        printf("%.3lf\n", hi);
    }

    return 0;
}