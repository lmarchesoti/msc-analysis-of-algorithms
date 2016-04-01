#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr double max_inf{numeric_limits<double>::max()};

typedef struct { double x, y; } point;

double dist(const point&, const point&);

pair<point, point> brute_closest_pair(vector<point>&);

pair<point, point> dc_closest_pair(vector<point>&);

int main(){

  vector<point> in;
  point c;

  while(cin >> c.x >> c.y) in.push_back(c);

  //auto closest = brute_closest_pair(in);
  auto closest = dc_closest_pair(in);

  cout << "(" << closest.first.x << ", " << closest.first.y << ") "
       << "(" << closest.second.x << ", " << closest.second.y << ") "
       << dist(closest.first, closest.second) << endl;

  return 0;
}

double dist(const point &p, const point &q) { return sqrt( (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) ); }

// take the minimum out of all n^2 distances
pair<point, point> brute_closest_pair(vector<point> &points){

  pair<point, point> closest;
  double min = max_inf;

  for(auto p = points.begin(); p != points.end(); ++p)

    for(auto q = p + 1; q != points.end(); ++q){

      double cur = dist(*p, *q);

      if(cur < min){

	closest.first = *p;
	closest.second = *q;
	min = cur;
      }
    }

  return closest;
}

// sorts the point vector and check if the minimum is
// on its left-side, right-side, or in-between
pair<point, point> dc_closest_pair(vector<point> &points){

  // implement using sort(quicksort)
  // check if we REALLY need to implement our mergesort
  // use <algorithm> merge (or inplace_merge) if so

  if(points.size() <= 3) return brute_closest_pair(points);

  vector<point> X{points}, Y{points};

  sort(X.begin(), X.end(),
    [](const point &p, const point &q) { return p.x < q.x; });

  sort(Y.begin(), Y.end(),
    [](const point &p, const point &q) { return p.y < q.y; });

  /* TODO */

  return {{0, 0}, {0, 0}};
}
