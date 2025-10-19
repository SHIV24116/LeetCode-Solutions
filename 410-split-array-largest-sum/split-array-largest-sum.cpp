class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int h=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            h+=nums[i];
            l=max(l,nums[i]);
        }while(l<=h){
            int m=(l+h)/2;
            if(cansplit(nums,m,k)){
                ans=m;
                h=m-1;
            }else l=m+1;
        }
        return ans;    
    }
    bool cansplit(vector<int>& nums,int m,int k){
        int splits=1;
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(x+nums[i]>m){
                splits++;
                x=0;
            }
            x+=nums[i];
        }
        return splits<=k;
    }
        
};
// auto init = atexit( []() { ofstream( "display_runtime.txt" ) << "0"; } );
