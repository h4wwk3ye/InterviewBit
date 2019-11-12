// https://www.interviewbit.com/problems/max-non-negative-subarray/

#define ll long long
vector< int > Solution::maxset (vector< int >& A) {
	ll ans = 0;
	ll curr = 0;
	ll len = 0, curr_len = 0;
	ll l = 0, r = 0;
	ll l_ = 0, r_ = 0;
	while (l < A.size () and A[l] < 0) {
		l++, r++, l_++, r_++;
	}
	int j = l_;
	for (; j < A.size (); ++j) {
		int i = A[j];

		if (i < 0) {
			if (curr > ans or (curr == ans and curr_len > len)) {
				ans = curr;
				l = l_;
				r = r_;
				l_ = r;
				len = curr_len;
			}
			curr = 0;
			curr_len = 0;
			l_++;
			r_++;
		} else {
			r_++;
			curr += i;
			curr_len++;
		}
		cout << i << " " << curr << " " << ans << " " << l << " " << r << "\n";
	}
	if (curr > ans or (curr == ans and curr_len > len)) {
		l = l_;
		r = r_;
	}
	vector< int > a;
	for (int i = l; i < r; i++) {
		a.push_back (A[i]);
	}
	return a;
}
