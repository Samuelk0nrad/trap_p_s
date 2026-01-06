// https://cses.fi/problemset/task/1754/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;

  if (min(a, b) < max(a, b) / 2) {
    cout << "NO";
  } else if ((a + b) % 3 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  //  if (a == b) {
  //    if (a % 3 == 0) {
  //      cout << "YES";
  //    } else {
  //      cout << "NO";
  //    }
  //  } else {
  //    if (a < b) {
  //      int temp = a;
  //      a = b;
  //      b = temp;
  //    }
  //    int s = a / 2;
  //    b = b - s;
  //    if (a % 2 == 1) {
  //      b -= 2;
  //    }
  //    if (b == 0) {
  //      cout << "YES";
  //    } else if (b < 0) {
  //      cout << "NO";
  //    } else if (b % 3 == 0) {
  //      cout << "YES";
  //    } else {
  //      cout << "NO";
  //    }
  //  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
