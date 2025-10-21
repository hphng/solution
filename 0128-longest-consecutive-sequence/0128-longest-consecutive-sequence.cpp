class Solution {
public:
    int find(int x, unordered_map<int, int>& parent ){
        if(parent[x] != x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void merge(int x, int y, unordered_map<int, int>& parent, unordered_map<int, int>& size, int& maxSegment){
        int rootX = find(x, parent);
        int rootY = find(y, parent);

        if(rootX != rootY){
            if(size[rootX] < size[rootY]){
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            maxSegment = max(maxSegment, size[rootX]);
        }
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> parent, size;
        vector<int> result;
        int ans = 1;

        if(nums.size() == 0) return 0;

        for(int i = 0; i < nums.size();i++){
            int x = nums[i];
            if(parent.find(x) != parent.end()){
                continue;
            }
            parent[x] = x;
            size[x] = 1;

            if(parent.find(x-1) != parent.end()){
                merge(x, x-1, parent, size, ans);
            }
            if(parent.find(x+1) != parent.end()){
                merge(x, x+1, parent, size, ans);
            }
            cout << nums[i] << " " << ans << endl;
        }
        return ans;

    }
};