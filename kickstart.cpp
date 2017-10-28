#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int A[100001];

int get(int i){
	int sum = 0;
	while(i > 0){
		sum += A[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		A[i] += val;
		i += i & -i;
	}
}

int search(int i, int j, int x){
	int mid;
	while(i  < j){
		mid = (i + j) >> 1;
		if(x <= get(mid)) j = mid;
		else i = mid + 1;
	}
	return i;
}

int main(){
	int t, n, B[100000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		set<int> tr;
		for(int j = 0; j < n; j++){
			cin >> B[j];
			tr.insert(B[j]);
			update(n, j + 1, 1);
		}
		int j = 0;
		for(; j < n; j++){
			int idx = search(1, n, ceil((n - j) / 2.0));
			auto it = tr.find(B[idx - 1]);
			if(*it == *tr.begin() || *it == *tr.rbegin()){
				tr.erase(B[idx - 1]);
				update(n, idx, -1);
			}
			else break;
		}
		cout << "Case #" << i + 1 << ": " <<  (j < n ? "NO" : "YES") << "\n";
		for(int j = 0; j < n; j++) A[j + 1] = 0;
	}
	return 0;
}