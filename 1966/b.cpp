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
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    rep(i, n)
    {
        cin >> grid[i];
    }

    auto found_in_row = [&](int row, char c)
    {
        rep(j, m)
        {
            if (grid[row][j] == c)
            {
                return true;
            }
        }

        return false;
    };

    auto found_in_col = [&](int col, char c)
    {
        rep(i, n)
        {
            if (grid[i][col] == c)
            {
                return true;
            }
        }

        return false;
    };

    char colors[2] = {'B', 'W'};

    bool ok = false;
    rep(x, 2)
    {
        char c = colors[x];

        if (grid[0][0] == grid[n - 1][m - 1] ||
            grid[n - 1][0] == grid[0][m - 1])
        {
            ok = true;
            break;
        }
        else if (c == grid[0][0] &&
                 grid[0][0] == grid[n - 1][0])
        {
            if (found_in_col(m - 1, c))
            {
                ok = true;
                break;
            }
        }
        else if (c == grid[0][m - 1] &&
                 grid[0][m - 1] == grid[n - 1][m - 1])
        {
            if (found_in_col(0, c))
            {
                ok = true;
                break;
            }
        }
        else if (c == grid[0][0] &&
                 grid[0][0] == grid[0][m - 1])
        {
            if (found_in_row(n - 1, c))
            {
                ok = true;
                break;
            }
        }
        else if (c == grid[n - 1][0] &&
                 grid[n - 1][0] == grid[n - 1][m - 1])
        {
            if (found_in_row(0, c))
            {
                ok = true;
                break;
            }
        }
    }

    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
