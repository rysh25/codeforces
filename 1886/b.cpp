#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

double dist(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve()
{
    pair<int, int> O(0, 0);
    pair<int, int> P, A, B;
    cin >> P.first >> P.second >> A.first >> A.second >> B.first >> B.second;

    double dPA = dist(P, A);
    double dPB = dist(P, B);
    double dOA = dist(O, A);
    double dOB = dist(O, B);
    double dOP = dist(O, P);
    double dAB = dist(A, B);

    // cout << "dPA=" << dPA << ", dPB=" << dPB << endl;
    // cout << "dOA=" << dOA << ", dOB=" << dOB << ", dOP=" << dOP << endl;
    // cout << "dAB=" << dAB << endl;

    if (dPA <= dPB &&
        dOA <= dOB)
    {
        // 両方とも A が近いなら その遠い方
        cout << (dPA <= dOA ? dOA : dPA) << endl;
    }
    else if (dPA <= dPB &&
             dOA <= dOB)
    {
        // 両方とも B が近い その遠い方
        cout << (dPB <= dOB ? dOB : dPB) << endl;
    }
    else
    {
        double dist_min_p_light = dPA < dPB ? dPA : dPB;
        double dist_min_o_light = dOA < dOB ? dOA : dOB;

        double half_dAB = dAB / 2;

        if (dist_min_p_light <= half_dAB &&
            dist_min_o_light <= half_dAB)
        {
            // 両方が A と B の間を照らした場合に含まれるなら
            cout << half_dAB << endl;
        }
        else
        {
            double l = (dist_min_p_light <= dist_min_o_light ? dist_min_o_light : dist_min_p_light);
            cout << l << endl;
        }
    }

    cout << "dist_min_p_light=" << dist_min_p_light << ", dist_min_o_light=" << dist_min_o_light << endl;
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
