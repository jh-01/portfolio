#include <iostream>
#include <deque>
#define MAX 500001

using namespace std;

int N, K;
int num;
string s;
deque<char> dq; 

int main(){
	cin >> N >> K;
	cin >> s;
	
	for(int i = 0; i < s.length(); i++){
		while(K && !dq.empty() && dq.back() < s[i]){
			dq.pop_back();
			K--;
		}
		dq.push_back(s[i]);
	}
	
	for(int i = 0; i < dq.size() - K; i++){
		cout << dq[i];
	}
	return 0;
}
