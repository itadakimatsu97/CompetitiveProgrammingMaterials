#include<bits/stdc++.h> 
using namespace std; 

/****** Template of MACRO/CONSTANT *****/
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define present(c, x) ((c).find(x) != (c).end())
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
/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

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
//    cin>>t;
   while(t--) 
   { 
      solve(); 
   } 
   
   cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 
void solve() 
{   
    int N, Bs, shortest, spaceR;
    int COL = 25;
    int space[COL+1];
    string line;

    while(cin>>N){
        if(!N) break;
        cin.ignore(); //Remove first \n
        shortest = 25;
        spaceR = 0;
        Fi(i, 0, N){
            Bs = 0;
            getline(cin, line);
            Fi(i, 0, COL){
                if(line[i] == ' ') Bs++;
            }
            if(Bs < shortest){
                shortest = Bs;
            }
            space[i] = Bs;
        }
        Fi(i, 0, N){
            spaceR += space[i]-shortest;
        }
        cout<<spaceR<<endl;
    }
} 