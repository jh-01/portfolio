#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> posi;
vector<int> nega;
vector<int> zero;
vector<int> res;

void input(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		if(a > 0){
			if(a == 1){
				res.push_back(a);
			}
			else {
				posi.push_back(a);	
			}
		}
		else if(a == 0){
			zero.push_back(a);
		}
		else {
			nega.push_back(a);
		}
	}
}

int solve(){
	int sum = 0;
	int pSize = posi.size();
	int nSize = nega.size();
	
	sort(posi.rbegin(), posi.rend());
	sort(nega.begin(), nega.end());

	for(int i = 0; i < nSize - 1; i+=2) {
		res.push_back(nega[i] * nega[i + 1]);
	}
	if(nSize % 2 != 0) {
		if(zero.size() > 0)
			zero.pop_back();
		else {
			res.push_back(nega[nSize - 1]);
		}
	}
	
	for(int i = 0; i < pSize - 1; i+=2){
		res.push_back(posi[i] * posi[i + 1]);
	}
	if(pSize % 2 != 0){
		res.push_back(posi[pSize - 1]);
	}
	
	for(int i = 0; i < res.size(); i++){
		sum += res[i];
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	input();
	cout << solve() << "\n";
	return 0;
}
