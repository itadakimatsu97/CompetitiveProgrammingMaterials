#include<bits/stdc++.h> 
using namespace std; 

//Common macro
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define sz(x) (x.size())
#define Fi(i, from, end) for(int i = from; i < end; i++)
#define Trav(it, x) for(auto it = (x).begin(); it != (X).end(); it++)

typedef long long                ll;
typedef pair<int, int>           ii;
typedef vector<int>              vi;
typedef vector<ii>               vii;
typedef map<int, int>            mii;

/*SPECIFIED PROBLEM*/
//For GRAPH-ADJACENCY MATRIX
#define MAX_V 100
int     R = 0;//Unknown row length
int     C = 0;//Unknown col length
int     adjMatrix[MAX_V][MAX_V];
bool    visited[MAX_V][MAX_V];
#define VISITED     true
#define UNVISITED   false
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
int dr[] = {1,1,0,-1,-1,-1, 0, 1};

void solve(); 
int main() 
{ 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL); 
   
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 

   int t=1; 
   cin>>t;
   cin.ignore(2);
//    cout<<t<<endl;
   while(t--) 
    { 
        solve();
        if(t)
            cout<<endl;

    } 
   
    cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
}
int bfs(int posn, int posm){
    int area = 0;
    ii tmp;
    tmp.fi = posn;
    tmp.se = posm;
    queue<ii> Q;
    Q.push(tmp);
    while(!Q.empty()){
        tmp = Q.front();
        Q.pop();
        if(adjMatrix[tmp.fi][tmp.se] == 1 && visited[tmp.fi][tmp.se] == UNVISITED){
            visited[tmp.fi][tmp.se] = VISITED;
            area++;
            Fi(i, 0, 8)
                if(tmp.fi+dr[i] >= 0 && tmp.fi+dr[i] < R && tmp.se+dc[i] >= 0 && tmp.se+dc[i] < C) 
                    Q.push(make_pair(tmp.fi+dr[i], tmp.se+dc[i]));
        }
    }
    return area;
}

int dfs(int posn, int posm){
    if (posn < 0 || posn >= R || posm < 0 || posm >= C) return 0;
    if (adjMatrix[posn][posm] != 1 || visited[posn][posm] == VISITED) return 0;
    int area = 1;
    visited[posn][posm] = VISITED;
    Fi(i, 0, 8)
        area += dfs(posn + dr[i], posm + dc[i]);
    return area;
}

int floodfill(int posn, int posm, int oldLabel, int newLabel){
    if (posn < 0 || posn >= R || posm < 0 || posm >= C) return 0;
    if (adjMatrix[posn][posm] != oldLabel) return 0;
    int area = 1;
    adjMatrix[posn][posm] = newLabel;
    Fi(i, 0, 8)
        area += floodfill(posn + dr[i], posm + dc[i], oldLabel, newLabel);
    return area;
}

void solve() 
{   
    R=0;
    C=0;
    string input;
    int posn, posm; //position
    stringstream ss;//for change string into stringstream;
    // cin.ignore(10, '\n');
    while(getline(cin, input)){
        if(input == "") break;
        // cout<<input<<endl;
        if(input[0] == 'L' || input[0] == 'W'){
            C = sz(input);
            Fi(i, 0, C){
                adjMatrix[R][i] = (input[i] == 'L')? 0 : 1;
            }
            R++;
        }
        else{
            Fi(i, 0, R)
                Fi(j,0,C)
                    visited[i][j] = UNVISITED;
            ss<<input;
            ss>>posn>>posm;
            ss.clear();
            // Fi(i, 0, R){
            //     Fi(j,0,C)
            //         cout<<adjMatrix[i][j];
            //     cout<<endl;
            // }
            // cout<<"ROW: "<<R<<" COL: "<<C <<endl;
            // cout<<"Px: "<<posn-1<<" Py: "<< posm-1 <<" A:"<< bfs(posn-1, posm-1)<<endl;
            // cout<<bfs(posn-1, posm-1)<<endl; //Time taken : 0.008 secs
            cout<<dfs(posn-1, posm-1)<<endl; //Time taken : 0.005 secs
        }
    }
} 