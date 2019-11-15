// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate (vector< vector< int > >& mat) {
	int N = mat.size ();
	for (int x = 0; x < N / 2; x++) {
		for (int y = x; y < N - x - 1; y++) {
			int temp = mat[N - 1 - y][x];

			mat[N - 1 - y][x] = mat[N - 1 - x][N - 1 - y];
			mat[N - 1 - x][N - 1 - y] = mat[y][N - 1 - x];
			mat[y][N - 1 - x] = mat[x][y];
			mat[x][y] = temp;
		}
	}
}
