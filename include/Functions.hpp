#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Data.hpp"
#include <string>
#include <functional>

class Function {
private:
	std::function<DataUnit(DataUnit)> handler;
public:
	std::string name;

	DataUnit operator[](DataUnit input) {
		return handler(input);
	}

	Function(std::string name, std::function<DataUnit(DataUnit)> handler) {
		this->name = name;
		this->handler = handler;
	}
};

#endif
