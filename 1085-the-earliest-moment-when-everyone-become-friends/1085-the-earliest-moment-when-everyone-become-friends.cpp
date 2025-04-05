class Solution {
private: 
    vector<int> parent, rank;
    int group;
public:
    static bool check(vector<int>&p, vector<int>&q){
        return p[0] < q[0];
    }

    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
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
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        group--;

    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), check);
        parent.resize(n);
        rank.resize(n, 0);
        group = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(auto x : logs){
            unite(x[1], x[2]);
            if(group == 1){
                return x[0];
            }
        }
        int last = logs[logs.size()-1][0];
        if(group == 1){
            return last;
        }
        return -1;
    }
};