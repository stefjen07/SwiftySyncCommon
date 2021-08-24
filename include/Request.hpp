#ifndef REQUEST_H
#define REQUEST_H

#include "Codable.hpp"
#include "JSON.hpp"
#include "Data.hpp"
#include "UUID.hpp"

#define MESSAGE_PREFIX "MES"
#define MESSAGE_ID "00000000-0000-0000-0000-000000000000"

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

#endif
