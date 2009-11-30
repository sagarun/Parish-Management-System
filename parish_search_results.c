#include "parish_search_results.h"

void on_search_results_close_clicked(GtkButton *button,gpointer user_data)
{
  GtkWidget *widget;
  sqlite3_reset(stmt);
  widget = (GtkWidget *)gtk_builder_get_object(build,"search_results");
  gtk_widget_hide(widget);

}

void on_search_results_next_clicked(GtkButton *button,gpointer user_data)
{
  int cols;
  GtkWidget *view;
  GtkTextBuffer *textbuf;
  GString *result;
  result = g_string_new("");
  cols = sqlite3_column_count(stmt);
  prepare_results(result,cols,1);
  view = (GtkWidget *)gtk_builder_get_object(build,"search_results_text");
  textbuf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
  gtk_text_buffer_set_text(textbuf,result->str,-1);

}

void on_search_results_print_clicked(GtkButton *button,gpointer user_data)
{
  GtkTextBuffer *buffer;
  GtkTextIter start,end;
  GtkWidget *widget;
  widget = (GtkWidget *) gtk_builder_get_object(build,"search_results_text");
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (widget));
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer),&start);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer),&end);
  g_print("getting buffer: %s",gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer),&start,&end,TRUE));

    print_buffer(gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer),&start,&end,TRUE));

}
