// Round 1014 (Div. 2) - Codeforces A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int max = *max_element(a.begin(), a.end());
        int min = *min_element(a.begin(), a.end());

        int result = max - min;
        cout << result << endl;
    }
    return 0;
}

// Round 1014 (Div. 2) - Codeforces A
#include <bits/stdc++.h>
using namespace std;

void solve(int n, string a, string b)
{
    int o1 = 0,     // 1 at odd pos in a
        int o2 = 0; // 1 at even pos in a

    for (int i = 0; i < n; i++)
    {
        int pos = i + 1;
        if (pos % 2 == 1)
        {
            if (a[i] == '1')
                o1++;
        }
        else
        {
            if (a[i] == '1')
                o2++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int pos = i + 1;
        if (pos % 2 == 1)
        {
            if (b[i] == '1')
                o2++;
        }
        else
        {
            if (b[i] == '1')
                o1++;
        }
    }

    int c1 = n / 2;  // no of even positions
    int c2 = n - c1; // no of odd positions

    if (o1 <= c1 && o2 <= c2) // less than or equal to available positions
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        string a, b;
        cin >> a >> b;

        solve(n, a, b);
    }

    return 0;
}

// Leetcode ki streak bachane ke lie koi easy sa question   - ??