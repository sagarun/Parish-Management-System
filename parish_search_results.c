#include "parish_search_results.h"

void on_search_results_close_clicked(GtkButton *button,gpointer user_data)
{
  GtkWidget *widget;
  widget = (GtkWidget *)gtk_builder_get_object(build,"search_results");
  gtk_widget_hide(widget);

}

void on_search_results_next_clicked(GtkButton *button,gpointer user_data)
{
  int cols;
  GtkWidget *widget,*view;
  GtkTextBuffer *textbuf;
  GString *result;
  result = g_string_new("");
  cols = sqlite3_column_count(stmt);
  prepare_results(result,cols);
  view = (GtkWidget *)gtk_builder_get_object(build,"search_results_text");
  textbuf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
  gtk_text_buffer_set_text(textbuf,result->str,-1);

}
