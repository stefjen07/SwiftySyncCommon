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

void DataUnit::encode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONEncodeContainer* jsonContainer = dynamic_cast<JSONEncodeContainer*>(container);
        std::string bytesStr;
        for (int i = 0; i < bytes.size(); i++) {
            bytesStr += bytes[i];
        }
        jsonContainer->encode(bytesStr, "bytes");
    }
}

void DataUnit::decode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONDecodeContainer* jsonContainer = dynamic_cast<JSONDecodeContainer*>(container);
        std::string bytesStr = jsonContainer->decode(std::string(), "bytes");
        bytes = std::vector<dataByte>();
        for (int i = 0; i < bytesStr.length(); i++) {
            bytes.push_back(bytesStr[i]);
        }
    }
}
#endif