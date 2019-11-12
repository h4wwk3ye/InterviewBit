// https://www.interviewbit.com/problems/anti-diagonals/

vector< vector< int > > Solution::diagonal (vector< vector< int > >& A) {
	vector< vector< int > > ans;
	int n = A.size ();
	for (int i = 0; i < n; i++) {
		vector< int > c;
		c.push_back (A[0][i]);
		int j = 1;
		while (i - j >= 0) {
			c.push_back (A[j][i - j]);
			j++;
		}
		ans.push_back (c);
	}
	for (int i = 1; i < n; i++) {
		vector< int > c;
		c.push_back (A[i][n - 1]);
		int j = i + 1;
		while (j < n) {
			c.push_back (A[j][n - j - i + 1]);
			j++;
		}
		ans.push_back (c);
	}
	return ans;
}
