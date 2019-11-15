// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector< int > Solution::subUnsort (vector< int >& arr) {
	int n = arr.size ();
	int s = -1, e = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			s = i;
			break;
		}
	}
	if (s == -1) {
		vector< int > ans (1, -1);
		return ans;
	}
	for (int i = n - 1; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			e = i;
			break;
		}
	}
	int mn = 1e9, mx = 0;
	for (int i = s; i <= e; ++i) {
		mn = min (mn, arr[i]);
		mx = max (mx, arr[i]);
	}
	for (int i = 0; i < s; i++) {
		if (arr[i] > mn) {
			s = i;
			break;
		}
	}
	for (int i = n - 1; i > e; i--) {
		if (arr[i] < mx) {
			e = i;
			break;
		}
	}
	vector< int > ans = {s, e};
	return ans;
}
