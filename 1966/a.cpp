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
    int n, k;
    cin >> n >> k;
    vector<int> freq(101, 0);

    rep(i, n)
    {
        int a;
        cin >> a;
        freq[a]++;
    }

    priority_queue<int> pq;

    rep(i, 101)
    {
        if (freq[i] > 0)
        {
            pq.push(freq[i]);
        }
    }

    int ans = 0;
    int add = 0;

    while (pq.size() > 0)
    {
        int a = pq.top();
        pq.pop();
        // cerr << "a: " << a << " add: " << add << endl;

        if (a + add >= k)
        {
            if (a < k)
            {
                add -= k - a;
                pq.push(0);
            }
            else
            {
                pq.push(a - k);
            }
            ans += k;
            // cerr << "add: " << add << " a: " << a << " k: " << k << endl;
            add += k - 1;
            n += k - 1;
            // cerr << "add: " << add << " a: " << a << " k: " << k << " ans: " << ans << endl;
        }
        else
        {
            break;
        }
    }

    cout << n - ans << endl;
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
