// https://www.interviewbit.com/problems/next-permutation/

vector< int > Solution::nextPermutation (vector< int >& A) {
	int n = A.size ();
	if (A.size () <= 2) {
		reverse (A.begin (), A.end ());
		return A;
	}
	int p = n - 1, q = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (A[i] < A[i + 1]) {
			p = i;
			break;
		}
	}
	for (int i = n - 1; i >= p; i--) {
		if (A[i] > A[p]) {
			q = i;
			break;
		}
	}
	swap (A[p], A[q]);
	reverse (A.begin () + p + 1, A.end ());
	return A;
}
