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

#ifndef PARISH_COMMON
#define PARISH_COMMON
#include <gtk/gtk.h>
#include <glib.h>
#include <sqlite3.h>
#include <string.h>
#include <math.h>

GtkBuilder *build;
sqlite3 *handle;
sqlite3_stmt *stmt;

struct baptism_cert
{
	gchar *kept_at;
	gchar *place;
	gchar *dobap_date;
        gchar *dobap_month;
        gchar *dobap_year;
	gchar *name;
	gchar *dob;
        gchar *dob_date;
        gchar *dob_month;
        gchar *dob_year;
	gchar *sex;
	gchar *mom;
	gchar *dad;
	gchar *resi;
	gchar *caste;
	gchar *spon1;
	gchar *spon2;
	gchar *priest;
	gchar *remarks;
};


typedef struct
{
  gchar *marriage_date;
  gchar *marriage_month;
  gchar *marriage_year;
  gchar *bride_name;
  gchar *groom_name;
  gchar *bride_dob_date;
  gchar *bride_dob_month;
  gchar *bride_dob_year;
  gchar *groom_dob_date;
  gchar *groom_dob_month;
  gchar *groom_dob_year;
  gchar *bride_cond;
  gchar *groom_cond;
  gchar *bride_rank;
  gchar *groom_rank;
  gchar *bride_father;
  gchar *groom_father;
  gchar *bride_addr;
  gchar *bride_villi;
  gchar *bride_dist;
  gchar *bride_pin;
  gchar *groom_addr;
  gchar *groom_villi;
  gchar *groom_dist;
  gchar *groom_pin;
  gchar *bride_wit_name;
  gchar *groom_wit_name;
  gchar *bride_wit_addr;
  gchar *bride_wit_villi;
  gchar *bride_wit_dist;
  gchar *bride_wit_pin;
  gchar *groom_wit_addr;
  gchar *groom_wit_villi;
  gchar *groom_wit_dist;
  gchar *groom_wit_pin;
  gchar *minister;

}marriage_cert;

void quick_message(gchar *);
gboolean is_form_valid(struct baptism_cert *cert);
void add_text_combobox();
void prepare_date(gchar *date,gchar *month,gchar *year,gchar *date_dob);
void prepare_results(GString *result,int cols);
void get_column_name(int i,gchar *col_name);

#endif
