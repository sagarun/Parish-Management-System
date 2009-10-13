#include "parish_callbacks.h"

int  sqlite_get_handle()
{
	int retval;
	char query[600] = "create table if not exists baptism_cert(uid integer primary key autoincrement,kept_at text,place text,date_baptism date,name text,date_birth date,sex text,mom text,dad text,resi text,caste text,sponsor1 text,sponsor2 text,priest text,remarks text";

	retval = sqlite3_open("parish.sqlite3",&handle);
	if(retval)
	{
		g_print("something went wrong with the database,return value:%d", retval);	
		return -1;
	}
	else
	{
		retval = sqlite3_exec(handle,query,0,0,0);
		g_print("Return value after the query: %d",retval);
	}
	
}
