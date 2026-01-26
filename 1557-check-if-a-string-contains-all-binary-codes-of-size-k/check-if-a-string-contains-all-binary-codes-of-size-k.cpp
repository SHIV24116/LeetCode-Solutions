class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        unordered_set<string>us;
        us.reserve(1 << k);

        for (int i = 0; i+k <= s.size(); i++) {
            us.insert(s.substr(i, k));
            if (us.size() == (1 << k))
                return true;
        }
        return false;
    }
};
