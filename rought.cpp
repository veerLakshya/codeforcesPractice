#include<bits/stdc++.h>
using namespace std;
#define ll long long


const int N = 100001;
int spf[N], occupied[N], isActive[N];

void sieve() {
    for (int i = 1; i < N; i++) spf[i] = i;

    for (int i = 2; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<int>primeFactorise(int n) {
    vector<int>primes;
    while (n != 1) {
        int x = spf[n];
        while (n % x == 0) n /= x;
        primes.push_back(x);
    }
    return primes;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    sieve();
    for (int i = 1; i <= n; i++) {
        a = primeFactorise(i);
        for (auto i : a)cout << i << " ";
        cout << endl;
    }
}
