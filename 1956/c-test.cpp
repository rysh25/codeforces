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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, m;
    cin >> n >> s >> m;

    cerr << "n=" << n << ", s=" << s << ", m=" << m << endl; // debug
    vector<vector<int>> graph(n, vector<int>(n));

    rep(j, m)
    {
        int c, i;
        cin >> c >> i;
        i--;

        vector<int> a(n);

        rep(k, n)
        {
            cin >> a[k];
        }

        if (c == 1)
        {
            rep(k, n)
            {
                graph[i][k] = a[k];
            }
        }
        else
        {
            rep(k, n)
            {
                graph[k][i] = a[k];
            }
        }
    }

    cout << "graph:" << endl;
    rep(i, n)
    {
        rep(j, n)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
