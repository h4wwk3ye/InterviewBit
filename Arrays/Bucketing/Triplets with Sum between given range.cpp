// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

int Solution::solve (vector< string >& A) {
	vector< long double > arr;
	for (auto& i : A) {
		arr.push_back (stod (i));
	}
	if (A.size () < 3) return -1;
	long double a, b, c;
	a = arr[0], b = arr[1], c = arr[2];
	for (int i = 3; i < arr.size (); i++) {
		if (a + b + c > 1 and a + b + c < 2) return 1;
		if (a + b + c > 2) {
			if (a > b and a > c) {
				a = arr[i];
			} else if (b > a and b > c) {
				b = arr[i];
			} else {
				c = arr[i];
			}
		} else {
			if (a < b and a < c) {
				a = arr[i];
			} else if (b < a and b < c) {
				b = arr[i];
			} else {
				c = arr[i];
			}
		}
	}
	if (a + b + c > 1 and a + b + c < 2) return 1;
	return 0;
}
