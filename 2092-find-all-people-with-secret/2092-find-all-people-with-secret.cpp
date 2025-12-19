class Solution {
public:
    vector<int> parent, rank;
    void makeSet(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool merge(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) {
            return false;
        }

        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        } else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
        return true;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& p, const vector<int>& q) {
            return p[2] < q[2]; 
        });
        makeSet(n);
        merge(0, firstPerson);
        int i = 0;
        while( i < meetings.size()){
            int time = meetings[i][2];
            unordered_set<int> people;

            int j = i;
            while(j < meetings.size() && meetings[j][2] == time){
                // merge(meetings[j][0], meetings[j][1]);
                // people.insert(meetings[j][0]);
                // people.insert(meetings[j][1]);
                if(merge(meetings[j][0], meetings[j][1])){
                    people.insert(meetings[j][0]);
                    people.insert(meetings[j][1]);
                }
                j++;
            }

            for(auto p : people){
                if(find(p) != find(0)){
                    parent[p] = p;
                    rank[p] = 1;
                }
            }
            i = j;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(find(i) == find(0)){
                ans.push_back(i);
            }
        }
        return ans;

    }
};