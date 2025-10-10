class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int sum=INT_MIN;
        int n=energy.size();
        vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            if(i+k<n)  v[i]=energy[i]+v[i+k];
            else v[i]=energy[i];
            sum=max(sum,v[i]);
        }
        return sum;
    }
};