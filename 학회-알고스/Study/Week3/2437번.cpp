#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int N;
int arr[MAX];

int main(){
	cin >> N >> K;
	
	for(int i = N; i >= 0; i--){
		cin >> arr[i];
	}
	
	sort(arr, arr + N);
	
	int res = 1;
	for(int i = 0; i < N; i++){
		if(res < arr[i]) break;
		res += arr[i];
	}
	cout << res << "\n";
	return 0;
}
