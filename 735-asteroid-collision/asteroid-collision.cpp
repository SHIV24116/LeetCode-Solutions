class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++){
            if(ans.size()==0) ans.push_back(asteroids[i]);
            else if(asteroids[i]*ans.back()>0 || ans.back()<0) ans.push_back(asteroids[i]);
            else{ 
                int pres=asteroids[i];
                while(ans.back()>0 && pres<0){
                    if(ans.back()>abs(pres)){
                        pres=0;
                    }
                    else{
                        if(abs(pres)==ans.back()) pres=0;
                        ans.pop_back();
                        if(ans.size()==0) break;
                    }
                }
                if(pres<0) ans.push_back(pres);
            }
        }
        return ans;
        
    }
};