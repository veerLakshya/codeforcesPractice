#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    vector<pair<int, int>> pq; // (frequency, character index)
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) pq.push_back({ freq[i], i });
    }

    sort(pq.begin(), pq.end()); // Sort by frequency first, then lexicographically

    if (pq.size() > 1) cout << char(pq[1].second + 'a'); // Second least frequent
    else cout << -1;

    return 0;
}
