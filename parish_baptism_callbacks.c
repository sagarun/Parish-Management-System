#include "parish_baptism_callbacks.h"



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
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dobap_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dobap_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dobap_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_name");
	gtk_entry_set_text(GTK_ENTRY(entry),"");
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dob_date");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dob_month");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dob_year");
	gtk_combo_box_set_active((GtkComboBox *)(cbox),-1);
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

void get_baptism_cert(struct baptism_cert *cert)
{
	GtkWidget *entry;
	GtkWidget *cbox;
	gchar dob[10];
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_kept_at");
	cert->kept_at = gtk_entry_get_text(GTK_ENTRY (entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_place");
	cert->place = gtk_entry_get_text(GTK_ENTRY (entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_name");
	cert->name = gtk_entry_get_text(GTK_ENTRY(entry));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dob_date");
	cert->dob_date = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dob_month");
	cert->dob_month = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dob_year");
	cert->dob_year = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));	
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dobap_date");
	cert->dobap_date = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dobap_month");
	cert->dobap_month = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_dobap_year");
	cert->dobap_year = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	cbox = (GtkComboBox *)gtk_builder_get_object(build,"window_baptism_sex");
	cert->sex = gtk_combo_box_get_active_text((GtkComboBox *)(cbox));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_mom");
	cert->mom = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_dad");
	cert->dad = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_resi");
	cert->resi = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_caste");
	cert->caste  = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp1");
	cert->spon1 = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_sp2");
	cert->spon2 = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_priest");
        cert->priest = gtk_entry_get_text(GTK_ENTRY(entry));
	entry = (GtkWidget *)gtk_builder_get_object(build,"window_baptism_remarks");
	cert->remarks = gtk_entry_get_text(GTK_ENTRY(entry));

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
*/
