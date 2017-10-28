#include <iostream>
#include <cmath>

using namespace std;

int power(int a, int n, int m){
	long long int z = 1;
	int b = (int)log2(n) + 1;
	for(int j = 1 << (b - 1); j > 0; j >>= 1){
		z = (z * z) % m;
		if(n & j) z = (z * a) % m;
	}
	return z;
}

int main(){
	int t, a, n, p;
	cin >> t;
	for(int j = 0; j < t; j++){
		cin >> a >> n >> p;
		int x = a;
		for(int i = 1; i <= n; i++) x = power(x, i, p);
		cout << "Case #" << j + 1 << ": " << x << "\n";
	}
	return 0;
}