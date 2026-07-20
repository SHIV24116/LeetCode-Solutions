class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        
        int p=nums[0];
        int p2=0;
        for(int i=1;i<n-1;i++){
            int x=p;
            p=max(p2+nums[i],p);
            p2=x;
        }
        int c=nums[1];
        p2=0;
        for(int i=2;i<n;i++){
            int x=c;
            c=max(p2+nums[i],c);
            p2=x;
        }
        cout<<p<<" "<<c<<endl;
        return max(p,c);
    }
};