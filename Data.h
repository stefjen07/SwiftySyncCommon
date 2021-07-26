#ifndef DATA_H
#define DATA_H

#include "Codable.h"
#include "JSON.h"
#include <vector>

typedef char dataByte;

using namespace std;

class DataUnit: public Codable {
public:
	vector<dataByte> bytes;

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	DataUnit(vector<char> bytes) {
		this->bytes = bytes;
	}

	DataUnit() {}
};
#endif