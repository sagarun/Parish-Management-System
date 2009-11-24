#include "parish_common.h"
#define HEADER_HEIGHT 50.0
#define HEADER_GAP 17

/* A structure that will hold information about the current print job. */
typedef struct
{
  gdouble font_size;
  gint lines_per_page;  
  gchar **lines;
  GString *str;
  gint total_lines;
  gint total_pages;
} PrintData;

GtkPrintSettings *settings;

void print_buffer(gchar *);
void begin_print (GtkPrintOperation*, GtkPrintContext*, PrintData*);
void draw_page (GtkPrintOperation*, GtkPrintContext*, gint, PrintData*);
void end_print (GtkPrintOperation*, GtkPrintContext*, PrintData*);
