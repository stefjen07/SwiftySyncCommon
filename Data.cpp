#include "Data.h"

void DataUnit::encode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONEncodeContainer* jsonContainer = dynamic_cast<JSONEncodeContainer*>(container);
        string bytesStr;
        for (int i = 0; i < bytes.size(); i++) {
            bytesStr += bytes[i];
        }
        jsonContainer->encode(bytesStr, "bytes");
    }
}

void DataUnit::decode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONDecodeContainer* jsonContainer = dynamic_cast<JSONDecodeContainer*>(container);
        string bytesStr = jsonContainer->decode(string(), "bytes");
        bytes = vector<dataByte>();
        for (int i = 0; i < bytesStr.length(); i++) {
            bytes.push_back(bytesStr[i]);
        }
    }
}