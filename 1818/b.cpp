#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        for (int j = 0; j < n; j++)
        {
            a[j] = j + 1;
        }

        auto print_permutation = [&]()
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        };

        // cout << "n=" << n << endl;
        do
        {
            // cout << "a: ";
            // print_permutation();

            bool found = true;
            for (int l = 0; l < n - 1; l++)
            {
                // cout << "l=" << l << endl;
                for (int r = l + 1; r < n; r++)
                {
                    // cout << "r=" << r << endl;
                    int sum = 0;
                    for (int k = l; k <= r; k++)
                        sum += a[k];

                    if (sum % (r - l + 1) != 0)
                    {
                        // cout << "n=" << n << ", l=" << l << ", r=" << r;
                        // cout << ", sum=" << sum;
                        // cout << ", r-l+1=" << (r - l + 1) << endl;
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
            }

            if (found)
            {
                // cout << "found" << endl;
                print_permutation();
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
    }

    cout << -1 << endl;

    return 0;
}
