#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

/****** Template of MACRO/CONSTANT *****/
#define INF INT_MAX
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()   //Forward traversal
#define rall(x) (x).rbegin, (x).rend()  //reverse traversal
#define present(c, x) ((c).find(x) != (c).end())
#define sz(x) (x.size())
#define rep(i, from, end) for (int i = from; i < end; i++)
#define REP(i, from, end) for (int i = from; i <= end; i++)
#define Trav(it, x) for (auto it : x)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

map<string, vector<string>> Graph;
vector<string> words;
map<string, int> dist;
bool diff1char(string s1, string s2) {
    int S1 = s1.size();
    int S2 = s2.size();
    int count = abs(S1 - S2);
    rep(i, 0, min(S1, S2)) {
        if (s1[i] != s2[i]) count++;
        if (count > 1) return false;
    }
    return true;
}

int bfs(string start, string end) {
    dist.clear();
    queue<string> Q;
    dist[start] = 0;
    Q.push(start);
    // cout << "\n   "<< start <<"\n";
    while (!Q.empty()) {
        string tmp = Q.front();
        Q.pop();
        if (!tmp.compare(end)) return dist[tmp];
        // cout << "       "<< tmp <<"\n";

        Trav(it, Graph[tmp]) {
            // cout << "           "<< it <<"\n";
            if (dist.count(it) == 0) {
                dist[it] = dist[tmp] + 1;
                Q.push(it);
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    // scanf("%d", &t);
    while (t--) {
        // cout<< "TC " <<t<<"\n";
        string word;
        stringstream ss;
    // cin.ignore();
        int a = 20;
        while (true) {
            cin >> word;
            if (word[0] == '*') break;
            words.pb(word);
            // cout<<word <<" \n";
        }
        // cout<< words.size();
        Trav(it, words) {
            Trav(it2, words) {
                if (it.compare(it2)) {
                    if (diff1char(it, it2)) Graph[it].pb(it2);
                }
            }
        }
        // Trav(it, Graph) {
        //     cout<< it.first << " ";
        //     Trav(it2, it.second){
        //         cout <<" " << it2;
        //     }
        //     cout<<"\n";
        // }
        // if (word[0] == '*') {
        cin.ignore();
        while (getline(cin, word) && word.size()) {
            ss.clear();
            string start, end;
            ss << word;
            ss >> start >> end;
            cout << start
                 << " " 
                 << end
                 << " "
                 << bfs(start, end)
                 << "\n";
        }
        if(t>0) cout<<"\n";
    }
    return 0;
}