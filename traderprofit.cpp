#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

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
using namespace std;

int P[1001][11];
struct{ int s, e, w, l;} intervals[1001];

int main(){
//	fastIO
	int q; 
	IN q;
	for(int i = 0; i < q; i++){
		int t, n, A[30], ints = 0;
		IN t; IN n;
		for(int j = 0; j < n; j++) IN A[j];
		for(int j = 0; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				if(A[j] < A[k]){
					intervals[ints].s = j;
					intervals[ints].e = k;
					intervals[ints].l = 1;
					intervals[ints].w = A[k] - A[j];
					ints++;
				}
			}
		}
		for(int j = 0; j < ints; j++) P[j][1] = intervals[j].w;
		for(int j = 0; j < ints; j++){
			for(int k = j - 1; k >= 0; k--){
				if(intervals[j].s > intervals[k].e){
					for(int m = intervals[k].l; m >= 1; m--){
						if(intervals[j].l < m + 1){
							P[j][m + 1] = P[k][m] + intervals[j].w;
						}
						else if(P[k][m] + intervals[j].w > P[j][m + 1]){
							P[j][m + 1] = P[k][m] + intervals[j].w;
						}
					}
					intervals[j].l = maxnum(intervals[k].l + 1, intervals[j].l);
				}
			}
		}
		int m = -1;
		for(int j = 0 ; j < ints; j++){
			for(int k = 1; k <= t; k++){
				if(P[j][k] > m) m = P[j][k];				
			}
		}
		OUT (m < 0 ? 0 : m); newline;
		for(int j = 0 ; j < ints; j++){
			for(int k = 1; k <= 10; k++){
				P[j][k] = 0;
			}
		}
	}
	return 0;
}
