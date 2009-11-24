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
	char query_baptism[] = "create table if not exists baptism_cert(uid integer primary key autoincrement,kept_at text,place text,date_baptism date,name text,date_birth date,sex text,mom text,dad text,resi text,caste text,sponsor1 text,sponsor2 text,priest text,remarks text)";
	char query_marriage[] = "create table if not exists marriage_cert(uid integer primary key autoincrement,date_marriage date,bride_name text,groom_name text,bride_dob date,groom_dob date,bride_cond text,groom_cond text,bride_rank text,groom_rank text,bride_fname text,groom_fname text,bride_addr text,groom_addr text,bride_villi text,groom_villi text,bride_dist text,groom_dist text,bride_pin text,groom_pin text,bride_wit_name text,groom_wit_name text,bride_wit_addr text,groom_wit_addr text,bride_wit_villi text,groom_wit_villi text,bride_wit_dist text,groom_wit_dist text,bride_wit_pin text,groom_wit_pin text,min_name text)";
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
		retval = sqlite3_exec(handle,query_baptism,0,0,0);
		retval = sqlite3_exec(handle,query_marriage,0,0,0);
		//g_print("Return value after the query: %d",retval);
		return retval;
	}
	
}

void  prepare_baptism_cert_query(GString *query,struct baptism_cert cert)
{
  gchar date_dob[10];
  gchar date_dobap[10];
  prepare_date(cert.dob_date,cert.dob_month,cert.dob_year,&date_dob);
  prepare_date(cert.dobap_date,cert.dobap_month,cert.dobap_year,&date_dobap);
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
  retval = sqlite3_exec(handle,query->str,0,0,0);
  g_string_free(query,TRUE);
  return retval;
}

void do_search(gchar *querystring,gchar *searchby,gchar *table)
{
  GString *query;
  int retval =0;
  query = g_string_new("select * from");
  g_string_append_printf(query," %s","");
  g_string_append_printf(query,"%s",table);
  g_string_append_printf(query," %s","");
  g_string_append_printf(query,"%s","where");
  g_string_append_printf(query," %s","");
  g_string_append_printf(query,"%s",searchby);
  g_string_append_printf(query," %s","");
  g_string_append_printf(query,"%s","like");
  g_string_append_printf(query," %s","");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",querystring);
  g_string_append_printf(query,"%s","'");
  g_print(query->str);
  retval = sqlite3_prepare_v2(handle,query->str,-1,&stmt,0);
  if(retval)
    {
      g_print("something went wrong");
    }
  g_string_free(query,TRUE);
}

int sqlite_store_marriage_cert(marriage_cert cert)
{
  int retval;
  GString *query;
  query = g_string_new("insert into marriage_cert values(NULL,");
  prepare_marriage_cert_query(query,cert);
  retval = sqlite3_exec(handle,query->str,0,0,0);
  g_string_free(query,TRUE);
  return retval;
}


void prepare_marriage_cert_query(GString *query,marriage_cert cert)
{
  gchar date_marriage[10];
  gchar bride_dob[10];
  gchar groom_dob[10];
  prepare_date(cert.marriage_date,cert.marriage_month,cert.marriage_year,&date_marriage);
  prepare_date(cert.bride_dob_date,cert.bride_dob_month,cert.bride_dob_year,&bride_dob);
  prepare_date(cert.groom_dob_date,cert.groom_dob_month,cert.groom_dob_year,&groom_dob);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",date_marriage);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_name);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_name);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",bride_dob);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",groom_dob);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_cond);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_cond);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_rank);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_rank);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_father);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_father);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_addr);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_addr);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_villi);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_villi);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_dist);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_dist);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_pin);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_pin);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_wit_name);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_wit_name);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_wit_addr);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_wit_addr);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_wit_villi);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_wit_villi);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_wit_dist);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_wit_dist);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.bride_wit_pin);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.groom_wit_pin);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",",");
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",cert.minister);
  g_string_append_printf(query,"%s","'");
  g_string_append_printf(query,"%s",")");

}
