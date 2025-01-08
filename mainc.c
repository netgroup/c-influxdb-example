
#include <stdio.h>
#include <errno.h>

#include "influxdb_wrapper_int.h"

#define INFLUXDB_URL "http://localhost:8086?db=temperature_db"

int main()
{
	struct data_point dp = {
		.city = "S.T. Gallura",
		.temperature = 25.2,
	};
	MHandler_t *h;

	h = create_influxdb(INFLUXDB_URL);
	if (!h) {
		printf("Cannot create MHandler\n");
		return -EINVAL;
	}

	show_databases_influxdb(h);

	write_temp_influxdb(h, "Rome", 14.1);
	write_temp_influxdb_struct(h, &dp);

	destroy_influxdb(h);
	h = NULL;

	printf(" *** Done ***\n");

	return 0;
}
