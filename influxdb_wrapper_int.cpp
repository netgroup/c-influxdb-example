
#include "influxdb_wrapper.hpp"
#include "influxdb_wrapper_int.h"

/* declared in magic_interface.h but defined here */
struct MHandler {
	void *obj;
};

MHandler_t *create_influxdb(const char *uri)
{
	InfluxDBWrapper *obj;
	MHandler_t *h;

	h = (typeof(h))malloc(sizeof(*h));
	if (!h)
		return NULL;

	try {
		obj = new InfluxDBWrapper(uri);
	} catch(...) {
		/* an exception occurred during wrapper creation */
		free(h);
		return NULL;
	}

	h->obj = obj;
	return h;
}

void show_databases_influxdb(MHandler_t *h)
{
	InfluxDBWrapper *obj;

	obj = static_cast<InfluxDBWrapper *>(h->obj);
	obj->showDatabases();
}

void destroy_influxdb(MHandler_t *h)
{
	InfluxDBWrapper *obj;

	obj = static_cast<InfluxDBWrapper *>(h->obj);
	/* Delete the obj instance */
	delete obj;

	/* destroy the opaque handler */
	free(h);
}

int write_temp_influxdb(MHandler_t *h, const char *city, double temp)
{
	InfluxDBWrapper *obj;

	obj = static_cast<InfluxDBWrapper *>(h->obj);
	return obj->writeTemperature(city, temp);
}

int write_temp_influxdb_struct(MHandler_t *h, const struct data_point *dp)
{
	/* we could have reused the write_temp_influxdb but we prefer to
         * implement a new C++ function accepting the data structure
         * @data_point.
         */
	InfluxDBWrapper *obj;

	obj = static_cast<InfluxDBWrapper *>(h->obj);
	return obj->writeTemperatureDataPoint(dp);
}
