// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel (vector< int >& arrive, vector< int >& depart, int K) {
	vector< pair< int, int > > arr;
	int mx = 0;
	for (int i = 0; i < arrive.size (); i++) {
		arr.push_back ({arrive[i], 0});
		arr.push_back ({depart[i] - 1, 1});
	}
	sort (arr.begin (), arr.end ());
	int cnt = 0;
	for (int i = 0; i < arr.size (); i++) {
		if (arr[i].second == 0) {
			cnt++;
		} else {
			cnt--;
		}
		if (cnt > K) return 0;
	}
	return 1;
}