/* Implements GUI event callbacks for baptism information entry form*/
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

#include "parish_baptism_callbacks.h"



/* Callbacks related to baptism certificate window */

void on_window_baptism_quit_clicked(GtkButton *button,gpointer user_data)
{
	GtkWidget *widget = (GtkWidget *)(gtk_builder_get_object(build,"window_baptism"));
	gtk_widget_hide(widget);
}

void clear_baptism_records()
{
  	GtkWidget *entry;
	GtkWidget *cbox;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_kept_at");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_place");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dobap_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dobap_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dobap_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_name");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sex");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_mom");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dad");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_resi");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_caste");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp1");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp2");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_priest");
        gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_remarks");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
		
}

void on_window_baptism_clear_clicked(GtkButton *button,gpointer user_data)
{
	clear_baptism_records();
}


void get_baptism_cert(struct baptism_cert *cert)
{
	GtkWidget *entry;
	GtkWidget *cbox;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_kept_at");
	cert->kept_at = (gchar *)gtk_entry_get_text(GTK_ENTRY (entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_place");
	cert->place = (gchar *)gtk_entry_get_text(GTK_ENTRY (entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_name");
	cert->name = (gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob_date");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->dob_date = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
	else
		cert->dob_date =NULL;

	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob_month");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->dob_month =(gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
	else
		cert->dob_month=NULL;

	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob_year");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->dob_year = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));	

	}
	else
		cert->dob_year=NULL;

	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dobap_date");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->dobap_date = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
	else
		cert->dobap_date = NULL;

	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dobap_month");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->dobap_month = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
	else
		cert->dobap_month = NULL;

	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dobap_year");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->dobap_year = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	}
	else
		cert->dobap_year = NULL;

	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sex");
	if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->sex = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	}
	else
		cert->sex = NULL;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_mom");
	cert->mom =(gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dad");
	cert->dad =(gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_resi");
	cert->resi = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_caste");
	cert->caste  = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp1");
	cert->spon1 =(gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp2");
	cert->spon2 = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_priest");
        cert->priest = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_remarks");
	cert->remarks = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));

}


void on_window_baptism_add_clicked(GtkButton *button,gpointer user_data)
{
  int retval;
  struct baptism_cert cert;
  get_baptism_cert(&cert);
  if(!is_form_valid(&cert))
    {
      quick_message("None of the fileds should be empty");
      return;
    }
  retval = sqlite_store_baptism_cert(cert);
  if(retval == 0)
	{
		quick_message("Record added successfully");
		clear_baptism_records();
	}
		
}

void on_window_baptism_remarks_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{
  if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_kept_at_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_place_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_mom_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_dad_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_priest_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_sp1_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_sp2_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_caste_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z ]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_resi_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[0-9a-zA-Z .,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

/* The code below is obsolete,as the date handling was changed entirely */

/*void on_window_baptism_dob_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{
	if(!g_regex_match_simple("[0-9/]+",new_text,0,0))
	{
		g_signal_stop_emission_by_name(editable,"insert-text");
	}
}
void on_window_baptism_date_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{
	if(!g_regex_match_simple("[0-9/]+",new_text,0,0))
	{
		g_signal_stop_emission_by_name(editable,"insert-text");
	}
x}

gboolean on_window_baptism_dob_focus_out_event(GtkWidget *widget,GdkEventFocus *event,gpointer user_data)
{
	if(!g_regex_match_simple("[0-9]{1,2}[/][0-9]{1,2}[/][0-9]{4}",gtk_entry_get_text((GtkEntry *)widget),0,0))
	{
		quick_message("Invalid Date entry in Date of birth field");
	}
	return FALSE;
}

gboolean on_window_baptism_date_focus_out_event(GtkWidget *widget,GdkEventFocus *event,gpointer user_data)
{
	if(!g_regex_match_simple("[0-9]{1,2}[/][0-9]{1,2}[/][0-9]{4}",gtk_entry_get_text((GtkEntry *)widget),0,0))
	{
		quick_message("Invalid Date entry in Baptism Date filed");
	}
	return FALSE;
}
*/
