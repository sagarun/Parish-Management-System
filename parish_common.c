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
  else if(cert->dobap_date == NULL)
    {
      return FALSE;
    }
  else if(cert->dobap_month== NULL)
    {
      return FALSE;
    }
  else if(cert->dobap_year == NULL)
    {
      return FALSE;
    }
  else if(g_strcmp0(cert->name,"")==0)
    {
      return FALSE;
    }
  else if(cert->dob_date == NULL)
    {
      return FALSE;
    }
  else if(cert->dob_month == NULL)
    {
      return FALSE;
    }
  else if(cert->dob_year == NULL)
    {
      return FALSE;
    }
  else if(cert->sex == NULL)
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
  else
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

/* Creates displayable search results*/
void prepare_results(GString *result,int cols)
{
  int retval,i;
  retval = sqlite3_step(stmt);
  gchar col_name[25];
  gchar col_name_db[25];
  if(retval == SQLITE_ROW)
    {
      //g_string_append_printf(result,"%s","*******************************************");
      //g_string_append_printf(result,"%s\n","*******************************************");

      /* i starts from 1 as uid is in first column of the table*/
      for(i=1;i<cols;i++)
	{
	  g_strlcpy(col_name_db,sqlite3_column_name(stmt,i),25);
	  g_string_append_printf(result,"\n%s","------------------------------------------");
	  g_string_append_printf(result,"%s","------------------------------------------");
	  get_column_name(i,col_name);  
	  g_string_append_printf(result,"\n\t\t\t%s",col_name);
	  g_string_append_printf(result,"\t\t\t%s","");
	  g_string_append_printf(result,"%s",(gchar *)sqlite3_column_text(stmt,i));

	}
      //g_string_append_printf(result,"\n%s","*******************************************");
      //g_string_append_printf(result,"%s\n","*******************************************");

    }
  else
    {
      g_string_append_printf(result,"%s","End of search");
    }
}


/* Creates printable column name*/
void get_column_name(int i,gchar *col_name)
{
  
  switch(i)
    {	    
     case 1:  
              g_strlcpy(col_name,"Kept At      ",25);
              break;
     case 2:
	      g_strlcpy(col_name,"Place        ",25);
	      break;
     case 3:
	      g_strlcpy(col_name,"Date         ",25);
	      break;
     case 4: 
	      g_strlcpy(col_name,"Name         ",25);
	      break;
     case 5:
	      g_strlcpy(col_name,"Date of birth",25);
	      break;
     case 6:
	      g_strlcpy(col_name,"Sex          ",25);
	      break;
     case 7:
	      g_strlcpy(col_name,"Mother's Name",25);
	      break;
     case 8:
	      g_strlcpy(col_name,"Father's Name",25);
	      break;
     case 9:
	      g_strlcpy(col_name,"Residence    ",25);
	      break;
     case 10:
	      g_strlcpy(col_name,"Caste        ",25);
	      break;
     case 11:
	      g_strlcpy(col_name,"Sponsor 1    ",25);
	      break;
     case 12:
	      g_strlcpy(col_name,"Sponsor 2    ",25);
	      break;
     case 13:
	      g_strlcpy(col_name,"Priest       ",25);
	      break;
     case 14:
	      g_strlcpy(col_name,"Remarks      ",25);
	      break;
    }
}
