#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

void solve() {
    string s;
    cin >> s;
    string t = "hello";
    int j = 0;
    for (int i = 0;i < s.size();i++) {
        if (s[i] == t[j]) {
            j++;
        }
    }
    if (j == 5) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
}