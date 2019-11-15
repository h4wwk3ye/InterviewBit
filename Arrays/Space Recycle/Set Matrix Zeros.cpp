// https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes (vector< vector< int > >& A) {
	int n = A.size ();
	if (!n) return;
	int m = A[0].size ();
	for (int i = 0; i < A.size (); ++i) {
		bool f = 0;
		for (auto& j : A[i]) {
			if (!j) f = 1;
		}
		if (f) {
			for (int j = 0; j < A[i].size (); ++j) {
				if (A[i][j]) A[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		bool f = 0;
		for (int j = 0; j < n; ++j) {
			if (!A[j][i]) f = 1;
		}
		if (f) {
			for (int j = 0; j < n; ++j) {
				if (A[j][i]) A[j][i] = -1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] == -1) A[i][j] = 0;
		}
	}
}
