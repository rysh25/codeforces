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
    vector<int> s(n + 1);

    int prev = -1;
    int xyz = 0;
    int count = 0;

    s[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] <= prev)
        {
            xyz++;
            // cout << "xyz: " << xyz << endl;
        }
        else
        {
            xyz = 0;
        }
        prev = a[i];

        if (xyz >= 2)
        {
            xyz = 0;
        }
        else
        {
            count++;
        }

        s[i + 1] = count;
    }

    // cout << "s: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << s[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        // cout << "l=" << l << ", r=" << r << endl;
        cout << s[r + 1] - s[l] << endl;
    }

    // cout << flush;

    return 0;
}
