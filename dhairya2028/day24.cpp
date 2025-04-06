class Solution {
public:
    int value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int total = 0;
    for (int i = 0; i < s.length(); i++) {
        int current = value(s[i]);
        int next = value(s[i + 1]);

        if (i + 1 < s.length() && current < next) {
            total += next - current;
            i++;
        } else {
            total += current;
        }
    }
    return total;
}
};
