#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int

using namespace std;

vector< pair<lli, lli> > P(100001);

int A[100001];

int main(){
	long long int n, k, p, m, t, e;
	fastIO
	IN n; IN k; IN p; IN m;
	if(p % m != 0){
		P[0] = MP(1, 0);
		e = 1;
		t = 1;
		while(e < 100001){
			t = (t * p) % m;
			P[e] = MP(t, e);
			e++;
		}
		sort(P.begin(), P.end());
		long long int i;
		for(i = 0; i < P.size() - 1; i++) if(P[i].F == P[i + 1].F) break;
		OUT i; newline;
		if(i < P.size() - 1){
			long long int u = P[i].S, v = P[i + 1].S;
			long long int j = u > v ? u : v;
			OUT u; space; OUT v; newline;
			// for(i = 0; i <= j; i++) A[i] = (rand() % k) + 1;
			// while(A[u] == A[v]) A[u] = (rand() % k) + 1;
			// for(int i = j; i >= 0; i++){
			// 	OUT A[i]; space;
			// }
			// newline;
			// swap(A[u], A[v]);
			// for(int i = j; i >= 0; i++){
			// 	OUT A[i]; space;
			// }
			// newline;			
		}
	}
	// if(t == 0) e = 0;
	// else{
	// 	P[0] = 1;
	// 	e = 1;
	// 	while(t != 1){
	// 		t = (t * t) % m;
	// 		e *= 2;
	// 	}
	// }
	// OUT e; newline;
	// srand (time(NULL));
	// if(e != 0){
	// 	for(int i = 0; i < e; i++) P[i] = (rand() % k) + 1;
	// 	for(int i = e; i < 2 * e; i++) P[i] = (rand() % k) + 1;
	// 	while(P[0] == P[e]) P[0] = (rand() % k) + 1;
	// 	int left;
	// 	if(e >= n) left = n - (2 * e) % n;
	// 	else if((2 * e) <= n) left = n - (2 * e);
	// 	else left = 2 * (n - e);
	// 	for(int i = 2 * e; i < 2 * e + left; i++) P[i] = (rand() % k) + 1;
	// 	for(int i = 2 * e + left - 1; i >= 0; i--){
	// 		OUT P[i]; space;
	// 	}
	// 	newline;
	// 	for(int i = 0; i < e; i++){
	// 		swap(P[i], P[i + e]);
	// 	}
	// 	for(int i = 2 * e + left - 1; i >= 0; i--){
	// 		OUT P[i]; space;
	// 	}
	// 	newline;
	// }
	// else{
	// 	for(int i = 0; i < n; i++) P[i] = (rand() % k) + 1;
	// 	while(P[0] == P[n - 1]) P[0] = (rand() % k) + 1;
	// 	for(int i = 0; i < n; i++){
	// 		OUT P[i]; space;
	// 	}
	// 	newline;
	// 	for(int i = n - 1; i >= 0; i--){
	// 		OUT P[i]; space;
	// 	}
	// 	newline;
	// }
	return 0;
}