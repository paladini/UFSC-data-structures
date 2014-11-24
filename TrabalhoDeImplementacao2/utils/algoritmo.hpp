#include <vector>
using namespace std;

class Algoritmo {

	vector<T>& intersect(const vector<T>& one, const vector<T>& other) {
		vector<T> intersection;
		for (auto it : one) {
			for (auto that : other) {
				if (it == that) {
					intersection.push_back(it);
					break;
				}
			}
		}
		std::swap(one, intersection);
		return one;
	}

};
