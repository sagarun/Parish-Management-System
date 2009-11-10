/* Implements operation related to sqlite3 db*/
/*  Copyright (C) 2009  Arun S.A.G.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include "database.h"

int  sqlite_get_handle()
{
	int retval;
	gchar *path;
	gint size=0;
	char query[] = "create table if not exists baptism_cert(uid integer primary key autoincrement,kept_at text,place text,date_baptism date,name text,date_birth date,sex text,mom text,dad text,resi text,caste text,sponsor1 text,sponsor2 text,priest text,remarks text)";
	size=strlen(g_getenv("HOME"));
	size=size+24;
	path=g_malloc(size);
	g_strlcpy(path,g_getenv("HOME"),size);
	g_strlcat(path,"/.parish/parish.sqlite3",size);
	retval = sqlite3_open(path,&handle);
	g_free(path);
	if(retval)
	{
		g_print("something went wrong with the database,return value:%d", retval);	
		return -1;
	}
	else
	{
		retval = sqlite3_exec(handle,query,0,0,0);
		//g_print("Return value after the query: %d",retval);
		return retval;
	}
	
}

void  prepare_baptism_cert_query(GString *query,struct baptism_cert cert)
{
  gchar date_dob[10];
  gchar date_dobap[10];
  baptism_prepare_date(cert,&date_dob,&date_dobap);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.kept_at);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.place);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",date_dobap);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.name);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",date_dob);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.sex);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.mom);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.dad);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.resi);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.caste);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.spon1);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.spon2);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.priest);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.remarks);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",")");  
}

int sqlite_store_baptism_cert(struct baptism_cert cert)
{
  int retval;
  GString *query;
  query = g_string_new("insert into baptism_cert values(NULL,");
  prepare_baptism_cert_query(query,cert);
  g_print(query->str);
  retval = sqlite3_exec(handle,query->str,0,0,0);
  g_string_free(query,TRUE);
  return retval;
}
