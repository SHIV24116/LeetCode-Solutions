class Solution {
public:
    class Node {
    public:
        Node* children[2];
        Node() {
            for(int i = 0; i < 2; i++) {
                children[i] = nullptr;
            }
        }
    };
    Node* root = new Node();

    void insert(int num) {
        Node* curr = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(curr->children[bit] == nullptr) {
                curr->children[bit] = new Node();
            }
            curr = curr->children[bit];
        }
    }

    int findMaxXOR(int x) {
        Node* curr = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int opposite = 1 - bit;
            if(curr->children[opposite] != nullptr) {
                ans |= (1 << i);
                curr = curr->children[opposite];
            }
            else {
                curr = curr->children[bit];
            }
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums,vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        // {m, x, original_index}
        vector<array<int, 3>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1],queries[i][0],i});
            //{m,x,originl_index}
        }
        sort(q.begin(), q.end());
        vector<int> answer(queries.size(), -1);
        int j = 0;
        for(auto query : q) {
            int m = query[0];
            int x = query[1];
            int index = query[2];
            // Insert all nums <= m....all no.s present in the trie during this will be <=m...so no need to check for this codition later
            while(j < nums.size() && nums[j] <= m) {
                insert(nums[j]);
                j++;
            }
            // If at least one valid number exists
            if(j > 0) {
                answer[index] = findMaxXOR(x);
            }
        }
        return answer;
    }
};