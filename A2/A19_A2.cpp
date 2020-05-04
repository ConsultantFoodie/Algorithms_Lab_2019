#include <bits/stdc++.h>

using namespace std;

extern void registerme ( int );
extern void startpart ( int );
extern void endpart ( int );
extern void makemove ( int , int , int );
extern void showpegs ( );

void ToH3(int i, int j, int p, int q, int r){
	if(i==j){
		makemove(j, p, q);
	}
	else{
		ToH3(i, j-1, p, r, q);
		makemove(j, p, q);
		ToH3(i, j-1, r, q, p);
	}
	return;
}

void ToH41(int i, int j, int p, int q, int r, int s){
	int m=j-i+1, k;
	k=m/2;
	if(m<=3){
		ToH3(i, j, p, q, r);
	}
	else{
		ToH41(i, i+m-k, p, s, r, q);
		ToH3(i+m-k+1, j, p, q, r);
		ToH41(i, i+m-k, s, q, r, p);
	}
}

void ToH42(int i, int j, int p, int q, int r, int s, int k){
	int m=j-i+1;
	if(m<=k){
		ToH3(i, j, p, q, r);
	}
	else{
		ToH41(i, i+m-k, p, s, r, q);
		ToH3(i+m-k+1, j, p, q, r);
		ToH41(i, i+m-k, s, q, r, p);
	}
	return;
}

void ToH43(int i, int j, int p, int q, int r, int s){
	int m=j-i+1, k;
	k=round(sqrt(m*2));
	if(m<=k){
		ToH3(i, j, p, q, r);
	}
	else{
		ToH41(i, i+m-k, p, s, r, q);
		ToH3(i+m-k+1, j, p, q, r);
		ToH41(i, i+m-k, s, q, r, p);
	}
	return;
}

int main(){
	int n;
	cin>>n;
	registerme(n);
	startpart(1); ToH41(1,n,0,1,2,3); endpart(1);
	startpart(2); ToH42(1,n,0,1,2,3, (int)sqrt(n)); endpart(2);
	startpart(3); ToH43(1,n,0,1,2,3); endpart(3);
	return 0;
}