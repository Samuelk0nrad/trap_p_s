// https://cses.fi/problemset/task/3399/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if (a + b > n || (a != b && (a == 0 || b == 0))) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for (int i = 1; i <= n; ++i) {
    cout << i << " ";
  }

  cout << "\n";

  for (int i = a + 1; i <= b + a; ++i) {
    cout << i << " ";
  }

  for (int i = 1; i <= a; ++i) {
    cout << i << " ";
  }

  for (int i = a + b + 1; i <= n; ++i) {
    cout << i << " ";
  }

  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
