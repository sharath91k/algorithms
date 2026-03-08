#include <bits/stdc++.h>
using namespace std;


void precompute(vector<int> &arr, vector<vector<int>> &sparse, int n) {
    
    for (int i = 1; i <= n; i++)
        sparse[0][i] = arr[i];
        
    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 1; i <= n; i++) {
            
            if ((i + (1 << k) - 1) <= n) {
                sparse[k][i] = sparse[k-1][i] & sparse[k-1][i + (1 << (k-1))];
            }
        }
    }
}

int query(vector<vector<int>> &sparse, int l, int r) {
    int len = r - l + 1;
    
    int k = __lg(len);
    
    return sparse[k][l] & sparse[k][r - (1 << k) + 1];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    vector<int> arr(n+1);
	    for (int i = 1; i <= n; i++) {
	        cin >> arr[i];
	    }
	    
	    int LOG = __lg(n);
	    vector<vector<int>> sparse(LOG + 1, vector<int> (n + 1, 0));
	    
	    precompute(arr, sparse, n);
	    
	    int q;
	    cin >> q;
	    while (q--) {
            int l, v;
            cin >> l >> v;
            
            int le = l, ri = n + 1;
            while (ri > le + 1) {
                int mid = le + (ri - le) / 2;
                if (query(sparse, l, mid) >= v) le = mid;
                else ri = mid;
            }
            if (le == l) {
                if (sparse[0][l] >= v) cout << l << " ";
                else cout << -1 << " ";
            } else cout << le << " ";
            
        }
        
        cout << endl;
	      
	}

}
