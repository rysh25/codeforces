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
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        vector<string> s(n);

        for (int j = 0; j < n; j++)
        {
            cin >> s[j];
        }

        int people = 1;
        for (int j = 1; j < n; j++)
        {
            if (s[0] == s[j])
            {
                people++;
            }
        }

        cout << people << endl;
    }

    return 0;
}
