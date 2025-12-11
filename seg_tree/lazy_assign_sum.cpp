using S = pair<long long, long long> ;
 using F = long  long ; 
 const F ID = 8e18 ; 
S op(S a, S b){ return {a.first + b.first, a.second + b.second }; } 
S e() { return {0ll, 0ll}; } 
S mapping(F f, S x){ return (f == ID ? x : make_pair(f * x.second, x.second) ); } 
F composition(F f, F g){ return (f == ID ? g : f); } 
F id(){ return ID; } 

