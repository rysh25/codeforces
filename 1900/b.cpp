#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int a_parity = a % 2;
    int b_parity = b % 2;
    int c_parity = c % 2;

    if (a_parity == b_parity && b_parity == c_parity)
    {
        cout << "1 1 1" << endl;
    }
    else if (a_parity == b_parity)
    {
        cout << "0 0 1" << endl;
    }
    else if (b_parity == c_parity)
    {
        cout << "1 0 0" << endl;
    }
    else if (a_parity == c_parity)
    {
        cout << "0 1 0" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
