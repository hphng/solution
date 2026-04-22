class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> freq;
        queue<pair<int, int>> wait; //{freq-1, cooldown time}
        unordered_map<char, int> mp; // task: freq

        for(auto& c: tasks){
            mp[c]++;
        }

        for(auto [_, f]: mp){
            freq.push(f);
        }

        int time = 0;
        while(!freq.empty() || !wait.empty()){

            while(!wait.empty() && wait.front().second <= time){
                int task = wait.front().first;
                wait.pop();

                freq.push(task);
            }

            if(!freq.empty()){
                int top = freq.top();
                freq.pop();

                if(top > 1){
                    wait.push({top-1, time + n + 1});
                }
            }
            time++;
        }

        return time;
    }
};