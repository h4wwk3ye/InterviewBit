// https://www.interviewbit.com/problems/find-permutation/

vector< int > Solution::findPerm (const string A, int B) {
	vector< int > ans (B, -1);
	int j = 1;
	vector< int > cnt (B, 0);
	int c = 0;
	for (int i = B - 2; i >= 0; i--) {
		if (A[i] == 'D')
			c++;
		else
			c = 0;
		cnt[i + 1] = c;
	}
	for (int i = B - 1; i >= 0; i--) {
		if (cnt[i] == 0) {
			continue;
		}
		ans[i] = j++;
	}
	for (int i = 0; i < B; i++) {
		if (ans[i] == -1) {
			ans[i] = j++;
		}
	}
	return ans;
}
