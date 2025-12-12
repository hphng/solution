class Solution {
public:

    /*
        if timestamps1 < t2 -> -1
        t1 == t2 -> 0
        t1 > t2 -> 1
    */ 
    static int compareTimestamp(const string t1, const string t2){
        long long num1 = stoll(t1);
        long long num2 = stoll(t2);

        if(num1 < num2){
            return -1;
        }

        if(num1 > num2){
            return 1;
        }
        return 0;
    }
    static bool customizedSort(const vector<string>& e1, const vector<string>& e2){
        string t1 = e1[1];
        string t2 = e2[1];
        int checkTimestamp = compareTimestamp(t1, t2);
        if(checkTimestamp == -1){
            return true;
        }

        if(checkTimestamp == 1){
            return false;
        }
        //when timestamp equal
        if (e1[0] == "OFFLINE" && e2[0] == "MESSAGE") return true;
        if (e1[0] == "MESSAGE" && e2[0] == "OFFLINE") return false;

        // If both are the same type — keep original order
        return true;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        unordered_map<string, long long> nextOnlineTime;
        unordered_map<string, int> mentions;
        vector<int> ans(numberOfUsers, 0);
        sort(events.begin(), events.end(), customizedSort);

        //add people into online polls
        for(int i = 0; i < numberOfUsers; i++){
            string id = "id" + to_string(i);
            mentions[id] = 0;
            nextOnlineTime[id] = 0;
        }

        for(auto event: events){
            // cout << event[0] << " " << event[1] << " " << event[2] << endl;
            long long timestamp = stoll(event[1]);
            if(event[0] == "OFFLINE"){
                string id = "id" + event[2];
                long long onlineBackTimestamp = timestamp + 60;
                // cout << "set offline: " << id << " " << onlineBackTimestamp << endl;
                nextOnlineTime[id] = onlineBackTimestamp;
                continue;
            }

            if(event[0] == "MESSAGE"){
                //process the message queue
                if(event[2] == "ALL"){
                    for(auto [id, _]: mentions){
                        mentions[id]++;
                    }
                } else if(event[2] == "HERE"){
                    for(auto [id, time]: nextOnlineTime){
                        if(time <= timestamp){
                            mentions[id]++;
                        }
                    }
                } else {
                    //specific number of id
                    stringstream ss(event[2]);
                    string id;
                    while(getline(ss, id, ' ')){
                        mentions[id]++;
                    }
                }
            }
        }

        for(int i = 0; i < numberOfUsers; i++){
            string id = "id" + to_string(i);
            ans[i] = mentions[id];
        }
        return ans;
    }
};