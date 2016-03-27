#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int min_inf(numeric_limits<int>::min());
constexpr int base(110);

class subarray{ public: int low, high, sum; };

subarray brute_find_max_subarray(vector<int>&, int, int);

subarray recursive_find_max_subarray(vector<int>&, int, int);

subarray find_max_crossing_subarray(vector<int>&, int, int, int);

subarray incremental_max_subarray(vector<int>&);


/* functions */
subarray brute_find_max_subarray(vector<int> &A, int low, int high){

	subarray m{low, low, min_inf};
	subarray cur{low, low, 0};

	for(cur.low = low; cur.low <= high; ++cur.low){

		cur.sum = 0;

		for(cur.high = cur.low; cur.high <= high; ++cur.high){

			cur.sum += A[cur.high];

			if(cur.sum > m.sum) m = cur;

		}
	}

	return m;
}

subarray recursive_find_max_subarray(vector<int> &A, int low, int high){

	//if((high - low) < base) return brute_find_max_subarray(A, low, high);
	if(high == low) return {low, high, A[low]};

	int mid((low + high) / 2); // implicit floor

	subarray left(recursive_find_max_subarray(A, low, mid));
	subarray right(recursive_find_max_subarray(A, mid+1, high));
	subarray cross(find_max_crossing_subarray(A, low, mid, high));

	if(left.sum >= right.sum && left.sum >= cross.sum)
		return left;

	if (right.sum >= left.sum && right.sum >= cross.sum)
		return right;

	return cross;
}

subarray find_max_crossing_subarray(vector<int> &A, int low, int mid, int high){

	// find best left-array
	int sum = 0;
	subarray left{0, mid, min_inf};

	for(int i = left.high; i >= low; --i){

		sum += A[i];
		if(sum > left.sum) { left.sum = sum; left.low = i; }

	}

	// find best right-array
	subarray right{mid+1, 0, min_inf};
	sum = 0;

	for(int j = right.low; j <= high; ++j){

		sum += A[j];
		if(sum > right.sum) { right.sum = sum; right.high = j; }
	}
		
	// merge to return
	return {left.low, right.high, left.sum + right.sum};
}

subarray incremental_max_subarray(vector<int> &A){

	subarray m{0, 0, min_inf};
	subarray cur{0, 0, 0};

	for(cur.high = 0; cur.high < A.size(); ++cur.high){

		cur.sum += A[cur.high];

		if(cur.sum >= m.sum) m = cur;

		if(cur.sum <= 0) { cur.sum = 0; cur.low = cur.high+1; }

	}

	return m;
}
