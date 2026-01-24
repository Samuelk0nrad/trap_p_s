#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
  } else if (n <= 3) {
    cout << "NO SOLUTION\n";
  } else {
    for (int i = n - 1; i >= 1; i -= 2) {
      cout << i << " ";
    }
    for (int i = n; i >= 1; i -= 2) {
      cout << i << " ";
    }
  }
}
