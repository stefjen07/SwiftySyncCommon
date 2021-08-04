#ifndef REQUEST_H
#define REQUEST_H

#include "Codable.hpp"
#include "JSON.hpp"
#include "Data.hpp"
#include "UUID.hpp"

class ConnectionData;

enum class RequestType {
	documentSet,
	documentGet,
	fieldSet,
	fieldGet,
	function,
	undefined
};

class Request {
public:
	std::string id;
	RequestType type;
	ConnectionData* connection;
	virtual void nothing() {};
};

class DataRequest : public Request, public Codable {
public:
	std::string collectionName;
	std::string documentName;
	std::string body;

	void nothing() {}

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	DataRequest(std::string collectionName, std::string documentName, std::string body) {
		this->collectionName = collectionName;
		this->documentName = documentName;
		this->body = body;
		this->id = create_uuid();
	}

	DataRequest() {
		this->id = create_uuid();
	}
};

class FieldRequest : public Codable {
public:
	std::string value;
	std::vector<std::string> path;

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	FieldRequest(std::string value, std::vector<std::string> path) {
		this->value = value;
		this->path = path;
	}

	FieldRequest() {}
};

class FunctionRequest : public Request, public Codable {
public:
	std::string name;
	DataUnit inputData;

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	FunctionRequest(std::string name, DataUnit input) {
		this->name = name;
		this->inputData = input;
		this->id = create_uuid();
	}

	FunctionRequest() {
		this->id = create_uuid();
	}
};

const std::vector<RequestType> DATA_REQUEST_TYPES = { RequestType::documentSet, RequestType::documentGet, RequestType::fieldSet, RequestType::fieldGet };
#define DATA_REQUEST_TYPES_COUNT 4

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
        collectionName = jsonContainer->decode(std::string(), "collection");
        documentName = jsonContainer->decode(std::string(), "document");
        body = jsonContainer->decode(std::string(), "body");
        id = jsonContainer->decode(std::string(), "id");
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
        value = jsonContainer->decode(std::string(), "value");
        path = jsonContainer->decode(std::vector<std::string>(), "path");
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
        name = jsonContainer->decode(std::string(), "name");
        inputData = jsonContainer->decode(DataUnit(), "input");
        id = jsonContainer->decode(std::string(), "id");
    }
}

#endif
