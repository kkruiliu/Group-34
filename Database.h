#pragma once
#include <fstream>
#include <json/json.h>

using namespace std;

Json::Value readData() {
	ifstream file("Database.json");
	Json::Reader reader;
	Json::Value data;

	reader.parse(file, data);

	file.close();

	return data;
}

void writeData(Json::Value& data) {
	Json::StyledStreamWriter writer;
	ofstream closer;
	closer.open("Database.json");
	closer.close();
	ofstream file;
	file.open("Database.json");

	writer.write(file, data);
}