#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<char, int> freq;

    for (auto c : s)
    {
        freq[c]++;
    }

    int deleteCount = k;
    for (auto [c, f] : freq)
    {
        if (deleteCount == 0)
        {
            break;
        }

        if (f % 2 == 1)
        {
            freq[c] -= 1;
            deleteCount -= 1;
        }
    }

    for (auto [c, f] : freq)
    {
        if (deleteCount == 0)
        {
            break;
        }

        if (f > deleteCount)
        {
            freq[c] -= deleteCount;
            deleteCount = 0;
        }
        else
        {
            deleteCount -= freq[c];
            freq[c] = 0;
        }
    }

    int oddCount = 0;
    int count = 0;

    for (auto [c, f] : freq)
    {
        if (f % 2 == 1)
        {
            oddCount += 1;
        }
        count += f;
    }

    // cout << "count=" << count << ", oddCount=" << oddCount << ", deleteCount=" << deleteCount << endl;

    if (count % 2 == 0)
    {
        if (oddCount == 0)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    {
        if (oddCount == 1)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
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
