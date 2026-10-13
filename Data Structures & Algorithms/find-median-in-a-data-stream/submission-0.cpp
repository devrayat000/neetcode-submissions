class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (num > minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        while (std::abs(minHeap.size() - maxHeap.size()) > 1) {
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.pop());
            } else {
                minHeap.push(maxHeap.push());
            }
        }
    }
    
    double findMedian() {
        return minHeap.top();
    }
};
