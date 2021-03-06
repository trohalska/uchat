#include "client.h"

void mx_on_click_register(GtkWidget *widget, gpointer data) {
    t_info *info = data;

    mx_login_screen_destroy(info);
    mx_register_screen_build(info, info->windows->reg);
}

void mx_on_click_login(GtkWidget *widget, gpointer user_data) {
    t_info *info = (t_info *)user_data;
    t_login *log = info->windows->log;

    if (mx_login_data_validate(log)) {
        mx_login_build_json_wrapper(info);
        mx_wait_for_json(info, success_authorization, failed_authorization);
        if (mx_get_jtype(info, success_authorization)) {
            mx_save_login_data(info);
            mx_login_screen_destroy(info);
            if (info->cl_data->profile->id == 1)
                mx_admin_screen_build(info, info->windows->adm);
            else
                mx_main_screen_build(info, info->windows->ms);
        }
        else if (mx_get_jtype(info, failed_authorization))
            mx_dialog_warning_create(NULL, "Invalid login or password!");
    }
}
