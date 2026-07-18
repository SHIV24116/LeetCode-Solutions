class Solution {
public:
    vector<int> par, size;

    int findUPar(int node) {
        if (node == par[node]) return node;
        return par[node] = findUPar(par[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        } else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        par.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) par[i] = i;
        unordered_map<string, int> mp;  //stores the index of the vector in which particular email if found

        //Union accounts sharing an email
        for (int i=0;i<n;i++) {
            for (int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    unionBySize(i,mp[mail]);
                }
            }
        }
        //Collect emails according to parent
        vector<vector<string>> mergedMails(n);
        for(auto &it:mp) {
            string mail=it.first;
            int account=it.second;
            int parent=findUPar(account);
            mergedMails[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMails[i].empty()) continue;
            sort(mergedMails[i].begin(),mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &mail:mergedMails[i]) temp.push_back(mail);
            ans.push_back(temp);
        }
        return ans;
    }
};