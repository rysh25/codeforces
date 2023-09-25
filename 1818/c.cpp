#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    int n, q;

    cin >> n >> q;

    vector<int> a(n);
    vector<int> p(n);

    // cout << "a: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;

    p[0] = 0;
    int downhill = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] >= a[i] && a[i] >= a[i + 1])
            downhill++;

        p[i] = downhill;
    }

    // cout << "p: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << p[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        // cout << "l=" << l << ", r=" << r << endl;
        if (r - l <= 1)
        {
            cout << (r - l + 1) << endl;
        }
        else
        {
            cout << (r - l + 1) + p[l] - p[r - 1] << endl;
        }
    }

    return 0;
}
