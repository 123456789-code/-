#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <vector> 
#include <string>
using namespace std;
//名字空间与引用 

int h=0,x;
vector <int> a;
//全局变量 

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
			if (q[i][j]==0) printf("□");
			else printf("■");
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
//定义函数 

//主函数


int main(){
	int n;
	while(true){
		a.clear();
		printf("%s","请输入有几个皇后\n");
		cin >> n;
		if(n == 0){
			break;
		}
		else{
			printf("%s","是否输出图形\n是写1，只输出解的个数写0。\n");
			cin >> x;
			h = 0;
			for(int i=0; i<n; i++){
				a.push_back(0);
			}
			findqueen(n,0);
			printf("共有%d组解\n\n",h);
		}
	}
	return 0;
}
