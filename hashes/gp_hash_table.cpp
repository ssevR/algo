#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct hash_int {
    static uint32_t splitmix32(uint32_t x) {
        x += 0x9e3779b9;
        x = (x ^ (x >> 16)) * 0x21f0aaad;
        x = (x ^ (x >> 15)) * 0x735a2d97;
        x ^= x >> 15;
        return x;
    }


    uint32_t operator()(uint32_t x) const {
        static const uint32_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix32(x + FIXED_RANDOM);
    }
};

//gp_hash_table<int64_t, int64_t, hash_ll> table; // unordered_map
//gp_hash_table<int64_t, null_type, hash_ll> // unordered_set

