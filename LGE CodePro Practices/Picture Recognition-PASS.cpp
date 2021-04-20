#include <bits/stdc++.h>
using namespace std;

int N;//drawing paper size
char A[10 + 2][10 + 2];//Color information of drawing paper
int cnt[10];

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int solver(){
	memset(cnt, 0, sizeof cnt);
	int lower_bound_r,upper_bound_r,lower_bound_c,upper_bound_c, ans =0;
	for(int i = '1'; i <= '9'; i++){
		lower_bound_r=lower_bound_c=N;
		upper_bound_r=upper_bound_c=0;
		for(int r = 0; r < N; r++){
			for(int c = 0; c < N; c++){
				if(A[r][c] == i) {
					if( upper_bound_r < r) upper_bound_r =r;
					if( upper_bound_c < c) upper_bound_c =c;
					if( lower_bound_r > r) lower_bound_r =r;
					if( lower_bound_c > c) lower_bound_c =c;
				}
			}
		}
		if( lower_bound_r == N ) continue; //not found this color
		cnt[i-'0']++;
		for(int r = lower_bound_r; r <= upper_bound_r; r++){
			for(int c = lower_bound_c; c <= upper_bound_c; c++){
				if(A[r][c] != i) cnt[A[r][c]-'0']++;
			}
		}
	}
	for(int i =1; i < 10; i++) if(cnt[i] == 1)ans++;
	return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	InputData();//	input function

	
	cout << solver() << endl;//output 
    return 0;
}