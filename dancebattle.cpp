#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	int t, e, n, h, r[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> e >> n;
		for(int j = 0; j < n; j++) cin >> r[j];
		sort(r, r + n);
		h = 0;
		if(e > r[0]){
			int p = 0, q  = n - 1;
			while(1){
				while(p <= q && e > r[p]){
					h++;
					e -= r[p++];
				}
				if(p < q && h > 0 && e + r[q] > r[p]){
					e += (r[q] - r[p]);
					p++;
					q--;
				}
				else break;
			}
			if(p == q && e > r[p]) h++;
		}
		cout << "Case #" << i + 1 << ": " << h << "\n";
	}
	return 0;
}