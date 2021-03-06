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

#include "database.h"
void on_search_main_cancel_button_clicked(GtkButton *widget,gpointer user_data);
void on_search_main_query_insert_text(GtkEditable *editable,gchar *new_text,gint new_text_length,gint *position,gpointer user_data);
void on_search_main_search_button_clicked(GtkButton *button,gpointer user_data);
gboolean is_valid_search(gchar *querystring,int *cbox_index,int *index);
void on_search_main_radio2_clicked(GtkButton *button,gpointer user_data);
void on_search_main_radio1_clicked(GtkButton *button,gpointer user_data);
