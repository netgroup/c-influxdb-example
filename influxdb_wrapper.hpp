
#ifndef INFLUXDB_WRAPPER_HPP
#define INFLUXDB_WRAPPER_HPP

#include <iostream>
#include <InfluxDBFactory.h>

class InfluxDBWrapper {
public:
	InfluxDBWrapper(const char *uri);
	~InfluxDBWrapper();
	void showDatabases();
private:
	std::unique_ptr<influxdb::InfluxDB> db;
};

#endif
