// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray (const vector< int >& A) {
	int curr = 0, mx = -1e9;
	for (int i = 0; i < A.size (); ++i) {
		curr += A[i];
		mx = max (mx, curr);
		if (curr < 0) curr = 0;
	}
	return mx;
}
