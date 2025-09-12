class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> m(numRows, vector<char>(s.size(), '\0'));
        int i = 0, j = 0, z = 0;
        int dir = 1;

        while (z < s.size()) {
            if (dir == 1) { 
                while (i < numRows && z < s.size()) {
                    if (j < s.size()) m[i][j] = s[z];
                    z++;
                    if (i == numRows - 1) {
                        dir = -1;
                        i--;
                        break;
                    } else i++;
                }
            } else { 
                if (j < s.size()) m[i][j] = s[z];
                z++;
                if (i == 0) {
                    dir = 1;
                    i++;
                } else i--;
            }
            if (dir == -1) j++;
            if (j >= s.size()) break;
        }

        string a = "";
        for (int l = 0; l < numRows; l++) {
            for (int k = 0; k < s.size(); k++) {
                if (m[l][k] != '\0') a.push_back(m[l][k]);
            }
        }
        return a;
    }
};
