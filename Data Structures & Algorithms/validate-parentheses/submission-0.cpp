class Solution {
private:
    unordered_map<char, char> braMap = {
        {'(', ')'}, 
        {'{', '}'}, 
        {'[', ']'},
    };
public:
    bool isValid(string s) {
        stack<char> start;
        for (const char& c : s) {
            if (braMap.contains(c))
                start.push(c);
            else if (start.size() == 0 || braMap[start.top()] != c)
                return false;
            else
                start.pop();
        }
        return start.size() == 0;
    }
};
