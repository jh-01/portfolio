#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int N;
int arr[MAX];

void input(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
}

int solve(){
	int res = 1;
	sort(arr, arr + N);
	
	for(int i = 0; i < N; i++){
		if(res < arr[i]){
			break;
		}
		res += arr[i];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	input();
	cout << solve() << "\n";
	return 0;
}
