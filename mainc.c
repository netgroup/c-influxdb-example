
#include <stdio.h>
#include <errno.h>

#include "influxdb_wrapper_int.h"

int main()
{
	MHandler_t *h = create_influxdb("http://localhost:8086?db=temperature_db");
	if (!h) {
		printf("Cannot create MHandler\n");
		return -ENOMEM;
	}

	show_databases_influxdb(h);

	destroy_influxdb(h);

	printf(" *** Done ***\n");

	return 0;
}
