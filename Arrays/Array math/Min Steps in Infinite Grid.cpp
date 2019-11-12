// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints (vector< int >& A, vector< int >& B) {
	int n = A.size ();
	int ans = 0, x = A[0], y = B[0], tmpx, tmpy;
	for (int i = 1; i < n; ++i) {
		tmpx = abs (A[i] - x);
		tmpy = abs (B[i] - y);
		if (tmpx < tmpy) {
			ans += tmpx;
			ans += abs (B[i] - y) - tmpx;
		} else {
			ans += tmpy;
			ans += abs (A[i] - x) - tmpy;
		}
		x = A[i], y = B[i];
	}
	return ans;
}
