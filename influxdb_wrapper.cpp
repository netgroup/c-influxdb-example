
#include "influxdb_wrapper.hpp"

InfluxDBWrapper::InfluxDBWrapper(const char *uri) {
	std::string cppString = uri;

	//TODO: handle exceptions
	db = influxdb::InfluxDBFactory::Get(cppString);
	db->createDatabaseIfNotExists();
}

InfluxDBWrapper::~InfluxDBWrapper() {
	db.reset();
}

void InfluxDBWrapper::showDatabases() {
	for (auto i: db->query("SHOW DATABASES"))
		std::cout << i.getTags() <<std::endl;
}
