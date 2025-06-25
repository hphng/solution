class MovingAverage {
public:
    int sum = 0;
    int MAX_SIZE;
    queue<int> q;
    MovingAverage(int size) {
        MAX_SIZE = size;
    }
    
    double next(int val) {
        if(q.size() == MAX_SIZE){
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return (double) sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */