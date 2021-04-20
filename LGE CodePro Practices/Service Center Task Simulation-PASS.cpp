#include <iostream>
using namespace std;

int N,Q;
int T[101];
int engineer[6];

void Input_Data(void){	
	cin >> N >> Q;				// Number of engineers, number of customers
	for(int i=1;i<=Q;i++){
		cin >> T[i];				// Customer’s work processing time
	}
}

int solver(){
	int ans = 0;
	for(int i = 1; i <= Q ; i++ ){
		int index_min = 1;
		for(int j = 2; j <= N; j++){
			if(engineer[index_min] > engineer[j]) index_min = j;
		}
		engineer[index_min] += T[i];
		if(engineer[index_min] > ans) ans = engineer[index_min];
	}
	return ans;
}

int main(void){
	int sol;

	Input_Data();				// Input function

	// Write the code. 

	
	cout << solver() << endl;	// Print answer
	return 0;
}