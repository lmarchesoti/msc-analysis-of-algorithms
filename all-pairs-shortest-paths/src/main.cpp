#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int min_inf{numeric_limits<int>::min()};

/* function prototypes */
vector<vector<int>> floyd_warshall(vector<vector<int>>&);

// I/O processing
vector<vector<int>> read_weight_matrix(unsigned);
void display_matrix(vector<vector<int>>&);

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
vector<vector<int>> floyd_warshall(vector<vector<int>> &W){

/*
	int kcost;

	// fill in base cases
	for(int i = 1; i < nodes; ++i)
		for(int j = 1; j < nodes; ++j){
			spaths[i][j] = weights[i][j];
			paths[i][j] = j;
		}

	// fill shortest paths matrix
	for(int k = 1; k < nodes; ++k)
		for(int i = 1; i < nodes; ++i)
			for(int j = 1; j < nodes; ++j){
				// cost-only one-liner
				//spaths[i][j] = min(spaths[i][j], spaths[i][k] + spaths[k][j]);
				// cost + path
				kcost = spaths[i][k] + spaths[k][j];
				if(kcost < spaths[i][j]){
					spaths[i][j] = kcost;
					paths[i][j] = k;
				}
			}
*/

}

vector<vector<int>> read_weight_matrix(unsigned n){

		vector<vector<int>> W(n, vector<int>(n, 0));

		string s;

		for(auto &v : W)
			for(auto &i : v){
				cin >> s;
				i = decode(s);
			}

		return W;
}

void display_matrix(vector<vector<int>> &M){

		// print all costs
		for(const auto &v : M){
			for(const auto &i : v)
				cout << encode(i) << " ";
			cout << endl;
		}

/*
		// print all shortest paths
		cout << "shortest paths: " << endl;
		for(int i = 1; i < nodes; ++i){
			for(int j = 1; j < nodes; ++j){
				if(i != j){
					cout << i << " ";
					int k = paths[i][j];
				//	while(k != j){
				//		cout << k << " ";
				//		k = paths[k][j];
				//	}
					cout << j << endl;
				}
			}
		}
				
		cout << endl;
	*/

}

inline
string encode(int i)
{ return (i == min_inf) ? "*" : to_string(i); }

inline
int decode(string &s)
{ return (s[0] == '*') ? min_inf : stoi(s, nullptr); }
