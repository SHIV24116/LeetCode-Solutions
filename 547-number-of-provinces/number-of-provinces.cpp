class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> v(n);

        for(int i=0;i<n;i++)
            v[i]=i;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(isConnected[i][j]==1){

                    int oldCode = v[j];
                    int newCode = v[i];

                    for(int k=0;k<n;k++){

                        if(v[k]==oldCode)
                            v[k]=newCode;
                    }
                }
            }
        }

        sort(v.begin(),v.end());

        v.erase(unique(v.begin(),v.end()),v.end());

        return v.size();
    }
};