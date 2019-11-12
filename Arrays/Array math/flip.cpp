// https://www.interviewbit.com/problems/flip/

vector< int > Solution::flip (string A) {
	int curr = 0, mx = 0, j = 1, l = 1, r = 1;
	vector< int > ans (2, 1);
	for (auto i : A) {
		if (i == '1')
			curr--;
		else
			curr++;

		if (curr > mx) {
			mx = curr;
			ans[0] = l, ans[1] = j;
		}
		if (curr < 0) {
			curr = 0;
			l = j + 1;
		}
		j++;
	}
	vector< int > x;
	if (mx == 0) return x;
	return ans;
}
