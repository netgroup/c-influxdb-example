
#include "influxdb_wrapper.hpp"

InfluxDBWrapper::InfluxDBWrapper(const char *uri) {
	std::string cppString = uri;

	/* throws an exception if we cannot connect to influxdb and/or
	 * create the db.
	 */
	db = influxdb::InfluxDBFactory::Get(cppString);
	db->createDatabaseIfNotExists();
}

InfluxDBWrapper::~InfluxDBWrapper() {
	db.reset();
}

void InfluxDBWrapper::showDatabases() {
	try {
		for (auto i: db->query("SHOW DATABASES"))
			std::cout << i.getTags() <<std::endl;
	} catch (...) { /* do nothing */ }
}
