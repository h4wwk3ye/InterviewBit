// https://www.interviewbit.com/problems/largest-number/

string Solution::largestNumber (const vector< int >& A) {
	vector< string > a;
	for (auto& i : A) {
		a.push_back (to_string (i));
	}
	auto cmp = [&] (const string& x, const string& y) { return x + y < y + x; };
	sort (a.begin (), a.end (), cmp);
	reverse (a.begin (), a.end ());
	string ans = "";
	for (auto& i : a) {
		if (ans == "" and i == "0") continue;
		ans += i;
	}
	if (ans == "") ans = "0";


	return ans;
}