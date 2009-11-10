#include "parish_search_main.h"
void on_search_main_cancel_button_clicked(GtkButton *button,gpointer user_data)
{
  GtkWidget *widget;
  widget = (GtkWidget *) gtk_builder_get_object(build,"search_main");
  gtk_widget_hide(widget);

}
