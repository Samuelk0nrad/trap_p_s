#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll k) {
  ll res = 0;
  if (k == 1)
    return 0;
  if (k == 2)
    return 6;
  if (k == 3)
    return 28;
  res += 4 * (k * k - 3);
  res += 8 * (k * k - 4);
  res += 4 * (k * k - 5);
  res += 4 * (k - 4) * (k * k - 5);
  res += 4 * (k - 4) * (k * k - 7);
  res += (k - 4) * (k - 4) * (k * k - 9);
  return res / 2;
}

int main() {
  ll n;
  cin >> n;

  for (ll i = 1; i <= n; ++i) {
    ll res = solve(i);
    cout << res << "\n";
  }
}
