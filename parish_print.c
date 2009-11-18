#include "parish_print.h"


/* Print the textbuffer with a font of "Monospace 10". */

void print_buffer (gchar *text)
{
  GtkPrintOperation *operation;
  GError *error = NULL;
  gint res; 
  PrintData *data;
  data = g_slice_new(PrintData);
  data->str = g_string_new("");
  g_string_append_printf(data->str,"%s",text);
  /* Create a new print operation, applying saved print settings if they exist. */
  operation = gtk_print_operation_new ();
  if (settings != NULL)
    gtk_print_operation_set_print_settings (operation, settings);
  
  data->font_size = 10.0;

  g_signal_connect (G_OBJECT (operation), "begin_print", G_CALLBACK (begin_print),(gpointer) data);
  g_signal_connect (G_OBJECT (operation), "draw_page", G_CALLBACK (draw_page),(gpointer) data);
  g_signal_connect (G_OBJECT (operation), "end_print", G_CALLBACK (end_print),(gpointer) data);

  /* Run the default print operation that will print the selected file. */
  res = gtk_print_operation_run (operation, GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG, 
                                 GTK_WINDOW (gtk_builder_get_object(build,"search_results")), &error);

  /* If the print operation was accepted, save the new print settings. */
  if (res == GTK_PRINT_OPERATION_RESULT_APPLY)
  {
    if (settings != NULL)
      g_object_unref (settings);
    settings = g_object_ref (gtk_print_operation_get_print_settings (operation));
  }
  /* Otherwise, report that the print operation has failed. */
  else if (error)
  {
    quick_message("Print operation was failed!");
    
    g_error_free (error);   
  }
  
  g_object_unref (operation);
}

/* Begin the printing by retrieving the contents of the selected files and
 * spliting it into single lines of text. */
static void
begin_print (GtkPrintOperation *operation, 
             GtkPrintContext *context,
             PrintData *w)
{
  gdouble height;
  //gsize length;

  /* Retrieve the file contents and split it into lines of text. */
  w->lines = g_strsplit (w->str->str, "\n", 0);

  /* Count the total number of lines in the file. */
  w->total_lines = 0;
  while (w->lines[w->total_lines] != NULL)
    w->total_lines++;
  
  /* Based on the height of the page and font size, calculate how many lines can be 
   * rendered on a single page. A padding of 3 is placed between lines as well. */
  height = gtk_print_context_get_height (context) - HEADER_HEIGHT - HEADER_GAP;
  w->lines_per_page = floor (height / (w->font_size + 3));
  w->total_pages = (w->total_lines - 1) / w->lines_per_page + 1;
  gtk_print_operation_set_n_pages (operation, w->total_pages);
}

/* Draw the page, which includes a header with the file name and page number along
 * with one page of text with a font of "Monospace 10". */
static void
draw_page (GtkPrintOperation *operation,
           GtkPrintContext *context,
           gint page_nr,
           PrintData *w)
{
  cairo_t *cr;
  PangoLayout *layout;
  gdouble width, text_height;
  gint line, i, text_width, layout_height;
  PangoFontDescription *desc;
  gchar *page_str;

  cr = gtk_print_context_get_cairo_context (context);
  width = gtk_print_context_get_width (context);
  layout = gtk_print_context_create_pango_layout (context);
  desc = pango_font_description_from_string ("Monospace");
  pango_font_description_set_size (desc, w->font_size * PANGO_SCALE);

  /* Render the page header with the filename and page number. */
  pango_layout_set_font_description (layout, desc);
  pango_layout_set_text (layout, "Certificate", -1);
  pango_layout_set_width (layout, -1);
  pango_layout_set_alignment (layout, PANGO_ALIGN_LEFT);
  pango_layout_get_size (layout, NULL, &layout_height);
  text_height = (gdouble) layout_height / PANGO_SCALE;

  cairo_move_to (cr, 0, (HEADER_HEIGHT - text_height) / 2);
  pango_cairo_show_layout (cr, layout);

  page_str = g_strdup_printf ("%d of %d", page_nr + 1, w->total_pages);
  pango_layout_set_text (layout, page_str, -1);
  pango_layout_get_size (layout, &text_width, NULL);
  pango_layout_set_alignment (layout, PANGO_ALIGN_RIGHT);

  cairo_move_to (cr, width - (text_width / PANGO_SCALE), 
                 (HEADER_HEIGHT - text_height) / 2);
  pango_cairo_show_layout (cr, layout);
  
  /* Render the page text with the specified font and size. */  
  cairo_move_to (cr, 0, HEADER_HEIGHT + HEADER_GAP);
  line = page_nr * w->lines_per_page;
  for (i = 0; i < w->lines_per_page && line < w->total_lines; i++) 
  {
    pango_layout_set_text (layout, w->lines[line], -1);
    pango_cairo_show_layout (cr, layout);
    cairo_rel_move_to (cr, 0, w->font_size + 3);
    line++;
  }

  g_free (page_str);
  g_object_unref (layout);
  pango_font_description_free (desc);
}

/* Clean up after the printing operation since it is done. */
static void
end_print (GtkPrintOperation *operation, 
           GtkPrintContext *context,
           PrintData *w)
{
  g_strfreev (w->lines);
  g_string_free(w->str,FALSE);
  g_slice_free1 (sizeof (PrintData), w);
  w = NULL;
}
