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

#ifndef PARISH_MAIN
#define PARISH_MAIN
#include "parish_baptism_callbacks.h"
#include "parish_search_main.h"
/*callbacks related to main window */
void on_window_button_search_clicked(GtkButton *button,gpointer user_data);
void on_window_button_baptism_clicked(GtkButton *button,gpointer user_data);
void on_window_button_marriage_clicked(GtkButton *button,gpointer user_data);
#endif
