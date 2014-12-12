#include "Move.h"

Move::Move(Market &m,Hand &h): market(m), hand(h)
{}

Move::~Move()
{}

int numElements(bool arr[], int size) {
	int n = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i])
			n++;
	}
	return n;
}

