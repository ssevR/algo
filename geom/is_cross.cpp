bool is_cross(P p1, P p2, P p3, P p4) {
    for (int i = 0; i < 2; ++i) {
        auto sign1 = (p2 - p1) * (p3 - p1);
        auto sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)) {
            return 0;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    if ((p2 - p1) * (p4 - p3) == 0) {
        for (int i = 0; i < 2; ++i) {
            if ((max(p1.x, p2.x) < min(p3.x, p4.x)) || (max(p1.y, p2.y) < min(p3.y, p4.y))) {
                return 0;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
    }
    return 1;
}
