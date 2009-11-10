#ifndef PARISH_COMMON
#define PARISH_COMMON
#include <gtk/gtk.h>
#include <glib.h>
#include <sqlite3.h>
#include <string.h>

GtkBuilder *build;
sqlite3 *handle;

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
#endif
