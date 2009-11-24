/*Implements callbacks for search window*/
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

#include "parish_search_main.h"
void on_search_main_cancel_button_clicked(GtkButton *button,gpointer user_data)
{
  GtkWidget *widget;
  widget = (GtkWidget *) gtk_builder_get_object(build,"search_main");
  gtk_widget_hide(widget);

}

void on_search_main_query_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{
  if(!g_regex_match_simple("[a-zA-Z0-9 /.]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
}

void on_search_main_search_button_clicked(GtkButton *button,gpointer user_data)
{
  GtkWidget *widget,*view;
  GString *result;
  GtkTextBuffer *textbuf;
  gchar querystring[30];
  gchar *searchby[] = {"name","dad","mom","date_birth"};
  gchar *table[] = {"baptism_cert","marriage_cert"};
  int radio=0;
  int cbox_index=-1;
  int cols;
  result=g_string_new("");
  if( !is_valid_search(querystring,&cbox_index,&radio))
    {
      return;
    } 
  //Fixme: For now assuming every query goes on baptism_cert table
  do_search(querystring,searchby[cbox_index],table[radio]);
  widget = (GtkWidget *) gtk_builder_get_object(build,"search_main");
  gtk_widget_hide(widget);
  cols = sqlite3_column_count(stmt);
  prepare_results(result,cols);
  view = (GtkWidget *)gtk_builder_get_object(build,"search_results_text");
  textbuf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
  gtk_text_buffer_set_text(textbuf,result->str,-1);
  widget = (GtkWidget *)gtk_builder_get_object(build,"search_results");
  gtk_widget_show(widget);
  
}


gboolean is_valid_search(gchar *querystring,int *cbox_index,int *index)
{
  GtkWidget *widget;
  GtkComboBox *cbox;
  widget = (GtkWidget *) gtk_builder_get_object(build,"search_main_query");
  g_strlcpy(querystring,gtk_entry_get_text(GTK_ENTRY(widget)),30);
  if(g_strcmp0(querystring,"") == 0)
    {
      quick_message("please enter a phrase to search");
      return FALSE;
    }
  
  cbox = (GtkComboBox *) gtk_builder_get_object(build,"search_main_searchby_combobox");
  *cbox_index  = gtk_combo_box_get_active(cbox);
  if(*cbox_index == -1)
    {
      quick_message("please select one filed to search with");
      return FALSE;
    }
  if(*cbox_index == 3)
    {
      /*The user input must be a date so validate it*/
      
      	if(!g_regex_match_simple("^[0-9]{1,2}[/][0-9]{1,2}[/][0-9]{4}$",querystring,0,0))
	{
		quick_message("Invalid Date entry to search");
		return FALSE;
	}	
    }

  //Fixme: Need to find a way to get radio buttons
  *index = 0;
  return TRUE;
  
  

}

void on_search_main_radio2_clicked(GtkButton *button,gpointer user_data)
{

  GtkListStore *store;
  GtkComboBox *cbox;
  store = GTK_LIST_STORE(gtk_builder_get_object(build,"liststore6"));
  cbox = (GtkComboBox *)gtk_builder_get_object(build,"search_main_searchby_combobox");
  gtk_combo_box_set_model(cbox,GTK_TREE_MODEL(store));
  
  
}

void on_search_main_radio1_clicked(GtkButton *button,gpointer user_data)
{

  GtkListStore *store;
  GtkComboBox *cbox;
  store = GTK_LIST_STORE(gtk_builder_get_object(build,"liststore2"));
  cbox = (GtkComboBox *)gtk_builder_get_object(build,"search_main_searchby_combobox");
  gtk_combo_box_set_model(cbox,GTK_TREE_MODEL(store));

}
