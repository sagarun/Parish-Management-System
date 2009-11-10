#ifndef DATABASE
#define DATABASE
#include "parish_common.h"
/*Function related to sqlite database intefacing*/
int sqlite_get_handle();
int sqlite_store_baptism_cert(struct baptism_cert cert);
void  prepare_baptism_cert_query(GString *query,struct baptism_cert cert);
#endif
