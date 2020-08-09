#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <vector> 
#include <string>
using namespace std;
//���ֿռ������� 

int h=0,x;
vector <int> a;
//ȫ�ֱ��� 

void printqueen(int n){
	h++;
	int q[n][n];
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			q[i][j] = 0;
		}
	}
	for (int j = 0; j<n; j++){
		q[j][a[j]] = 1;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if (q[i][j]==0) printf("��");
			else printf("��");
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int check(int k){
	if(k==0) return 1;
	for(int i = 0; i < k; i++){
		if(a[i]==a[k] || abs(a[k]-a[i])==(k-i)) return 0;
	}
	return 1;
}

int findqueen(int n,int m){
	for(int i = 0; i<n; i++){
		a[m] = i;
		if(check(m) == 1){
			if(m + 1 == n) {
				if(x == 0){
					h++;
				}
				else{
					printqueen(n);
				}
			}
			
			else findqueen(n,m+1);
		}
	}
	a[m] = 0;
	return 0;
}
//���庯�� 

//������


int main(){
	int n;
	while(true){
		a.clear();
		printf("%s","�������м����ʺ�\n");
		cin >> n;
		if(n == 0){
			break;
		}
		else{
			printf("%s","�Ƿ����ͼ��\n��д1��ֻ�����ĸ���д0��\n");
			cin >> x;
			h = 0;
			for(int i=0; i<n; i++){
				a.push_back(0);
			}
			findqueen(n,0);
			printf("����%d���\n\n",h);
		}
	}
	return 0;
}
