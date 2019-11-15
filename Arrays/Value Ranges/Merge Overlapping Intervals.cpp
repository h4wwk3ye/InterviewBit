// https://www.interviewbit.com/problems/merge-overlapping-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp (const Interval& a, const Interval& b) {
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}

vector< Interval > Solution::merge (vector< Interval >& A) {
	int n = A.size ();
	int i = 1;
	sort (A.begin (), A.end (), cmp);
	vector< Interval > ans;
	if (!n) return ans;
	int l = A[0].start;
	int r = A[0].end;
	while (i < n) {
		if (A[i].start <= r) {
			r = max (r, A[i].end);
		} else {
			ans.push_back ({l, r});
			l = A[i].start;
			r = A[i].end;
		}
		i++;
	}
	if (!ans.size ())
		ans.push_back ({l, r});
	else if (ans.back ().start != l and ans.back ().end != r)
		ans.push_back ({l, r});
	return ans;
}
