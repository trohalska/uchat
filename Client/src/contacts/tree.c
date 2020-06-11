#include "client.h"


static GtkTreeViewColumn *create_column(char *title, gint col) {
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column = gtk_tree_view_column_new();

    gtk_tree_view_column_set_title(column, title);
    gtk_tree_view_column_pack_start(column, renderer, true);
    gtk_tree_view_column_add_attribute(column, renderer, "text", col);

    return column;
}

GtkWidget *mx_contacts_tree_constructor(t_info *info) {
    GtkWidget *new;

    // gtk_tree_store_append(list_store, &iter, NULL);
    // gtk_tree_store_append(list_store, &iter, NULL);
    // new->treemodel = gtk_tree_model_
    new = gtk_tree_view_new();

    gtk_widget_set_size_request(new, 880, 520);

    gtk_tree_view_append_column(GTK_TREE_VIEW(new), create_column("ID", 0));
    gtk_tree_view_append_column(GTK_TREE_VIEW(new), create_column("Name", 1));
    return new;
    if (info) {};
}
