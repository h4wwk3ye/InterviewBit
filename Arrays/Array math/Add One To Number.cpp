// https://www.interviewbit.com/problems/add-one-to-number/

vector< int > Solution::plusOne (vector< int >& A) {
	int carry = 1, n = A.size () - 1;
	vector< int > ans;
	while (n >= 0) {
		int tmp = A[n] + carry;
		if (tmp >= 10) {
			ans.push_back (tmp % 10);
			carry = 1;
		} else {
			ans.push_back (tmp);
			carry = 0;
		}
		n--;
	}
	if (carry) ans.push_back (1);

	n = ans.size () - 1;
	while (ans[n] == 0) {
		ans.pop_back ();
		n--;
	}
	reverse (ans.begin (), ans.end ());
	return ans;
}
