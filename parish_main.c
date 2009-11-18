/* Implements Application's master window and its callbacks*/
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

void on_menu_item_about_activate(GtkMenuItem *item,gpointer user_data)
{
  GtkWidget *widget;
  widget = (GtkWidget *)gtk_builder_get_object(build,"parish_about");
  gtk_about_dialog_set_wrap_license((GtkAboutDialog *)widget,TRUE);
  gtk_widget_show(widget);

}
