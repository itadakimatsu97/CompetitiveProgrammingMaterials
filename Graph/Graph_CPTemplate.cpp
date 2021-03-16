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


typedef long int                 int32;
typedef unsigned long int        uint32;
typedef long long int            int64;
typedef unsigned long long int   uint64;
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
int bfs(int posn, int posm){ // For Adjancent Matrix
    int dc[] = {0,1,1, 1, 0,-1,-1,-1};
    int dr[] = {1,1,0,-1,-1,-1, 0, 1}; 
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
   while(t--) 
   { 
      solve(); 
   } 
   
   cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 
void solve() 
{   
} 