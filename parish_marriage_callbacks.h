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
#include "database.h"

typedef struct
{
  gchar *marriage_date;
  gchar *marriage_month;
  gchar *marriage_year;
  gchar *bride_name;
  gchar *groom_name;
  gchar *bride_dob_date;
  gchar *bride_dob_month;
  gchar *bride_dob_year;
  gchar *groom_dob_date;
  gchar *groom_dob_month;
  gchar *groom_dob_year;
  gchar *bride_cond;
  gchar *groom_cond;
  gchar *bride_rank;
  gchar *groom_rank;
  gchar *bride_father;
  gchar *groom_father;
  gchar *bride_addr;
  gchar *groom_addr;
  gchar *bride_wit;
  gchar *groom_wit;
  gchar *bride_wit_addr;
  gchar *groom_wit_addr;
  gchar *minister;

}marriage_cert;

void on_window_marriage_close_clicked(GtkButton *button,gpointer user_data);
void on_window_marriage_clear_clicked(GtkButton *button,gpointer user_data);

void clear_marriage_records();

void on_window_marriage_bride_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_cond_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_cond_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_rank_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);

void on_window_marriage_groom_rank_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_father_insert_text(GtkEditable *editable,gchar *new_textr,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_father_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_address_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_address_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_wit_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_wit_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_wit_addr_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_wit_addr_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_minister_name_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
