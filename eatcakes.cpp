#include <iostream>
#include <cmath>

using namespace std;

int eatcake(int n){
	int p = (int)floor(sqrt(n)), dp[p + 1][n + 1];
	for(int i = 0; i <= n; i++)dp[1][i] = i;
	for(int i = 2; i <= p; i++) dp[i][0] = 0;
	for(int i = 2; i <= p; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = INT_MAX;
			for(int k = 0; k * (i * i) <= j; k++){
				dp[i][j] = min(dp[i][j], dp[i - 1][j - k * (i * i)] + k);
			}
		}
	}
	return dp[p][n];
}

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << "Case #" << i + 1 << ": " << eatcake(n) << "\n";
	}
	return 0;
}