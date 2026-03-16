template<typename T>
vector<int> next_greater(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);

	for (int i = sz - 1; i >= 0; --i) {
		while(!st.empty() && a[st.top()] <= a[i])
			st.pop();

		res[i] = st.empty() ? sz : st.top();

		st.push(i);
	}
	return res;
}

template<typename T>
vector<int> next_greater_or_equal(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);

	for (int i = sz - 1; i >= 0; --i) {
		while(!st.empty() && a[st.top()] < a[i])
			st.pop();

		res[i] = st.empty() ? sz : st.top();

		st.push(i);
	}
	return res;
}

template<typename T>
vector<int> next_smaller(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);
	for (int i = sz - 1; i >= 0; --i) {
		while(!st.empty() && a[st.top()] >= a[i])
			st.pop();
		res[i] = st.empty() ? sz : st.top();
		st.push(i);
	}
	return res;
}

template<typename T>
vector<int> next_smaller_or_equal(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);
	for (int i = sz - 1; i >= 0; --i) {
		while(!st.empty() && a[st.top()] > a[i])
			st.pop();
		res[i] = st.empty() ? sz : st.top();
		st.push(i);
	}
	return res;
}


template<typename T>
vector<int> prev_greater(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);
	for (int i = 0; i < sz; ++i) {
		while(!st.empty() && a[st.top()] <= a[i])
			st.pop();
		res[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
	return res;
}

template<typename T>
vector<int> prev_greater_or_equal(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);
	for (int i = 0; i < sz; ++i) {
		while(!st.empty() && a[st.top()] < a[i])
			st.pop();
		res[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
	return res;
}
template<typename T>
vector<int> prev_smaller(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);
	for (int i = 0; i < sz; ++i) {
		while(!st.empty() && a[st.top()] >= a[i])
			st.pop();
		res[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
	return res;
}
template<typename T>
vector<int> prev_smaller_or_equal(const vector<T>& a) {
	int sz = a.size();
	stack<int> st;
	vector<int> res(sz);
	for (int i = 0; i < sz; ++i) {
		while(!st.empty() && a[st.top()] > a[i])
			st.pop();
		res[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
	return res;
}
