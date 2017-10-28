#include <iostream>

using namespace std;

void build(int seg[], int a[], int n){
	for(int i = 1; i <= n; i++) seg[i + n - 1] = a[i];
	for(int i = n - 1; i >= 1; i--) seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
}

int query(int seg[], int n, int l, int r){
	int mi = INT_MAX;
	for(l += n - 1, r += n - 1; l < r; l >>= 1, r >>= 1){
		if(l & 1) mi = min(mi, seg[l++]);
		if(r & 1) mi = min(mi, seg[--r]);
	}
	return mi;
}

int seg[40][100], mat[41][41], dp[41][41][41][41], n, m;

int findminval(int i, int j, int p, int q){
	int mi = INT_MAX;
	for(int l = i; l <= p; l++) mi = min(mi, query(seg[l], m, j, q + 1));
	return mi;
}

void findmax(int r, int c){
	for(int i = 1; i <= n - r + 1; i++){
		for(int j = 1; j <= m - c + 1; j++){
			int p = i + r - 1, q = j + c - 1;
			int mi = findminval(i, j, p, q), s = 0;
			if(i == p && j == q) dp[i][j][p][q] = 0;
			else{
				if(j < q){
					for(int v = j; v < q; v++)
						s = max(s, dp[i][j][p][v] + dp[i][v + 1][p][q]);
				}
				if(i < p){
					for(int h = i; h < p; h++)
						s = max(s, dp[i][j][h][q] + dp[h + 1][j][p][q]);
				}
				dp[i][j][p][q] = mi + s;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	for(int test = 0; test < t; test++){
		cin >> n >> m;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= m; k++){
				cin >> mat[j][k];
			}
			build(seg[j], mat[j], m);
		}
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= m; k++){
				findmax(j, k);
				findmax(k, j);
			}
		}
		cout << "Case #" << test + 1 << ": " << dp[1][1][n][m] << "\n";
	}
	return 0;
}