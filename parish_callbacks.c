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
  retval = sqlite_store_baptism_cert();
  g_print("Return value after insert query: %d",retval);

}

