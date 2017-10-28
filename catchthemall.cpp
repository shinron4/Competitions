#include <iostream>
#include <climits>
#include <iomanip>

#define MAX 100

using namespace std;


void floydwarshall(int A[MAX][MAX], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++) A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
		}
	}
}

double catchc(int A[MAX][MAX], int n, int p){
	double sum = 0, prob[p][n];
	for(int i = 0; i < n; i++){
		prob[0][i] = i == 0 ? 0.0 : 1.0 / (n - 1);
		sum += prob[0][i] * A[0][i];
	}
	for(int i = 1; i < p; i++){
		for(int j = 0; j < n; j++){
			prob[i][j] = 0;
			for(int k = 0; k < n; k++){
				prob[i][j] += k != j ? prob[i - 1][k] / (n - 1) : 0;
				sum += prob[i - 1][k] * A[k][j] / (n - 1);
			}
		}
	}
	return sum;
}

int main(){
	int t, n, m, p, A[MAX][MAX];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m >> p;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				A[j][k] = j != k ? 100000 : 0;
			}
		}
		for(int j = 0; j < m; j++){
			int x, y, w;
			cin >> x >> y >> w;
			A[x - 1][y - 1] = w;
			A[y - 1][x - 1] = w;
		}
		floydwarshall(A, n);
		cout << "Case #" << i + 1 << ": ";
		cout << fixed << setprecision(6) << catchc(A, n, p) << "\n";
	}
	return 0;
}