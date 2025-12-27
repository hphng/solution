class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        unordered_map<int, int> mp;

        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > busy;
        for(int i = 0;i < n; i++){
            mp[i] = 0;
            available.push(i);
        }

        for(auto& meeting: meetings){
            long long start = meeting[0];
            long long end = meeting[1];

            //free up room before start
            while(!busy.empty() && busy.top().first <= start){
                int freeRoom = busy.top().second;
                available.push(freeRoom);
                busy.pop();
            }
            if(available.empty()){
                auto [finish, room] = busy.top();
                busy.pop();
                busy.push({finish + end - start, room});
                mp[room]++;
            } else {
                int room = available.top();
                available.pop();
                mp[room]++;
                busy.push({end, room});
            }
        }

        int maxscore = -1;
        int ans = -1;
        for(auto [room, score]: mp){
            if(score > maxscore || (score == maxscore && room < ans)){
                maxscore = score;
                ans = room;
            }
        }
        return ans;
    }
};