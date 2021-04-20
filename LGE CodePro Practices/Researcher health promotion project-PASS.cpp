#include <bits/stdc++.h>
using namespace std;

int N;				//	# of stairs
int P[310];		//	P[i]: score earned when stepping on stair i
int dp[310];    //bottom up dp

int Solve(){
	dp[0] = 0; 
	dp[1] = P[0]; 
	dp[2] = P[0] + P[1];
    //Step 1 - step 2 - step 3 - step 4
	for (int i = 3; i <= N; i++){
		dp[i] = dp[i - 2] + P[i-1];		//step1 + step 2 + step 4 --- ignore step 3
		if (dp[i] < dp[i - 3] + P[i - 2] + P[i-1]){   //step1 + step 3 + step 4 --- ignore step 2
			dp[i] = dp[i - 3] + P[i - 2] + P[i-1];
		} 
	}
	return dp[N];
}

void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> P[i];
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	InputData();					//	Input function

	int sol = Solve();

	cout << sol << endl;		//	Answer output
	return 0;
}
