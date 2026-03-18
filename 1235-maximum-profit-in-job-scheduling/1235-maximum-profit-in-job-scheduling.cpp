class Solution {
public:
    vector<int> dp;
    int backtrack(vector<vector<int>>& jobs, int index){
        int n = jobs.size();
        if(index >= n){
            return 0;
        }

        if(dp[index] != INT_MIN){
            return dp[index];
        }

        //choose current job
        //-> need to find the next job not overlap
        int endTime = jobs[index][1];
        auto it = lower_bound(jobs.begin(), jobs.end(), endTime, [](auto& job, int value){
            return job[0] < value;
        });
        int choose = jobs[index][2];
        if(it != jobs.end()){
            choose += backtrack(jobs, it - jobs.begin());
        }
        
        //not choose this job
        int notChoose = backtrack(jobs, index+1);
        cout << index << " " << choose << " " << notChoose << endl;
        int ans = max(choose, notChoose);
        dp[index] = ans;
        return dp[index];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i = 0; i < startTime.size(); i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), [](auto& p, auto& q){
            return p[0] < q[0]; 
        });

        dp.resize(jobs.size(), INT_MIN);
        int ans = backtrack(jobs, 0);
        return ans;
    }
};