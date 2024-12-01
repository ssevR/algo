using S = long  long ;
 using F = long  long ; const S INF = 8e18 ; 
S op(S a, S b){ return std::max(a, b); } 
S e(){ return -INF; } 
S mapping(F f, S x){ return f+x; } 
F composition(F f, F g){ return f+g; } 
F id(){ return 0 ; } int main(){
     int N; 
    std::vector<S> v(N); 
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v); 
}

