#include "parish_callbacks.h"

/*Callbacks related to main window*/
void on_window_button_search_clicked(GtkButton *button,gpointer user_data)
{

}

void on_window_button_baptism_clicked(GtkButton *button,gpointer user_data)
{
	GtkWidget *window;
	window=(GtkWidget *)(gtk_builder_get_object(build,"window_baptism"));
	gtk_widget_show(window);
}

void on_window_button_marriage_clicked(GtkButton *button,gpointer user_data)
{

}

/*Adds text to window_baptism_sex combo box*/
void add_text_window_baptism_sex()
{
	GtkCellRenderer *cell;
	GtkComboBox *cbox;
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_sex"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
}

/* Callbacks related to baptism certificate window */

void on_window_baptism_quit_clicked(GtkButton *button,gpointer user_data)
{
	GtkWidget *widget = (GtkWidget *)(gtk_builder_get_object(build,"window_baptism"));
	gtk_widget_hide(widget);
}

void on_window_baptism_clear_clicked(GtkButton *button,gpointer user_data)
{
		
}

