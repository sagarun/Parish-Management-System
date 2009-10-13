#include <gtk/gtk.h>
#include <glib.h>
#include <sqlite3.h>
GtkBuilder *build;
sqlite3 *handle;

/*callbacks related to main window */
void on_window_button_search_clicked(GtkButton *button,gpointer user_data);
void on_window_button_baptism_clicked(GtkButton *button,gpointer user_data);
void on_window_button_marriage_clicked(GtkButton *button,gpointer user_data);

/*callbacks related to (window_baptism) baptism certificate entry*/
void on_window_baptism_quit_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_clear_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_add_clicked(GtkButton *button,gpointer user_data);

/*utility functions*/

void add_text_window_baptism_sex();


/*Function related to sqlite database intefacing*/
int sqlite_get_handle();
