class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int x = abs((int)a.size() - (int)b.size());
        if (a.size() > b.size()) {
            while (x--) b = '0' + b;
        } else {
            while (x--) a = '0' + a;
        }
        int c = 0;
        s.reserve(a.size() + 1);
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] == '1' && b[i] == '1') {
                if (c == 0) s.push_back('0');
                else s.push_back('1');
                c = 1;
            }
            else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
                if (c == 0) {
                    s.push_back('1');
                } else {
                    s.push_back('0');
                    c = 1;
                }
            }
            else { 
                if (c == 0) {
                    s.push_back('0');
                } else {
                    s.push_back('1');
                    c = 0;
                }
            }
        }
        if (c == 1) s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};
