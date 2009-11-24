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

void on_window_marriage_add_clicked(GtkButton *button,gpointer user_data)
{
  marriage_cert cert;
  get_marriage_cert(&cert);
  if(!is_marriage_cert_valid(cert))
    {
          quick_message("None of the fileds should be empty");
	  return;
    }
  sqlite_store_marriage_cert(cert);

}

void clear_marriage_records()
{
	GtkWidget *entry;
	GtkWidget *cbox;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_name");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_name");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_dob_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_dob_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_dob_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_dob_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_dob_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_dob_year");
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

void get_marriage_cert(marriage_cert *cert)
{
  GtkWidget *entry;
  GtkComboBox *cbox;
  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_date");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
		cert->marriage_date  = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->marriage_date = NULL;

  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_month");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
		cert->marriage_month  = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->marriage_month = NULL;

  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_year");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
		cert->marriage_year  = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->marriage_year = NULL;

  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_name");
  cert->bride_name = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_name");
  cert->groom_name = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_cond");
  cert->bride_cond = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_cond");
  cert->groom_cond = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_rank");
  cert->bride_rank = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_rank");
  cert->groom_rank = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_father");
  cert->bride_father = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_father");
  cert->groom_father = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_address");
  cert->bride_addr = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_address");
  cert->groom_addr = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_villi");
  cert->bride_villi = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_villi");
  cert->groom_villi = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_dist");
  cert->bride_dist = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_dist");
  cert->groom_dist = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_pin");
  cert->bride_pin = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_pin");
  cert->groom_pin = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_bride_dob_date");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->bride_dob_date  =(gchar *) gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->bride_dob_date = NULL;

  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_bride_dob_month");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->bride_dob_month  = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->bride_dob_month = NULL;

  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_bride_dob_year");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->bride_dob_year  = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->bride_dob_year = NULL;
  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_groom_dob_date");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->groom_dob_date  = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->bride_dob_date = NULL;

  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_groom_dob_month");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->groom_dob_month  = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->groom_dob_month = NULL;

  cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_marriage_groom_dob_year");
  if(gtk_combo_box_get_active((GtkComboBox *)(cbox))!=-1)
	{
	  cert->groom_dob_year  = (gchar *)gtk_combo_box_get_active_text((GtkComboBox *)(cbox));

	}
  else
    cert->groom_dob_year = NULL;
  
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_addr");
  cert->bride_wit_addr = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_addr");
  cert->groom_wit_addr = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_villi");
  cert->bride_wit_villi = (gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_villi");
  cert->groom_wit_villi = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_dist");
  cert->bride_wit_dist = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_dist");
  cert->groom_wit_dist = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_pin");
  cert->bride_wit_pin = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_pin");
  cert->groom_wit_pin = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_bride_wit_name");
  cert->bride_wit_name = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_groom_wit_name");
  cert->groom_wit_name = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));
  entry = (GtkWidget *)gtk_builder_get_object(build,"window_marriage_minister_name");
  cert->minister = (gchar *)gtk_entry_get_text(GTK_ENTRY(entry));

  
}

gboolean is_marriage_cert_valid(marriage_cert cert)
{
  if(cert.marriage_date == NULL)
    return FALSE;
 else if(cert.marriage_month == NULL)
    return FALSE;
  else if(cert.marriage_year == NULL)
    return FALSE;
  else if(cert.bride_dob_date == NULL)
    return FALSE;
  else if(cert.bride_dob_month == NULL)
    return FALSE;
  else if(cert.bride_dob_year == NULL)
    return FALSE;
  else if(cert.groom_dob_date == NULL)
    return FALSE;
  else if(cert.groom_dob_month == NULL)
    return FALSE;
  else if(cert.groom_dob_year == NULL)
    return FALSE;
  else if(g_strcmp0(cert.bride_name,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_name,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_cond,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_cond,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_rank,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_rank,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_father,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_father,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_addr,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_addr,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_dist,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_dist,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_pin,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_pin,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_villi,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_villi,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_wit_name,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_wit_name,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_wit_addr,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_wit_addr,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_wit_dist,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_wit_dist,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_wit_villi,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_wit_villi,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.bride_wit_pin,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.groom_wit_pin,"")==0)
    return FALSE;
  else if(g_strcmp0(cert.minister,"")==0)
    return FALSE;
  else
    return TRUE;

}

