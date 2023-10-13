#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

long double dist(pair<int, int> a, pair<int, int> b)
{
    return hypot(a.first - b.first, a.second - b.second);
}

void solve()
{
    pair<int, int> O(0, 0);
    pair<int, int> P, A, B;

    cin >> P.first >> P.second >> A.first >> A.second >> B.first >> B.second;

    long double dPA = dist(P, A);
    long double dPB = dist(P, B);
    long double dOA = dist(O, A);
    long double dOB = dist(O, B);
    long double dOP = dist(O, P);
    long double dAB = dist(A, B);

    // cout << "dPA=" << dPA << ", dPB=" << dPB << endl;
    // cout << "dOA=" << dOA << ", dOB=" << dOB << ", dOP=" << dOP << endl;
    // cout << "dAB=" << dAB << endl;

    if (dPA <= dPB &&
        dOA <= dOB)
    {
        // O P ともに、 A が近いなら そのうちの距離が長い方
        // cout << "Case I" << endl;
        cout << setprecision(16) << max(dPA, dOA) << endl;
    }
    else if (dPB <= dPA &&
             dOB <= dOA)
    {
        // O P ともに、B が近い そのうちの距離が長い方
        // cout << "Case II" << endl;
        cout << setprecision(16) << max(dPB, dOB) << endl;
    }
    else
    {
        // O P がそれぞれ、A B のどちらかに近い場合
        // O P それぞれから、距離の近いランタンのうちの距離が長い方
        long double dO = min(dOA, dOB);
        long double dP = min(dPA, dPB);
        long double dL = max(dO, dP);

        // それが、A B 間の距離の半分より短いなら光が重なっていないので、距離が長い方
        // cout << "Case III" << endl;
        // cout << "dL=" << dL << ", dAB/2=" << dAB / 2.0 << endl;

        cout << setprecision(16) << max(dL, dAB / 2.0) << endl;
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
