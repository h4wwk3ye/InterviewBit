// https://www.interviewbit.com/problems/maximum-consecutive-gap/

int Solution::maximumGap (const vector< int >& A) {
	if (A.size () < 2) return 0;
	int mx = *max_element (A.begin (), A.end ());
	int mn = *min_element (A.begin (), A.end ());
	int d = (mx - mn - 1) / (A.size () - 1) + 1;
	vector< int > buckets_min (A.size () - 1, INT_MAX);
	vector< int > buckets_max (A.size () - 1, INT_MIN);
	for (int i = 0; i < A.size (); i++) {
		if (A[i] == mx or A[i] == mn) continue;
		int idx = (A[i] - mn) / d;
		buckets_min[idx] = min (buckets_min[idx], A[i]);
		buckets_max[idx] = max (buckets_max[idx], A[i]);
	}
	int ans = 0;
	int previous = mn;
	for (int i = 0; i < A.size () - 1; ++i) {
		cout << buckets_min[i] << " " << buckets_max[i] << "\n";
		if (buckets_min[i] == INT_MAX or buckets_max[i] == INT_MIN) continue;
		ans = max (ans, buckets_min[i] - previous);
		previous = buckets_max[i];
	}
	ans = max (ans, mx - previous);
	return ans;
}