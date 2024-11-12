struct treap {
    struct Node {
        Node* l;
        Node* r;
        int x;
        long double y;
    }

    Node* merge(Node* lhs, Node* rhs) {
        if (lhs == nullptr) return rhs;
        if (rhs == nullptr) return lhs;

        if (lhs->y > rhs->y) {
            lhs->r = merge(lhs->r, rhs);
            return lhs;
        }
        else {
            rhs->l = merge(lhs, rhs->l);
            return rhs;
        }
        
    }
    pair<Node*, Node*> split(Node* root) {
        if (root == nullptr) {
            return mp(nullptr, nullptr);
        }
        if (root.x < k) {
            auto [l, r] : split(root->r, k);
            root->r = l;
            return mp(root, r);
        }
        else {
            auto [l, r] = split(root->l, k);
            root->l = r;
            return mp(l, root);
        }
    }

}
