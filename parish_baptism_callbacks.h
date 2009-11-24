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

# include "database.h"
# include "parish_common.h"
/*callbacks related to (window_baptism) baptism certificate entry*/
void on_window_baptism_quit_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_clear_clicked(GtkButton *button,gpointer user_data);
void on_window_baptism_add_clicked(GtkButton *button,gpointer user_data);

void on_window_baptism_remarks_insert_text(GtkEditable  *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_kept_at_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_place_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_dad_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_mom_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_sp2_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_sp1_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_priest_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_resi_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_window_baptism_caste_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);


/*void on_window_baptism_dob_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
  void on_window_baptism_date_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
gboolean on_window_baptism_dob_focus_out_event(GtkWidget *widget,GdkEventFocus *event,gpointer user_data);
gboolean on_window_baptism_date_focus_out_event(GtkWidget *widget,GdkEventFocus *event,gpointer user_data);*/

/*utility functions*/

void add_text_window_baptism_sex();

