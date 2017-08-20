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

using namespace std;


int main(){
	int t, n;
	double k, x, d;
	IN t; 
	for(int i = 0; i < t; i++){
		cin >> n >> k >> x >> d;
		double tot = 0;
		for(int j = 0; j < n; j++){
			int p;
			IN p;
			tot += maxnum(k, x / 100.0 * p);
		}
		if(tot <= d) OUT "fee\n";
		else OUT "upfront\n";
	}
	return 0;
}