#include "client.h"

GtkWidget *mx_entry_constructor(char *name) {
    GtkWidget *new = gtk_entry_new();
    GtkStyleContext *context = gtk_widget_get_style_context(new);

    gtk_style_context_add_class(context, name);
    gtk_widget_set_name(new, name);
    gtk_entry_set_max_length(GTK_ENTRY(new), 16);
    
    return new;
}

bool mx_entry_text_exist(GtkWidget *entry) {
    if (gtk_entry_get_text_length(GTK_ENTRY(entry)))
        return true;
    return false;
}

char *mx_entry_get_text(GtkWidget *entry) {
    return (char *)gtk_entry_get_text(GTK_ENTRY(entry));
}
