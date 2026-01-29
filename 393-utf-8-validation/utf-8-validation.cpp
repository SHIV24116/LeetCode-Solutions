class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int i = 0;

        while (i < n) {
            int ct = 0;
            int byte = data[i] & 255;  /// keep only leading 8 bits of each byte

            for (int bit = 7; bit >= 0; bit--) {
                if (((byte >> bit) & 1) == 1) ct++;
                else break;
            }

            if (ct == 1 || ct > 4) return false;
            if (ct == 0) {
                i++;
                continue;
            }

            if (i + ct > n) return false;

            for (int j = 1; j < ct; j++) {
                if (((data[i + j] >> 6) & 3) != 2)
                    return false;
            }
            i += ct;
        }
        return true;
    }
};
