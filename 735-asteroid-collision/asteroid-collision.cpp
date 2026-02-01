class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i = 0; i < asteroids.size(); i++) {
            int pres = asteroids[i];
            while(!ans.empty() && ans.back() > 0 && pres < 0) {
                if(ans.back() > abs(pres)) {
                    pres = 0;
                    break;
                } else if(ans.back() == abs(pres)) {
                    ans.pop_back();
                    pres = 0;
                    break;
                } else {
                    ans.pop_back();
                }
            }
            if(pres != 0) ans.push_back(pres);
        }
    return ans;    
    }
};