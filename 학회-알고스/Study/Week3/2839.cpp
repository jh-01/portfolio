#include <iostream>

using namespace std;

int main(){
	int N;
	int cnt = 0;
	
	cin >> N;
	while(true){
		if(N % 5 == 0){
			cnt += N / 5;
			cout << cnt << "\n";
			break;
		}
		N -= 3;
		cnt++;
		if(N < 0){
			cout << -1;
			break;
		}
	}
	return 0;
}
