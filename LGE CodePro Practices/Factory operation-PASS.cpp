#include <bits/stdc++.h>
using namespace std;


int N;//Day
int S;//Storage cost
int C[50010];//Price
int Y[50010];//Capacity

void Input_Data(void){
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	Input_Data();		//Input function

    long long price = C[0];
    long long sum = C[0]*Y[0];
    for(int i = 1; i < N ; i++){
        price += S;
        if(C[i] < price) price = C[i];
        sum += price*Y[i];
    }

	// TODO : Write your codes.
	
	
	cout << sum << endl;	//	Answer output
	return 0;
}
