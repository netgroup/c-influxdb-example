#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_BUF 32
struct data_point {
	double temperature;
	char city[MAX_BUF];
};

#ifdef __cplusplus
}
#endif

#endif /* COMMON_H */
