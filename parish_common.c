/*Implements functions which are common to all forms in the application*/
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

#include "parish_common.h"
/*Utility functions*/
/*Checks form is empty or not*/
gboolean is_form_valid(struct baptism_cert *cert)
{
  if(g_strcmp0(cert->kept_at,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->place,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dobap_date,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dobap_month,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dobap_year,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->name,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dob_date,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dob_month,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dob_year,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->mom,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->dad,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->resi,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->caste,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->spon1,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->spon2,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->priest,"")==0)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->remarks,"")==0)
    {
      return FALSE;
    }
  return TRUE;
  
}

/*Displays a Message box*/
void quick_message (gchar *message) 
{
   	GtkWidget *dialog, *label, *content_area,*parent;
	parent =(GtkWidget *)gtk_builder_get_object(build,"window");
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


/*Adds text from liststores  to combo box's in the application*/
void add_text_combobox()
{
	GtkCellRenderer *cell;
	GtkComboBox *cbox;
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_sex"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_dob_date"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_dob_month"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_dob_year"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_dobap_date"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_dobap_month"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"window_baptism_dobap_year"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
	cbox = (GtkComboBox *)(gtk_builder_get_object(build,"search_main_searchby_combobox"));
	cell = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(cbox),cell,TRUE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(cbox),cell,"text",0);
}

/*Prepates date information to store it in db*/
void baptism_prepare_date(struct baptism_cert cert,gchar *date_dob,gchar *date_dobap)
{
  g_strlcpy(date_dob,cert.dob_date,10);
  g_print(cert.dob_date);
  g_strlcat(date_dob,"/",10);
  g_strlcat(date_dob,cert.dob_month,10);
  g_strlcat(date_dob,"/",10);
  g_strlcat(date_dob,cert.dob_year,10);
  g_strlcpy(date_dobap,cert.dobap_date,10);
  g_strlcat(date_dobap,"/",10);
  g_strlcat(date_dobap,cert.dobap_month,10);
  g_strlcat(date_dobap,"/",10);
  g_strlcat(date_dobap,cert.dobap_year,10);

}
