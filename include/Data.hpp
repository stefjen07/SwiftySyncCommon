#ifndef DATA_H
#define DATA_H

#include "Codable.hpp"
#include "JSON.hpp"
#include <vector>

typedef char dataByte;

class DataUnit: public Codable {
public:
	std::vector<dataByte> bytes;

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	DataUnit(std::vector<char> bytes) {
		this->bytes = bytes;
	}

	DataUnit() {}
};
#endif