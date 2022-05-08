#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 200002
using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int> > pq;

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

int solve(){
	sort(v.begin(), v.end(), compare);
	
	pq.push(v[0].second);
	for(int i = 1; i < N; i++){
		pq.push(v[i].second);
		if(pq.top() <= v[i].first){
			pq.pop();
		}
	}
	
	return pq.size();
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	input();
	cout << solve() << "\n";
	return 0;
}
