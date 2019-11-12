// https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr (vector< int >& A) {
	int n = A.size ();
	vector< int > a (n), b (n);
	for (int i = 0; i < n; i++) {
		a[i] = A[i] + i;
		b[i] = A[i] - i;
	}
}