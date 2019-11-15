// https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber (const vector< int >& A) {
	int n = A.size ();
	int sq = sqrt (n);
	int r = (n / sq) + 1;
	vector< int > cnt (r, 0);
	for (auto& i : A) {
		cnt[(i - 1) / sq]++;
	}
	int block = r - 1;
	for (int i = 0; i < r - 1; i++) {
		if (cnt[i] > sq) {
			block = i;
			break;
		}
	}

	set< int > s;
	for (int i = 0; i <= n; i++) {
		if (block * sq < A[i] and (block + 1) * sq >= A[i]) {
			if (s.find (A[i]) != s.end ()) return A[i];
			s.insert (A[i]);
		}
	}
	return -1;
}
