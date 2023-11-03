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
#include <cstdlib>
#include <limits>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    rep(i, n)
    {
        cin >> s[i];
    }
    vector<vector<int>> prefix_sum(n, vector<int>());

    rep(i, n)
    {
        int sum = 0;
        prefix_sum[i].push_back(0);
        rep(j, s[i].size())
        {
            sum += s[i][j] - '0';
            prefix_sum[i].push_back(sum);
        }
    }

    int count = 0;
    rep(i, n) rep(j, n)
    {
        int len_i = s[i].size();
        int len_j = s[j].size();
        int len = len_i + len_j;
        // if (s[i] != "5" || s[j] != "93746")
        //     continue;
        if (i == j)
            continue;
        if (len % 2 != 0)
            continue;
        int sum1 = 0;
        int sum2 = 0;
        // cout << "len / 2=" << len / 2 << ", len_i=" << len_i << endl;
        if (len_i < len / 2)
        {
            sum1 += prefix_sum[i][len_i];
            sum1 += prefix_sum[j][len / 2 - len_i];
            sum2 += prefix_sum[j][len_j] - prefix_sum[j][len / 2 - len_i];
        }
        else
        {
            sum1 += prefix_sum[i][len / 2];
            sum2 += prefix_sum[i][len_i] - prefix_sum[i][len / 2];
            sum2 += prefix_sum[j][len_j];
        }

        // cout << "sum1=" << sum1 << ", sum2=" << sum2 << endl;

        // rep(k, s[i].size() + s[j].size())
        // {
        //     if (k < s[i].size())
        //     {
        //         if (k < (s[i].size() + s[j].size()) / 2)
        //             sum1 += s[i][k] - '0';
        //         else
        //             sum2 += s[i][k] - '0';
        //     }
        //     else
        //     {
        //         if (k < (s[i].size() + s[j].size()) / 2)
        //             sum1 += s[j][k - s[i].size()] - '0';
        //         else
        //             sum2 += s[j][k - s[i].size()] - '0';
        //     }
        // }

        if (sum1 == sum2)
        {
            count++;
            // cout << s[i] << " " << s[j] << endl;
            // cout << "sum=" << sum1 << endl;
        }
    }

    count += n;

    cout << count << endl;

    return 0;
}
