class MedianFinder {
private:
    priority_queue<int> maxHeap; //store half -> min
    priority_queue<int, vector<int>, greater<int>> minHeap; //store half -> max
public:
    MedianFinder() {
        
    }
    /*
        maxheap size always should > min Heap size
    
    */
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();

        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top() * 1.0;
        }

        return (maxHeap.top() + minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */