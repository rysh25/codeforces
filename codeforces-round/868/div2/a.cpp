#include <iostream>

#define endl '\n'

using namespace std;

long long combi(long long n, long long k)
{
    if (n == k || k == 0)
        return 1;
    else
    {
        return combi(n - 1, k - 1) + combi(n - 1, k);
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        // cout << "n=" << n << ", k=" << k << endl;

        bool found = false;
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            if (j != 0 && j != 1)
            {
                // cout << "combi(" << j << ", 2)=" << combi(j, 2) << endl;
                count += combi(j, 2);
            }

            if (n - j != 0 && n - j != 1)
            {
                // cout << "combi(" << n - j << ", 2)=" << combi(n - j, 2) << endl;
                count += combi(n - j, 2);
            }

            // cout << "j=" << j << ", n-j=" << n - j << ", count=" << count << endl;

            if (count == k)
            {
                found = true;
                cout << "YES" << endl;

                for (int l = 0; l < n; l++)
                {
                    if (l < j)
                        cout << "1 ";
                    else
                        cout << "-1 ";
                }
                cout << endl;
                break;
            }
        }

        if (!found)
            cout << "NO" << endl;
    }
}
