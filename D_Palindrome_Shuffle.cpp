#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int k, string s) {
    int n = s.size();
    int m = n / 2 - 1;
    for (int i = k; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])return false;
    }
    multiset<char> left, right;
    for (int i = 0; i < k; i++) left.insert(s[i]);
    for (int i = n - 1; i >= k && i >= n - k; i--)
        if (left.find(s[i]) != left.end())left.erase(left.find(s[i]));
        else return false;
    return true;
}

void ekbaar() {
    string s; cin >> s;
    int n = s.size();
    // cout << n;
    int l = 0, r = n - 1;
    while (l < r && s[l] == s[r])l++, r--;
    if (l >= r) {
        cout << "0\n";
        return;
    }
    string x = "";
    for (int i = l; i <= r; i++) x += s[i];
    string t = x;
    reverse(t.begin(), t.end());

    l = 0, r = x.size() - 1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, x) || check(mid, t)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) ekbaar();
    return 0;
}