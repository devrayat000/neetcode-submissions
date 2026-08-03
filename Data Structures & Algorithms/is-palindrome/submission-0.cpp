class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (!isAlphanumeric(s[l]))
                l++;
            while (!isAlphanumeric(s[r]))
                r--;
            if (!isEqual(s[l], s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
private:
    bool isEqual(char a, char b)  {
        return tolower(static_cast<unsigned char>(a)) == tolower(static_cast<unsigned char>(b));
    }
    bool isAlphanumeric(char ch) {
        return (ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z') || 
           (ch >= '0' && ch <= '9');
    }
};
