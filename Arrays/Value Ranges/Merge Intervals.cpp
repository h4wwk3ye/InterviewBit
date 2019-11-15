// https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector< Interval > Solution::insert (vector< Interval >& intervals, Interval newInterval) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int flag = 0;
	vector< Interval > ans;

	int n = intervals.size ();

	if (n == 0) {
		ans.push_back (newInterval);
		return ans;
	}
	if (newInterval.start == 0 and newInterval.end == 0) return intervals;

	Interval to_change;

	if (newInterval.end < intervals[0].start) {
		ans.push_back (newInterval);
		for (auto i : intervals)
			ans.push_back (i);
		return ans;
	}

	if (newInterval.start > intervals[n - 1].end) {
		for (auto i : intervals)
			ans.push_back (i);
		ans.push_back (newInterval);
		return ans;
	}

	if (newInterval.start <= intervals[0].start and newInterval.end >= intervals[n - 1].end) {
		ans.push_back (newInterval);
		return ans;
	}

	to_change.end = -1;
	for (int j = 0; j < n; j++) {
		auto i = intervals[j];
		if (!flag) {
			if (i.end < newInterval.start) {
				ans.push_back (i);
			} else {
				flag = 1;
				to_change.start = min (i.start, newInterval.start);
				j--;
			}
		} else if (flag == 1) {
			if (i.start > newInterval.end) {
				to_change.end = newInterval.end;
				flag = 2;
				ans.push_back (to_change);
				j--;
			} else if (i.start < newInterval.end and i.end >= newInterval.end) {
				to_change.end = max (newInterval.end, i.end);
				ans.push_back (to_change);
				flag = 2;
			}
		} else if (flag == 2) {
			ans.push_back (i);
		}
	}
	if (to_change.end == -1) {
		to_change.end = newInterval.end;
		ans.push_back (to_change);
	}
	return ans;
}
