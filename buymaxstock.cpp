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

using namespace std;

vector< pair<int, int > > A;

int main(){
	int n;
	long long int k;
	IN n;
	for(int i = 0; i < n; i++){
		int x;
		IN x;
		A.PB(MP(x, i + 1));
	}
	IN k;
	long long int tot_share = 0;
	sort(A.begin(), A.end());
	for(int i = 0; k >= A[i].F && i < n; i++){
		long long int t = k / A[i].F;
		if(t <= A[i].S){
			k -= A[i].F * t;
			tot_share += t;
		}
		else{
			k -= A[i].F * A[i].S;
			tot_share += A[i].S;
 		} 
	}
	OUT tot_share; newline;
	return 0;
}