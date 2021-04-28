#include <iostream>
using namespace std;

int N;
int P[150000 + 10];

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int greedy(){  // bottom-up dp
	int sum = P[0];
	for(int i = 1; i < N; i++){
        // cout << "i: "<<i<< "\n";
        if (P[i - 1] < P[i]) {
            sum = sum - P[i - 1] + P[i];
            // cout <<"    pi-1  "<< P[i - 1] << "    pi  "<< P[i]<<"\n";
        }
    }
	return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	int ans = -1;
	InputData();
	ans = greedy();
	cout << ans << endl;
	return 0;
}