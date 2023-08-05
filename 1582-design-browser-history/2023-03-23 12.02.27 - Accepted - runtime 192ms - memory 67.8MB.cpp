class BrowserHistory {
public:
    string curr;
    vector<string> ufor;
    vector<string> uback;
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        uback.push_back(curr);
        curr = url;
        if(!ufor.empty())
        ufor.clear();
    }
    
    string back(int steps) {
        while(steps-- && !uback.empty()){
            ufor.push_back(curr);
            curr = uback.back();
            uback.pop_back();
        }
        return curr;
    }
    
    string forward(int steps) {
        while(steps-- && !ufor.empty()){
            uback.push_back(curr);
            curr = ufor.back();
            ufor.pop_back();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */