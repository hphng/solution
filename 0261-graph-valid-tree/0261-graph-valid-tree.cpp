class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // int unions(int i, int j){
        
    // }

    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto edge: edges){
            int node1 = edge[0];
            int node2 = edge[1];
            if(find(node1) == find(node2)){
                return false;
            }
            parent[find(node1)] = find(node2);
            n--;
        }
        return n == 1;
    }
};