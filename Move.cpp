#include "Move.h"

Move::Move(Market &m,Hand &h): market(m), hand(h)
{}

Move::~Move()
{}

vector<int> Move::getIndexes(bool *arr, int size) {
	vector<int> indexes;
	for (int i = 0; i < size; i++) {
		if (arr[i]){
			indexes.push_back(i);
		}
	}
	return indexes;
}

