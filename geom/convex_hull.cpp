vector<P> convex_hull(vector<P>& points) {
    sort(points.begin(), points.end());

    vector<P> hull;
    for (int rep = 0; rep < 2; ++rep) {
        for (auto C : points) {
            while((int)hull.size() >= 2) {
                auto A = hull.end()[-2];
                auto B = hull.end()[-1];
                if (A.triangle(B, C) <= 0)
                    break;
                hull.pop_back();
            }
            hull.push_back(C);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }

    return hull;

}

