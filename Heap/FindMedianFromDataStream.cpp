class MedianFinder {
public:

    priority_queue<int>largeHeap;
    priority_queue<int, vector<int>, greater<int>> smallHeap;

    MedianFinder() {
        while(!largeHeap.empty()){
            largeHeap.pop();
        }
        while(!smallHeap.empty()){
            smallHeap.pop();
        }
    }
    
    void addNum(int num) {
        largeHeap.push(num);
        smallHeap.push(largeHeap.top());
        largeHeap.pop();

        if(largeHeap.size() < smallHeap.size()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
    }
    
    double findMedian() {
        return largeHeap.size() > smallHeap.size() ? largeHeap.top() : (largeHeap.top() + smallHeap.top())/2.0f;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */