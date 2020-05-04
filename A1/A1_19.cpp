//Written by Hardik Tibrewal
//18EC10020

#include <bits/stdc++.h>
#define LIM 1000000000

using namespace std;

extern void registerme ( );
extern void startgame ( int );
extern int valquery ( int );
extern int sgnquery ( int );
extern int delquery ( int );
extern int sumquery ( int );
extern void checksoln ( int, int );

void playgame0(){
	startgame(0);
	int q;
	for(q=0;q<LIM;q++){
		if(valquery(q)!=q){
			break;
		}
	}
	checksoln(q, valquery(q));
	return;
}

void bs(int l, int r, int* L, int* R){
	int mid = (r+l)/2, ans;

	if(r<l || *L>=0 || *R>=0) return;

	ans = valquery(mid);

	if(mid<ans){
		*L = mid;
		*R = ans;
	}
	else if(ans<mid){
		*L = ans;
		*R = mid;
	}
	else{
		bs(l, mid-1, L, R);
		bs(mid+1, r, L, R);		
	}
}

int find(int l, int r){
	int mid=(r+l)/2, s;
	s = sgnquery(mid);
	if(s==0 || l==r){
		return mid;
	}
	else{
		if(s>0) return find(l, mid);
		else return find(mid+1, r);
	}
}

void playgame1(){
	startgame(1);
	int L=-1, R=-1;
	bs(0, LIM-1, &L, &R);
	checksoln(L, R);
	return;
}

void playgame2(){
	startgame(2);
	int ans, del;
	ans = find(0, LIM-1);
	del=delquery(0);
	int L, R;
	ans*=2;
	//if(del%2) ans++;
	R = (ans+del)/2;
	L = R - del;
	checksoln(L, R);
	return;
}

void playgame3(){
	startgame(3);
	int a1, a2, L, R;
	a1 = sumquery(0);
	a2 = sumquery(a1/2);
	L = (a1-a2)/2;
	R = (a1+a2)/2;
	checksoln(L, R);
}

int main(int argc, char** argv){
	registerme();
	playgame0();
	playgame1();
	playgame2();
	playgame3();
	return 0;
}