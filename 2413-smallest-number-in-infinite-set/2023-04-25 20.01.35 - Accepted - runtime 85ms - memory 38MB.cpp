class SmallestInfiniteSet {
public:
    unordered_set<int> mp;
    priority_queue <int, vector<int>, greater<int> > pq;
    SmallestInfiniteSet() {
        pq.push(1);
    }

    int popSmallest() {
        int temp = pq.top();
        pq.pop();
        mp.insert(temp);
        if(pq.empty()){
            for(int i = temp + 1;; i++){
                if(mp.find(i) == mp.end()){
                    pq.push(i);
                    break;
                }
            }
        }
        return temp;
    }
    
    void addBack(int num) {
        if(mp.find(num) != mp.end()){
            pq.push(num);
            mp.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */