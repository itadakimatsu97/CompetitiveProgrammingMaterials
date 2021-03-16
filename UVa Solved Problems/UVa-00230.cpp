#include <bits/stdc++.h>
using namespace std;

/****** Template of MACRO/CONSTANT *****/
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define present(c, x) ((c).find(x) != (c).end())
#define sz(x) (x.size())
#define Fi(i, from, end) for(int i = from; i < end; i++)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

void solve();
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif

   int t = 1;
   // cin>>t;
   string tempt;
   while (t--)
   {
      solve();
   }

   cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
   return 0;
}

struct book
{
   string title, author;
   bool operator<(const book &bookC) const
   {
      if (author != bookC.author)
         return author < bookC.author;
      return title < bookC.title;
   }
};

void solve()
{
   string line;
   char title[85], author[85];
   vector<book> listBooks;
   map<string, int> pos;
   map<int, bool> available;
   vector<book> returned;
   while (getline(cin, line))
   {
      book tempBook;
      if (line == "END")
         break;
      sscanf(line.c_str(), "\"%[^\"]\" by %[^\n\r]", title, author);
      tempBook.title = title;
      tempBook.author = author;
      listBooks.push_back(tempBook);
   }
   sort(all(listBooks));

   Fi(i, 0, sz(listBooks)){
      pos[listBooks[i].title] = i;
      available[i] = true;
   }

   while (getline(cin, line))
   {  
      char cmd[10], title[85];
      if(line == "END")
         break;
      sscanf(line.c_str(), "%[A-Z] \"%[^\"]\"", cmd, title);

      if(!strcmp(cmd,"BORROW")){
         available[pos[title]] = false; 
      }
      else if (!strcmp(cmd,"RETURN")){
         returned.push_back(listBooks[pos[title]]);
      }
      else{
         sort(all(returned));
         for(auto i : returned){
            bool isHasBookAfter = false;
            int p = pos[i.title];
            int posAfter = p-1;
            while (posAfter >= 0) {
               if (available[posAfter] == true) {
                     isHasBookAfter = true;
                     break;
               }
               posAfter--;
            }
            if(isHasBookAfter){
               cout<<"Put \""<<i.title<<"\" after \""<<listBooks[posAfter].title<<"\""<<endl;
            }
            else{
               cout<<"Put \""<<i.title<<"\" first\n";
            }
            available[p] = true;
         }
         returned.clear();
         cout<<"END"<<endl;
      }
   }
}