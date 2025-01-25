struct vi_hash {
    std::size_t operator()(std::vector<int32_t> const& vec) const {

        static const uint32_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        std::size_t seed = vec.size() + FIXED_RANDOM;
        for(auto x : vec) {
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = (x >> 16) ^ x;
            seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
