#include <iostream>
#define MAX 1000000001
using namespace std;

long long N;
long long cost[100001];
long long dist[100001];

void input(){
	cin >> N;
	for(int i = 1; i <= N - 1; i++){
		cin >> dist[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> cost[i];
	}
}

long long solve(){
	long long tmp = MAX;
	long long res = 0;
	
	for(int i = 1; i <= N; i++){
		if(cost[i] < tmp) tmp = cost[i];
		res += tmp * dist[i];
	}
	return res;
}

int main(){
	input();
	cout << solve();
	return 0;
}
