#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string line;
    while(getline(cin,line)){
        if("0 Fuel consumption 0" == line) break;
        double tank = 0.0, curTank = 0.0;
        int lastPos =0, leak = 0, consumtion = 0;

        do{
            stringstream ss(line);
            int curPos, lpk;
            string cmd, trash;
            ss >> curPos >> cmd;
            if(cmd == "Fuel" || cmd == "Gas") ss >> trash;

            curTank += (curPos-lastPos)*leak;
            curTank += (curPos-lastPos)*consumtion/100.0;
            tank = max(tank,curTank);
            //do

            if(cmd == "Goal") break;
            if(cmd == "Fuel") ss >> consumtion;
            else if (cmd == "Leak") leak++;
            else if (cmd == "Mechanic") leak = 0;
            else if (cmd == "Gas") curTank = 0.0;
            lastPos = curPos;
        }
        while(getline(cin, line));
        cout << fixed << setprecision(3) << tank << "\n";
    }

    return 0;
}