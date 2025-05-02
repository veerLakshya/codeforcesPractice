#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        arr[x].push_back(i);
        arr[i].push_back(x);
    }
    vector<int> sub(n + 1);

    function <int(int, int)> dfs = [&](int cur, int par) -> int {
        int cnt = 1;
        for (auto nbr : arr[cur]) {
            if (nbr == par) continue;
            cnt += dfs(nbr, cur);
        }
        sub[cur] = cnt - 1;
        return cnt;
        };

    dfs(1, -1);

    for (int i = 1; i <= n; i++) cout << sub[i] << " ";
}
