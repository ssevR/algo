//INF = 1e9
struct sliding_window_min{
    vector<int> l, r;
    int rmin;
    
    sliding_window(){
        rmin = INF;
    }
    
    void push_back(int x){
        r.push_back(x);
        rmin = min(rmin, x);
    }
    
    void pop_front(){
        if(l.empty()){
            for(int mn = INF; !r.empty();){
                mn = min(mn, r.back());
                l.push_back(mn);
                r.pop_back();
            }
            rmin = INF;
        }
        l.pop_back();
    }
    
    int get_min(){
        int res = rmin;
        if(!l.empty()) res = min(res, l.back());
        return res;
    }
};
