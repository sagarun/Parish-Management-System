/* Implements marriage  certificate window's  callbacks */
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
#include "parish_marriage_callbacks.h"

void on_window_marriage_close_clicked(GtkButton *button, gpointer user_data)
{

  GtkWidget *widget;
  widget = (GtkWidget *) gtk_builder_get_object(build,"window_marriage");
  gtk_widget_hide(widget);

}


void on_window_marriage_clear_clicked(GtkButton *button, gpointer user_data)
{
  clear_marriage_records();

}

void clear_marriage_records()
{
	GtkWidget *entry;
	GtkWidget *cbox;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_name");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_name");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_bride_dob_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_bride_dob_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_bride_dob_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_groom_dob_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_groom_dob_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_groom_dob_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_cond");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_cond");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_rank");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_rank");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_father");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_father");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_address");
        gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_address");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_name");
        gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_name");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_addr");
        gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_addr");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_minister_name");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_villi");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_villi");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_dist");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_dist");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_pin");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_pin");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_villi");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_villi");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_dist");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_dist");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_pin");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_pin");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
		
}


void on_window_marriage_bride_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{
  
   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}
void on_window_marriage_bride_cond_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z ]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}
void on_window_marriage_groom_cond_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z ]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}
void on_window_marriage_bride_rank_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{
     if(!g_regex_match_simple("[a-zA-Z ]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_groom_rank_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z ]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_bride_father_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_groom_father_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{
     if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_bride_address_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z0-9 ./,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_groom_address_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z0-9 ./,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_bride_wit_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}

void on_window_marriage_groom_wit_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_bride_wit_addr_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{
     
   if(!g_regex_match_simple("[a-zA-Z0-9 ./,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}

void on_window_marriage_groom_wit_addr_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z0-9 ./,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}

void on_window_marriage_minister_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

     if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}

void on_window_marriage_bride_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{
    if(!g_regex_match_simple("[a-zA-Z0-9 ,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z0-9 ,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_bride_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_bride_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[0-9]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[0-9]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
}

void on_window_marriage_bride_wit_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z0-9 ,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_wit_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z0-9 ,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}
void on_window_marriage_bride_wit_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_wit_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[a-zA-Z]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
}
void on_window_marriage_bride_wit_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[0-9]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }

}
void on_window_marriage_groom_wit_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data)
{

    if(!g_regex_match_simple("[0-9]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }


}
