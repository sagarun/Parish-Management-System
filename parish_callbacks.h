#include <gtk/gtk.h>
#include <glib.h>
GtkBuilder *build;

/*callbacks related to main window */
void on_window_button_search_clicked(GtkButton *button,gpointer user_data);
void on_window_button_birth_clicked(GtkButton *button,gpointer user_data);
void on_window_button_marriage_clicked(GtkButton *button,gpointer user_data);

/*callbacks related to (window_birth) birth certificate entry*/
void on_window_birth_quit_clicked(GtkButton *button,gpointer user_data);
void on_window_birth_clear_clicked(GtkButton *button,gpointer user_data);
void on_window_birth_add_clicked(GtkButton *button,gpointer user_data);

/*utility functions*/

void add_text_window_birth_sex();
