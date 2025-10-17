class Solution {
public:
    vector<int> parent, rank;

    void makeSet(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void uni(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY){
            return;
        }

        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        } else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootX]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        makeSet(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    uni(i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i){
                res++;
            }
        }
        return res;
    }
};