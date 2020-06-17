#include "client.h"

void mx_on_click_create_room_channel(GtkWidget *widget, gpointer data) {
    t_info *info = data;
    t_room_creation *dialog = info->windows->room_creation;

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dialog->groupbt), FALSE);
}

void mx_on_click_create_room_group(GtkWidget *widget, gpointer data) {
    t_info *info = data;
    t_room_creation *dialog = info->windows->room_creation;

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dialog->channelbt), FALSE);
}

void mx_on_click_create_room_create(GtkWidget *widget, gpointer data) {
    t_info *info = data;
    t_room_creation *dialog = info->windows->room_creation;

    
    if (mx_room_creation_data_validation(dialog)) {
        // action "mx_make_new_chat" estimated return "mx_make_new_chat_success"(TODO)
        mx_room_creation_destructor(info);
    }
}

void mx_on_click_create_room_cancel(GtkWidget *widget, gpointer data) {
    t_info *info = data;
    t_room_creation *dialog = info->windows->room_creation;

    mx_room_creation_destructor(info);
}
