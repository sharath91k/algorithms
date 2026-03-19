// https://codeforces.com/problemset/problem/1837/D
// D. Bracket Coloring


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    
	    int pref = 0;
	    for (int i = 0; i < n; i++) {
	        if (s[i] == '(') pref++;
	        else pref--;
	    }
	    if (pref != 0) {
	        cout << -1 << endl;
	        continue;
	    }
	
	    
	    stack<int> st1, st2;
	    set<int> colors;
	    vector<int> res;
	    for (int i = 0; i < n; i++) {
	       if (s[i] == '(') {
	           if (!st2.empty()) {
	               res.push_back(2);
	               colors.insert(2);
	               st2.pop();
	           } 
	           else {
	                st1.push(1);
	                res.push_back(1);
                    colors.insert(1);
	           }
	       } 
	       else {
	           if (!st1.empty()) {
	               st1.pop();
	               res.push_back(1);
	               colors.insert(1);
	           } 
	           else {
	               st2.push(-1);
	               res.push_back(2);
                   colors.insert(2);
	           }
	       }
	    }
	    
	    
	    if (colors.size() == 1) {
	        cout << 1 << endl;
	        for (int i = 0; i < n; i++) cout << 1 << " ";
	    } else {
	        cout << 2 << endl;
	        for (int i = 0; i < n; i++) cout << res[i] << " ";
	    }
	    
	    cout << endl;
	    
	    
	}

}
