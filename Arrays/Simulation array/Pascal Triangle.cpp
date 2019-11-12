// https://www.interviewbit.com/problems/pascal-triangle/

#define pb push_back
vector< vector< int > > Solution::solve (int A) {
	vector< vector< int > > ans;
	if (A == 0) {
		return ans;
	}
	ans.resize (A);
	ans[0].pb (1);
	for (int i = 1; i < A; i++) {
		ans[i].pb (1);
		for (int j = 1; j < i; j++) {
			ans[i].pb (ans[i - 1][j - 1] + ans[i - 1][j]);
		}
		ans.pb (1);
	}
	return ans;
}
