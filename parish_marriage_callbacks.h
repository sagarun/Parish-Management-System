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
#ifndef PARISH_MARRIAGE_CALLBACKS
#define PARISH_MARRIAGE_CALLBACKS
#include "parish_common.h"
#include "database.h"



void on_window_marriage_close_clicked(GtkButton *button,gpointer user_data);
void on_window_marriage_clear_clicked(GtkButton *button,gpointer user_data);
void on_window_marriage_add_clicked(GtkButton *button,gpointer user_data);

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
void on_window_marriage_bride_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_wit_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_wit_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_wit_villi_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_wit_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_wit_dist_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_bride_wit_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);
void on_window_marriage_groom_wit_pin_insert_text(GtkEditable *editable,gchar *new_text,gint new_length,gint *position,gpointer user_data);


void get_marriage_cert(marriage_cert *cert);
gboolean is_marriage_cert_valid(marriage_cert cert);
#endif
