// 38 LeetCode
class Solution
{
public:
    string rle(string s)
    {
        int n = s.size();
        if (n == 1)
            return "11";
        string a = "";
        int cnt = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                cnt++;
            else
            {
                a += to_string(cnt);
                a += s[i];
                cnt = 1;
            }
        }
        a += to_string(cnt);
        a += s[n - 1];
        return a;
    }

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        cout << s << endl;
        return rle(s);
    }
};
// T.C O(2^n)
// S.C O(n)
