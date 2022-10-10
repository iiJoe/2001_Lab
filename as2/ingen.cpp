/**
 * ingen.cpp
 *
 * Written on Monday,10 October 2022.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;

#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define sz(a) ((int) ((a).size()))

const int MOD = 1e9 + 7;
const ld PI = atan(1) * 4;
const char nl = '\n';

void solve()
{
  int n = 10000;
  cout << n << nl;
  FOR(i, 1, n + 1) {
    cout << i << " ";
    FOR(j, 1, n + 1) {
      if (i != j && rand() % 100 < 5) {
        cout << j << "," << rand() % 10000 << " ";
      }
    }
    cout << nl;

  }

  cout << nl;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
}
