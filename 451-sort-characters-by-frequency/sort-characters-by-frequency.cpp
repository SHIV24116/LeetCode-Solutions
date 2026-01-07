class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        // 1. Count frequency
        for (char c : s) {
            m[c]++;
        }
        // 2. Move to vector
        vector<pair<char, int>> v;
        for (auto &p : m) {
            v.push_back({p.first, p.second});
        }
        // 3. Sort by frequency (descending)
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        // 4. Build result
        string result;
        for (auto &p : v) {
            result.append(p.second, p.first);
        }
        return result;
    }
};
