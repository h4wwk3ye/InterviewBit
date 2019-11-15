#define ll long long
int Solution::maxSpecialProduct (vector< int >& A) {
	ll mod = 1e9 + 7;
	ll n = A.size ();

	stack< ll > greater_right;
	vector< ll > right (n, 0);
	for (ll i = 0; i < n; i++) {
		while (!greater_right.empty ()) {
			if (A[i] > A[greater_right.top ()]) {
				ll idx = greater_right.top ();
				greater_right.pop ();
				right[idx] = i;
			} else
				break;
		}
		greater_right.push (i);
	}


	stack< ll > greater_left;
	vector< ll > left (n, 0);
	for (ll i = n - 1; i >= 0; i--) {
		while (!greater_left.empty ()) {
			if (A[i] > A[greater_left.top ()]) {
				ll idx = greater_left.top ();
				greater_left.pop ();
				left[idx] = i;
			} else
				break;
		}
		greater_left.push (i);
	}

	ll ans = 0ll;
	for (ll i = 0; i < n; i++) {
		ans = max (ans, (left[i] * right[i]));
	}
	ans %= mod;
	return ans;
}
