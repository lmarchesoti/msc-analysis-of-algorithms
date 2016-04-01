#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

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

  auto closest = brute_closest_pair(in);

  cout << "(" << closest.first.x << ", " << closest.first.y << ") "
       << "(" << closest.second.x << ", " << closest.second.y << ") "
       << dist(closest.first, closest.second) << endl;

  return 0;
}

double dist(const point &p, const point &q) { return sqrt( (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) ); }

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

pair<point, point> dc_closest_pair(vector<point> &points);
