// https://cses.fi/problemset/task/1092
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ll n;
  cin >> n;
  ll sum = n * (n + 1) / 2;
  if (sum % 2 == 1) {
    cout << "NO";
  } else {
    cout << "YES" << "\n";
    if (n % 2 == 0) {
      cout << n / 2 << "\n";
      for (int i = 1; i <= n / 4; ++i) {
        cout << i << " ";
      }
      for (int i = n * 3 / 4 + 1; i <= n; ++i) {
        cout << i << " ";
      }

      cout << "\n" << n / 2 << "\n";
      for (int i = n / 4 + 1; i <= n * 3 / 4; ++i) {
        cout << i << " ";
      }
    } else {
      cout << (n + 1) / 2 << "\n";
      int p = (n + 1) / 4;
      for (int i = 0; i < (n + 1) / 2; ++i) {
        int num = i * 2;
        if (i < p)
          num++;
        cout << num << " ";
      }
      cout << "\n";
      cout << n / 2 << "\n";
      for (int i = 1; i <= n / 2; ++i) {
        int num = i * 2;
        if (i >= p)
          num++;
        cout << num << " ";
      }
    }
  }
}
