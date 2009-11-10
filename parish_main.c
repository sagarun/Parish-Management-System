#include "parish_main.h"
/*Callbacks related to main window*/
void on_window_button_search_clicked(GtkButton *button,gpointer user_data)
{
  GtkWidget *widget;
  widget=(GtkWidget *)(gtk_builder_get_object(build,"search_main"));
  gtk_widget_show(widget);

}

void on_window_button_baptism_clicked(GtkButton *button,gpointer user_data)
{
	GtkWidget *window;
	window=(GtkWidget *)(gtk_builder_get_object(build,"window_baptism"));
	gtk_widget_show(window);
}

void on_window_button_marriage_clicked(GtkButton *button,gpointer user_data)
{
  
  quick_message("Not yet Implemented");

}

int main(int argc,char *argv[])
{
	GtkWidget *win;
	GError *error=NULL;
	int sqlitestatus;
	gtk_init(&argc,&argv);
	build = gtk_builder_new();
	gtk_builder_add_from_file(build,"parish.glade",&error);
	if(error!=NULL)
	{
		g_print("Failed to load the userinterface: %s",error->message);
		g_error_free(error);
		exit(0);
	}
	win = GTK_WIDGET(gtk_builder_get_object(build,"window"));
	gtk_builder_connect_signals(build,NULL);
	/*Add selectable  options to comboboxes */
	add_text_combobox();
	/*Create Sqlitedb get handle*/
	sqlitestatus = sqlite_get_handle();
	if(sqlitestatus == -1)
	  {
	    g_object_unref(G_OBJECT(build));
	    return 0;
	  }
	gtk_widget_show(win);
	gtk_main();
	g_object_unref(G_OBJECT(build));
	return 0;
}
