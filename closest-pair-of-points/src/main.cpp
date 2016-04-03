#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

constexpr double max_inf{numeric_limits<double>::max()};
constexpr unsigned inliers = 5;

typedef struct { double x, y; } point;

typedef struct { pair<point, point> points; double dist; } ppair;

double dist(const point&, const point&);

ppair brute_closest_pair(const vector<point>&);

ppair dc_closest_pair(const vector<point>&);

ppair dc_closest_recursion(const vector<point>&, const vector<point>&);

ppair box_closest(const vector<point>&, ppair);

ppair check_coincident(const vector<point>&);

int main(){

  vector<point> in;
  point c;

  while(cin >> c.x >> c.y) in.push_back(c);

  //auto closest = brute_closest_pair(in);
  auto closest = dc_closest_pair(in);

  cout << "(" << closest.points.first.x << ", " << closest.points.first.y << ") "
		 << "(" << closest.points.second.x << ", " << closest.points.second.y << ") "
		 << closest.dist << endl;

  return 0;
}

double dist(const point &p, const point &q)
	{ return sqrt( (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) ); }

// take the minimum out of all n^2 distances
ppair brute_closest_pair(const vector<point> &points){

	ppair closest;
	closest.dist = max_inf;

  for(auto p = points.begin(); p != points.end(); ++p)

    for(auto q = p + 1; q != points.end(); ++q){

      double cur = dist(*p, *q);

      if(cur < closest.dist){

				closest.points = make_pair(*p, *q);
				closest.dist = cur;
      }
    }

  return closest;
}

ppair dc_closest_pair(const vector<point> &points){

  // implement using sort(quicksort)
  // check if we REALLY need to implement our mergesort
  // use <algorithm> merge (or inplace_merge) if so

  vector<point> X{points}, Y{points};

	// order points absolutely by x-coordinate
	// and relatively by y-coordinate
  sort(X.begin(), X.end(), [](const point &p, const point &q)
		{ return (p.x < q.x) ? true : (p.x == q.x) ? p.y < q.y : false; });

	// order points by y-coordinate only
  sort(Y.begin(), Y.end(), [](const point &p, const point &q)
		{ return p.y < q.y; });

	// pre-process for coincident points
	auto coincident = check_coincident(X);
	if(coincident.dist == 0) return coincident;

	return dc_closest_recursion(X, Y);
}

// sorts the point vector and check if the minimum is
// on its left-side, right-side, or in-between
ppair dc_closest_recursion(const vector<point> &X, const vector<point> &Y){

  if(X.size() <= 3) return brute_closest_pair(X);

	vector<point> Xl, Xr, Yl, Yr;

	/* DIVIDE */
	// find partition pivot
	auto mid = X.size() / 2;
	auto pivot = X.at(mid);

	// partition X
	copy(X.begin(), X.begin() + mid, back_inserter(Xl));
	copy(X.begin() + mid, X.end(), back_inserter(Xr));

	// partition Y
	copy_if(Y.begin(), Y.end(), back_inserter(Yl), [pivot](const point &p)
			{ return p.x < pivot.x || (p.x == pivot.x && p.y < pivot.y); });

	copy_if(Y.begin(), Y.end(), back_inserter(Yr), [pivot](const point &p)
			{ return p.x > pivot.x || (p.x == pivot.x && p.y > pivot.y); });

	/* CONQUER */
	auto left  = dc_closest_recursion(Xl, Yl);
	auto right = dc_closest_recursion(Xr, Yr);
	auto closest = left.dist <= right.dist ? left : right;

	/* COMBINE */
	vector<point> Y_;

	// create a vector within the 2sigma distance around the pivot
	copy_if(Y.begin(), Y.end(), back_inserter(Y_), [pivot, closest](const point &p)
			{ return abs(p.x - pivot.x) < closest.dist; });

	// check if there is a closest pair of points that crosses the strip
	auto cross = box_closest(Y_, closest);
	closest = closest.dist <= cross.dist ? closest : cross;

  return closest;
}

ppair box_closest(const vector<point> &Y_, ppair closest){

	for(auto p = Y_.cbegin(); p != Y_.cend(); ++p)

		for(unsigned i = 1; i <= inliers && (p+i) < Y_.cend(); ++i){

			auto d = dist(*p, *(p+i));

			if(d < closest.dist)
				{ closest.points = make_pair(*p, *(p+i)); closest.dist = d; }

		}

	return closest;
}

ppair check_coincident(const vector<point> &points){

	for(auto b = points.begin(), n = b + 1; n != points.end(); ++b, ++n)
		if(b->x == n->x && b->y == n->y) return {{*b, *n}, 0};

	return {{{0, 0}, {0, 0}}, -1};
}
