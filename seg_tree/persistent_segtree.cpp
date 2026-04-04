template<typename T> 
struct persistent_segtree {
	int n;
	struct Node {
		T sum = 0;
		shared_ptr<Node> left;
		shared_ptr<Node> right;
	};
	vector<shared_ptr<Node> > roots;

	shared_ptr<Node> build(const vector<T>& v, int l, int r) {
		shared_ptr<Node> cur(new Node);
		if (l + 1 == r) {
			cur.get()->sum = v[l];
			return cur;
		}
		int mid = (r + l) / 2;
		if (l < mid) {
			cur.get()->left = shared_ptr<Node>(build(v, l, mid));
			cur.get()->sum += cur.get()->left.get()->sum;
		}
		if (mid < r) {
			cur.get()->right = shared_ptr<Node>(build(v, mid, r));
			cur.get()->sum += cur.get()->right.get()->sum;
		}
		return cur;


	};
	shared_ptr<Node> update(shared_ptr<Node> cur, int i, int lx, int rx, T x) {
		if (lx + 1 == rx) {
			cur.get()->sum = x;
			return cur;
		}
		int mx = (lx + rx) / 2;
		if (i < mx) {
			auto old = *(cur.get()->left.get());
			cur.get()->sum -= old.sum;
			cur.get()->left = shared_ptr<Node>(new Node(old));

			update(cur.get()->left, i, lx, mx, x);
			cur.get()->sum += cur.get()->left.get()->sum;
		}
		else {
			auto old = *(cur.get()->right.get());
			cur.get()->sum -= old.sum;
			cur.get()->right = shared_ptr<Node>(new Node(old));

			update(cur.get()->right, i, mx, rx, x);
			cur.get()->sum += cur.get()->right.get()->sum;
		}
		return cur;
	}
	int update(int ind, int i, T x) {
		auto new_root = make_shared<Node>(*roots[ind]);

		update(new_root, i, 0, n, x);
		roots.push_back(new_root);
		return roots.size() - 1;
	}
	T find_sum(shared_ptr<Node> root, int l, int r, int lx, int rx) {
		int L = max(l, lx);
		int R = min(r, rx);
		if (L >= R)
			return 0;
		if (l <= lx && rx <= r) {
			return root.get()->sum;
		}
		int mx = (lx + rx) / 2;
		return find_sum(root.get()->left, l, r, lx, mx) + find_sum(root.get()->right, l, r, mx, rx);
	}
	T find_sum(int ind, int l, int r) {
		return find_sum(roots[ind], l, r, 0, n);
	}



	persistent_segtree(const vector<T>& a) {
		n = a.size();

		int l = 0, r = n;
		roots.push_back(build(a, 0, n));
	};


};

