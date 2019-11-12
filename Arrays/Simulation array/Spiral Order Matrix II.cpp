// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector< vector< int > > Solution::generateMatrix (int A) {
	vector< vector< int > > ans (A, vector< int > (A, 0));
	int xl = 0, xr = A;
	int yl = 0, yr = A;
	int c = 1;

	int f = 0;
	while (c <= A * A) {
		if (f == 0) {
			for (int x = xl; x < xr; x++) {
				ans[yl][x] = c++;
			}
			yl++;
			f = 1;
		} else if (f == 1) {
			for (int y = yl; y < yr; y++) {
				ans[y][xr - 1] = c++;
			}
			xr--;
			f = 2;
		} else if (f == 2) {
			for (int x = xr - 1; x >= xl; x--) {
				ans[yr - 1][x] = c++;
			}
			yr--;
			f = 3;
		} else {
			for (int y = yr - 1; y >= yl; y--) {
				ans[y][xl] = c++;
			}
			xl++;
			f = 0;
		}
	}
	return ans;
}
