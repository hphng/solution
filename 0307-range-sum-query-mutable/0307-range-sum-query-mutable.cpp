class NumArray {
private:
    vector<int> original, tree;
    void buildTree(int node, int start, int end){
        if(start == end){
            tree[node] = original[start];
        } else {
            int mid = (start + end)/2;
            buildTree(node*2, start, mid);
            buildTree(node*2+1, mid+1, end);

            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }

    void updateTree(int node, int start, int end, int idx, int value){
        if(start == end){
            tree[node] = value;
            original[start] = value;
            return;
        } 

        int mid = (start + end)/2;
        if(idx <= mid){
            updateTree(node*2, start, mid, idx, value);
        } else {
            updateTree(node*2+1, mid+1, end, idx, value);
        }

        tree[node] = tree[node*2] + tree[node*2+1];
    }

    int queryTree(int node, int start, int end, int l, int r){
        //query in range [l, r]
        if(l > end || r < start ){
            return 0;
        }

        if(l <= start && end <= r){
            return tree[node];
        }

        int mid = (start+end)/2;
        int leftSum = queryTree(node*2, start, mid, l, r);
        int rightSum = queryTree(node*2+1, mid+1, end, l, r);

        return leftSum + rightSum;
    }
public:
    NumArray(vector<int>& nums) {
        original = nums;
        int n = nums.size();
        tree.resize(4*n, 0);

        buildTree(1, 0, n-1);
    }
    
    void update(int index, int val) {
        int n = original.size();
        updateTree(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        int n = original.size();
        int ans = queryTree(1, 0, n-1, left, right);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */