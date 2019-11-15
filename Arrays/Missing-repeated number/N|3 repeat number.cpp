// https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber (const vector< int >& A) {
	int f = -1, s = -1;
	int c1 = 0, c2 = 0;
	for (auto& i : A) {
		if (f == i) {
			c1++;
		} else if (s == i) {
			c2++;
		} else if (c1 == 0) {
			f = i;
			c1++;
		} else if (c2 == 0) {
			s = i;
			c2++;
		} else {
			c1--;
			c2--;
		}
	}
	c1 = 0;
	c2 = 0;
	for (auto& i : A) {
		if (f == i) c1++;
		if (s == i) c2++;
	}
	int n = A.size ();
	if (c1 > n / 3) return f;
	if (c2 > n / 3) return s;
	return -1;
}
