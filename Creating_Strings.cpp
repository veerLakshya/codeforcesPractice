#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    vector<int> freq(26, 0);
    vector<string> ans;
    for (auto i : s) freq[i - 'a']++;

    function<void(string)> helper = [&](string cur)->void {
        if ((ll)(cur.size() == n)) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (!freq[i]) continue;
            freq[i]--;
            helper(cur + (char)('a' + i));
            freq[i]++;
        }

        };

    helper("");

    cout << ans.size() << endl;
    for (auto i : ans) cout << i << endl;

    return 0;
}