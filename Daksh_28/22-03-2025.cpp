// 443 LeetCode
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();

        int index = 0;
        int i = 0;
        while (i < n)
        {
            char curr = chars[i];
            int count = 0;

            while (i < n && chars[i] == curr)
            {
                count++;
                i++;
            }
            chars[index] = curr;
            index++;

            if (count > 1)
            {
                string count_str = to_string(count);

                for (char &ch : count_str)
                {
                    chars[index] = ch;
                    index++;
                }
            }
        }
        return index;
    }
};
// T.C. O(N)
// S.C. O(1)

// 1832 LeetCode
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> arr(26, 0);
        for (char &ch : sentence)
        {
            int index = ch - 'a';
            arr[index]++;
        }
        for (int &count : arr)
        {
            if (count == 0)
            {
                return false;
            }
        }
        int n = sentence.size();
        if (n < 26)
        {
            return false;
        }
        return true;
    }
};
// T.C. O(N)
// S.C. O(1)
