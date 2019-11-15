// https://www.interviewbit.com/problems/first-missing-integer/

void sep (vector< int >& A) {
	int i = 0, j = 0;
	for (i = 0; i < A.size (); i++) {
		if (A[i] <= 0) {
			swap (A[i], A[j]);
			j++;
		}
	}
	A.erase (A.begin (), A.begin () + j);
}
int Solution::firstMissingPositive (vector< int >& A) {
	sep (A);
	int i;
	for (i = 0; i < A.size (); i++) {
		if (abs (A[i]) - 1 < A.size () && A[abs (A[i]) - 1] > 0)
			A[abs (A[i]) - 1] = -A[abs (A[i]) - 1];
	}
	for (i = 0; i < A.size (); i++) {
		if (A[i] > 0) return i + 1;
	}
	return A.size () + 1;
}