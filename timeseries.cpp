#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define maxnum(a, b) ((a) > (b) ? (a) : (b))
#define minnum(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int A[100001];
void setP(int n, int i, int v){
	while(i <= n){
		A[i] = maxnum(A[i], v); 
		i += i & -i;
	}
}

int getP(int i){
	int m = -1;
	while(i > 0){
		if(A[i] > m) m = A[i];
		i -= i & -i;
	}
	return m;
}

int T[100001];
int searchT(int i, int j, int x){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(x <= T[mid]) j = mid;
		else i = mid + 1;
	}
	return i;
}

int B[100001];
void setT(int n, int i, int v){
	while(i <= n){
		B[i] = minnum(B[i], v); 
		i += i & -i;
	}
}

int getT(int i){
	int m = INT_MAX;
	while(i > 0){
		if(B[i] < m) m = B[i];
		i -= i & -i;
	}
	return m;
}

vector< pair<int, int> > P, Q; 
int searchP(int i, int j, int x){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(x <= Q[mid].F) j = mid;
		else i = mid + 1;
	}
	return i;
}

int main(){
	int n, q, t, v, idx;
	fastIO
	IN n; IN q;
	for(int i = 0; i < n; i++){
		IN T[i];
		P.PB(MP(-1, i));
	}
	for(int i = 0; i < n; i++){
		int x;
		IN x;
		P[i].F = x;
	}
	for(int i = 0; i < n; i++) setP(n, i + 1, P[n - 1 - i].F);
	sort(P.begin(), P.end());
	Q.PB(P[0]);
	for(int i = 1; i < n; i++) if(Q[Q.size() - 1].F != P[i].F) Q.PB(P[i]);
	for(int i = 0; i < Q.size(); i++) B[i] = INT_MAX;
	for(int i = 0; i < Q.size(); i++) setT(Q.size(), i + 1, Q[Q.size() - 1 - i].S);
	for(int i = 0; i < q; i++){
		IN t; IN v;
		if(t == 1){
			idx = searchP(0, Q.size() - 1, v);
			OUT (Q[idx].F >= v ? T[getT(Q.size() - idx)] : -1); newline;
		}
		else{
			idx = searchT(0, n - 1, v);
			OUT (T[idx] >= v ? getP(n - idx) : -1); newline;
		}
	}
	return 0;
}