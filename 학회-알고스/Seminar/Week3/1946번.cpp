#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

int T, N;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first)
		return 1;
	else return 0;
}

void input(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
}

void init(){
	v.clear();
}

int solve(){
	int cnt = 0;
	int min = MAX;
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < N; i++){
		if(min > v[i].second){
			min = v[i].second;
			cnt++;
		}
	}
	
	return cnt;
}

int main(){
	cin >> T;
	while(T--){
		input();
		cout << solve() << "\n";
		init();
	}
	return 0;
}
