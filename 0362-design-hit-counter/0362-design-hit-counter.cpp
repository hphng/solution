class HitCounter {
public:
    queue<pair<int, int>> record; //left: small -> right: larger
    int WINDOW = 300;
    int count;
    HitCounter() {
        count = 0;
    }
    
    void hit(int timestamp) {
        if(!record.empty() && record.back().first == timestamp){
            record.back().second++;
        } else {
            record.push({timestamp, 1});
        }
        count++;
    }
    
    int getHits(int timestamp) {
        while(!record.empty()){
            int diff = timestamp - record.front().first;
            if(diff >= 300){
                count-= record.front().second;
                record.pop();
            } else {
                break;
            }
        }

        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */