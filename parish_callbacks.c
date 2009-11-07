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
  	GtkWidget *entry;
	GtkWidget *cbox;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_kept_at");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_place");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_date");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_name");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob");
	gtk_entry_set_text(GTK_ENTRY (entry),"");
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_sex");
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

void get_baptism_cert()
{
	GtkWidget *entry;
	GtkWidget *cbox;
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_kept_at");
	cert.kept_at = gtk_entry_get_text(GTK_ENTRY (entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_place");
	cert.place = gtk_entry_get_text(GTK_ENTRY (entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_date");
	cert.date_baptism = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_name");
	cert.name = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dob");
	cert.dob = gtk_entry_get_text(GTK_ENTRY (entry));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_sex");
	cert.sex = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_mom");
	cert.mom = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dad");
	cert.dad = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_resi");
	cert.resi = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_caste");
	cert.caste  = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp1");
	cert.spon1 = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp2");
	cert.spon2 = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_priest");
        cert.priest = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_remarks");
	cert.remarks = gtk_entry_get_text(GTK_ENTRY(entry));

}


void on_window_baptism_add_clicked(GtkButton *button,gpointer user_data)
{
  int retval;
  get_baptism_cert();
  if(!is_form_valid())
    {
      quick_message("None of the fileds should be empty");
      return;
    }
  retval = sqlite_store_baptism_cert();
}

void on_window_baptism_remarks_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{
  if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_kept_at_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z]+",new_text,0,0))
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

   if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_mom_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_dad_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_priest_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_sp1_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_sp2_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z \s .]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_caste_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[a-zA-Z \s]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_resi_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
{

   if(!g_regex_match_simple("[0-9a-zA-Z \s . ,]+",new_text,0,0))
    {
      g_signal_stop_emission_by_name (editable,"insert-text");
    }
      

}

void on_window_baptism_dob_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data)
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
}

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



/*Utility functions*/
gboolean is_form_valid()
{
  if(g_strcmp0(cert.kept_at,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.place,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.date_baptism,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.name,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.dob,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.mom,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.dad,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.resi,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.caste,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.spon1,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.spon2,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.priest,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert.remarks,"")==0)
    {
      return FALSE;
    }
  return TRUE;
  
}


void quick_message (gchar *message) 
{
   	GtkWidget *dialog, *label, *content_area,*parent;
	parent =(GtkWidget *)gtk_builder_get_object(build,"window_baptism");
   /* Create the widgets */
  	 dialog = gtk_dialog_new_with_buttons ("Message",
					 parent,
                                         GTK_DIALOG_MODAL,
                                         GTK_STOCK_OK,
                                         GTK_RESPONSE_OK,
                                         NULL);
   	content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
   	label = gtk_label_new (message);
   	/* Ensure that the dialog box is destroyed when the user responds. */
   	g_signal_connect_swapped (dialog,"response",G_CALLBACK (gtk_widget_destroy),dialog);
   	/* Add the label, and show everything we've added to the dialog. */
   	gtk_container_add (GTK_CONTAINER (content_area), label);
  	gtk_widget_show_all (dialog);
}
