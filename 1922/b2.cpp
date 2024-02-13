#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &ai : a)
        {
            cin >> ai;
        }

        sort(a.begin(), a.end());

        ll count = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (pow(2, a[i]) + pow(2, a[j]) > pow(2, a[k]))
                    {
                        cout << "a=" << pow(2, a[i]) << " " << pow(2, a[j]) << " " << pow(2, a[k]) << endl;
                        // Counting each valid combination
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}
