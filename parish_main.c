#include "parish_baptism_callbacks.h"

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
	/*Add 'Male' and 'Female' option to combobox */
	add_text_window_baptism_sex();
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
