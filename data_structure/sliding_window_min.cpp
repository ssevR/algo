//INF = 1e9
struct sliding_window_min{
    stack<int> l, r;
    int rmin;
    
    sliding_window(){
        rmin = INF;
    }
    
    void push_back(int x){
        r.push(x);
        rmin = min(rmin, x);
    }
    
    void pop_front(){
        if(l.empty()){
            int mn = INF;
            while(!r.empty()){
                mn = min(mn, r.top());
                l.push(mn);
                r.pop();
            }
            rmin = INF;
        }
        l.pop();
    }
    
    int get_min(){
        int res = rmin;
        if(!l.empty()) res = min(res, l.top());
        return res;
    }
};

