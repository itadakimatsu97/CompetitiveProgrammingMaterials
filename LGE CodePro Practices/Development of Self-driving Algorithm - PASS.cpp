#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int H;//Height
int W;//Width
char Map[500][510];//map
int d[500][510];
const int dr[]={-1, 0, 0, 1};
const int dc[]={0, -1, 1, 0};
void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> Map[i];
	}
}

bool valid(int a, int b){
    if(a <0 || b < 0 || a >= H || b >= W) return false;
    if(Map[a][b] == 'X') return false;
    if(d[a][b] != -1) return false;
    return true;
}

int bfs(){
    memset(d, -1, sizeof d);
    queue<pair<int, int>> Q;
    d[0][0] = 0;
    Q.push(make_pair(0, 0));
    while(!Q.empty()){
        pair<int, int> tmp = Q.front(); Q.pop();
        if( tmp.first == H-1 && tmp.second == W-1) return d[H-1][W-1];
        for(int i =0; i < 4 ; i++){
            int x = tmp.first + dr[i];
            int y = tmp.second + dc[i];
            if(valid(x, y)) {
                Q.push(make_pair(x, y));
                d[x][y] = d[tmp.first][tmp.second] +1;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	input_data();
	// Todo : write the code
	int ans = bfs();
	cout << ans << endl;
	return 0;
}