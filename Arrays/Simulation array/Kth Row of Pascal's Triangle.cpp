// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector< int > Solution::getRow (int A) {
	int fact[2 * A];
	fact[0] = 1;
	for (int i = 1; i < 2 * A; i++) {
		fact[i] = fact[i - 1] * i;
	}
	vector< int > ans;
	int c = 1;
	auto ncr = [&] (int n, int r) { return c * (n - r + 1) / r; };
	ans.push_back (1);
	for (int i = 1; i <= A; i++) {
		c = ncr (A, i);
		ans.push_back (c);
	}
	return ans;
}
