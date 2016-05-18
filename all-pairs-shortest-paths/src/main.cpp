#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using matrix = vector<vector<int>>;

constexpr int max_inf{numeric_limits<int>::max()};

/* function prototypes */
matrix floyd_warshall(matrix&);

// I/O processing
matrix read_weight_matrix(unsigned);
void display_matrix(matrix&);
matrix init_path_matrix(unsigned);

// aux
int decode(string&);
string encode(int);

/* debug */

int main(){

	unsigned nodes;

	cin >> nodes;

	auto W = read_weight_matrix(nodes);

	auto D = floyd_warshall(W);

	display_matrix(D);

  return 0;
}

/* functions */
matrix floyd_warshall(matrix &W){

	auto D(W);

	for(int k = 0; k < D.size(); ++k)
		for(int i = 0; i < D.size(); ++i)
			for(int j = 0; j < D.size(); ++j)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	return D;

}

matrix read_weight_matrix(unsigned n){

		matrix W(n, vector<int>(n, 0));

		string s;

		for(auto &v : W)
			for(auto &i : v){

				cin >> s;
				i = decode(s);
			}

		return W;
}

void display_matrix(matrix &M){

	for(const auto &v : M){
		for(const auto &i : v)
			cout << encode(i) << " ";

		cout << endl;
	}

}

matrix init_path_matrix(unsigned n){

	matrix P(n, vector<int>(n, -1));

	for(int i = 0; i < P.size(); ++i)
		P[i][i] = i;

	return P;
}

inline
string encode(int i)
{ return (i >= max_inf/4) ? "*" : to_string(i); }

inline
int decode(string &s)
{ return (s[0] == '*') ? max_inf/2 : stoi(s, nullptr); }
