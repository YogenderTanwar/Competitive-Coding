// Input generator file
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int numberOfTestCaseFiles = 10;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	// os<<"[";
	for (int i = 0; i < v.size(); ++i) {
		// if (i) os << ", ";
		os << v[i] << " ";
	}
	// os << "]\n";
	return os;
}
int random(int folds = 1) {
	if (!folds) return 1;
	return rand() * random(folds - 1);
}
int genInt(int s, int e) {  // [s , e)
	int range = (e - s);
	int folds = 1, crange = 1;
	while (crange < range && crange < (LONG_MAX / RAND_MAX)) {
		++folds;
		crange *= RAND_MAX;
	}
	int val = random(folds) % range;
	return val + s;
}

int32_t main() {
	srand(time(0));
	for (int fileIdx = 1; fileIdx <= numberOfTestCaseFiles; ++fileIdx) {
		// freopen("in.txt" , "r" , stdin);
		ofstream fout;
		fout.open("in" + to_string(fileIdx) + ".txt");

		// generate an int
		int N = genInt(-5000, 10001);
		fout << N << endl;

		// generate a vector
		int sz = genInt(1, 1000);
		vector<int> v(sz);
		for (auto& i : v) {
			i = genInt(0, 1e16);
		}

		fout << sz << endl;  // size of the vector
		fout << v << endl;

		// generate other vector of same size
		vector< int > v2(sz);
		for (auto &i : v2)  {
			i = genInt(0 , 1e16);
		}
		fout << v2 << endl;


		// for (auto& i : v) fout << i << " ";
		// fout << endl;
		cout << "File in" << fileIdx << ".txt generated!" << endl;
	}
}

