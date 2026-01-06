#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll C = 1e9 + 7;

int main() {
  ll n;
  cin >> n;

  ll res = 1;
  while (n > 0) {
    ll p = n;
    if (n >= 31) {
      p = 31;
    }
    ll one = 1;
    ll sol = one << p;
    res = (res * sol) % C;
    n -= p;
  }

  cout << res % C;
}
