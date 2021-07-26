#ifndef REQUEST_H
#define REQUEST_H

#include "Codable.h"
#include "JSON.h"
#include "Data.h"
#include "UUID.h"

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
	string id;
	RequestType type;
	ConnectionData* connection;
	virtual void nothing() {};
};

class DataRequest : public Request, public Codable {
public:
	string collectionName;
	string documentName;
	string body;

	void nothing() {}

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	DataRequest(string collectionName, string documentName, string body) {
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
	string value;
	vector<string> path;

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	FieldRequest(string value, vector<string> path) {
		this->value = value;
		this->path = path;
	}

	FieldRequest() {}
};

class FunctionRequest : public Request, public Codable {
public:
	string name;
	DataUnit inputData;

	void encode(CoderContainer* container);

	void decode(CoderContainer* container);

	FunctionRequest(string name, DataUnit input) {
		this->name = name;
		this->inputData = input;
		this->id = create_uuid();
	}

	FunctionRequest() {
		this->id = create_uuid();
	}
};

const vector<RequestType> DATA_REQUEST_TYPES = { RequestType::documentSet, RequestType::documentGet, RequestType::fieldSet, RequestType::fieldGet };
#define DATA_REQUEST_TYPES_COUNT 4

#endif