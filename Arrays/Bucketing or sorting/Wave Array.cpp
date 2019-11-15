// https://www.interviewbit.com/problems/wave-array/

vector< int > Solution::wave (vector< int >& A) {
	sort (A.begin (), A.end ());
	vector< int > ans;
	int j = 0;
	while (j + 4 <= A.size ()) {
		ans.push_back (A[j + 1]);
		ans.push_back (A[j]);
		ans.push_back (A[j + 3]);
		ans.push_back (A[j + 2]);
		j += 4;
	}
	if (j + 3 < A.size ()) {
		ans.push_back (A[j + 1]);
		ans.push_back (A[j]);
		ans.push_back (A[j + 3]);
	} else if (j + 2 < A.size ()) {
		ans.push_back (A[j + 1]);
		ans.push_back (A[j]);
		ans.push_back (A[j + 2]);
	} else if (j + 1 < A.size ()) {
		ans.push_back (A[j + 1]);
		ans.push_back (A[j]);
	} else if (j < A.size ()) {
		ans.push_back (A[j]);
	}
	return ans;
}
