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
    
    Node* root=new Node();
    // Insert a number into the Trie
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
    // Find maximum XOR possible with num
    int findMaxXOR(int num) {
        Node* curr = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // For maximum XOR, we want the opposite bit
            int opposite = 1 - bit;
            if(curr->children[opposite] != nullptr) {
                // This bit of XOR becomes 1
                ans |= (1 << i);
                curr = curr->children[opposite];
            }
            else {
                // Opposite bit doesn't exist
                curr = curr->children[bit];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        // Put all numbers into the Trie
        for(int num : nums) {
            insert(num);
        }
        int ans = 0;
        // Find the best XOR for every number
        for(int num : nums) {
            ans = max(ans, findMaxXOR(num));
        }
        return ans;
    }
};