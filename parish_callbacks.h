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

/*callbacks related to main window */
void on_window_button_search_clicked(GtkButton *button,gpointer user_data);
void on_window_button_baptism_clicked(GtkButton *button,gpointer user_data);
void on_window_button_marriage_clicked(GtkButton *button,gpointer user_data);

/*callbacks related to (window_baptism) baptism certificate entry*/
void on_window_baptism_quit_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_clear_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_add_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_remarks_insert_text(GtkEditable  *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_kept_at_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_place_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_dad_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_mom_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_sp2_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_sp1_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_priest_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_resi_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_caste_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_dob_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_date_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
gboolean on_window_baptism_dob_focus_out_event(GtkWidget *widget,GdkEventFocus *event,gpointer user_data);
gboolean on_window_baptism_date_focus_out_event(GtkWidget *widget,GdkEventFocus *event,gpointer user_data);

/*utility functions*/

void add_text_window_baptism_sex();
void quick_message(gchar *);
gboolean is_form_valid();

/*Function related to sqlite database intefacing*/
int sqlite_get_handle();
int sqlite_store_baptism_cert();
void  prepare_baptism_cert_query(GString *query);
