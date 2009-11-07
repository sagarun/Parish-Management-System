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
	gchar *date_baptism;
	gchar *name;
	gchar *dob;
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

struct baptism_cert cert;
void quick_message(gchar *);
gboolean is_form_valid();
