#include <iostream>
#include <vector>
#define MAX 11

using namespace std;

int N;
int arr[MAX];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){ // i�� ����� ��ȣ�� ��Ÿ�� 
		int a;
		cin >> a;
		for(int j = 0; j < N; j++){ // j�� ������ ��Ÿ�� 
			if(a == 0 && arr[j] == 0){
				arr[j] = i + 1;
				break;
			}
			if(arr[j] == 0) a--;
		}
	}
	for(int i = 0; i < N; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
