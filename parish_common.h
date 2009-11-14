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

void quick_message(gchar *);
gboolean is_form_valid(struct baptism_cert *cert);
void add_text_combobox();
void baptism_prepare_date(struct baptism_cert cert,gchar *date_dob,gchar *date_dobap);
void prepare_results(GString *result,int cols);
void get_column_name(int i,gchar *col_name);

#endif
