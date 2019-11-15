// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap (const vector< int >& A) {
	int n = A.size ();
	vector< int > left (n), right (n);
	left[0] = A[0];
	right[n - 1] = A[n - 1];
	for (int i = 1; i < n; i++) {
		left[i] = min (A[i], left[i - 1]);
	}
	for (int i = n - 2; i >= 0; i--) {
		right[i] = max (A[i], right[i + 1]);
	}
	int i = 0;
	int j = 0;
	int ans = -1;
	while (i < n and j < n) {
		if (left[i] <= right[j]) {
			ans = max (ans, j - i);
			j++;
		} else {
			i++;
		}
	}
	return ans;
}