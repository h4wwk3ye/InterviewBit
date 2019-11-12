// https://www.interviewbit.com/problems/noble-integer/

int Solution::solve (vector< int >& A) {
	sort (A.begin (), A.end ());
	int n = A.size ();
	for (int i = 0; i < n; i++) {
		int j = upper_bound (A.begin (), A.end (), A[i]) - A.begin ();
		if (n - j == A[i]) return 1;
	}
	return -1;
}
