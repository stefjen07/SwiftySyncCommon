#include "Request.hpp"
using namespace std;

void DataRequest::encode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONEncodeContainer* jsonContainer = dynamic_cast<JSONEncodeContainer*>(container);
        jsonContainer->encode(collectionName, "collection");
        jsonContainer->encode(documentName, "document");
        jsonContainer->encode(body, "body");
        jsonContainer->encode(id, "id");
    }
}

void DataRequest::decode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONDecodeContainer* jsonContainer = dynamic_cast<JSONDecodeContainer*>(container);
        collectionName = jsonContainer->decode(string(), "collection");
        documentName = jsonContainer->decode(string(), "document");
        body = jsonContainer->decode(string(), "body");
        id = jsonContainer->decode(string(), "id");
    }
}

void FieldRequest::encode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONEncodeContainer* jsonContainer = dynamic_cast<JSONEncodeContainer*>(container);
        jsonContainer->encode(value, "value");
        jsonContainer->encode(path, "path");
    }
}

void FieldRequest::decode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONDecodeContainer* jsonContainer = dynamic_cast<JSONDecodeContainer*>(container);
        value = jsonContainer->decode(string(), "value");
        path = jsonContainer->decode(vector<string>(), "path");
    }
}

void FunctionRequest::encode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONEncodeContainer* jsonContainer = dynamic_cast<JSONEncodeContainer*>(container);
        jsonContainer->encode(name, "name");
        jsonContainer->encode(inputData, "input");
        jsonContainer->encode(id, "id");
    }
}

void FunctionRequest::decode(CoderContainer* container) {
    if (container->type == CoderType::json) {
        JSONDecodeContainer* jsonContainer = dynamic_cast<JSONDecodeContainer*>(container);
        name = jsonContainer->decode(string(), "name");
        inputData = jsonContainer->decode(DataUnit(), "input");
        id = jsonContainer->decode(string(), "id");
    }
}