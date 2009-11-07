#include "parish_common.h"
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
