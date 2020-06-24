#include "server.h"

static int check_err_json(cJSON *new) {
    const char *error_ptr;

    if (new == NULL)
        if ((error_ptr = cJSON_GetErrorPtr()) != NULL) {
            fprintf(stderr, "cJSON_Parse error, before: %s", error_ptr);
            return 1;
        }
    return 0;
}

void mx_message_handler(t_info *info, t_peer *peer) {
    cJSON *get;
    int type;

    get = cJSON_Parse(peer->receiving_buffer);
    if (check_err_json(get))
        return;

    type = MX_TYPE(get);

    mx_response_db(info, peer, type, get);
    // cJSON_Delete(get);
}

void mx_response_db(t_info *info, t_peer *peer, int type, cJSON *get) {

    switch (type) {
    case make_register:  //fallthrough
        mx_db_registration(info, peer, type, get);
        // + дописать его в канал general или нет ???
        break;
    case make_authorization:
        mx_db_authorization(info, peer, type, get);
        // + подгрузка истории
        break;
    case make_deletion:
        mx_db_delete(info, peer, type, get);
        break;
    case make_change_password:
        mx_db_change_password(info, peer, type, get);
        break;
    case get_client_contacts:
        mx_db_get_client_contacts(info, peer, type, get);
        break;
    case make_update_profile:
        mx_db_update_profile(info, peer, type, get);
        break;
    case make_add_new_contact:
        mx_db_add_new_contact(info, peer, type, get);
        break;
    case make_del_contact:
        mx_db_del_contact(info, peer, type, get);
        break;
    case make_new_personal_chat:
        mx_db_create_personal_chat(info, peer, type, get);
        break;
    case send_message:
        mx_db_send_message(info, peer, type, get);
        break;
    case logout:
        peer->uid = MX_NO_PEER;
        mx_json_to_sending_buffer(peer, get);
        mx_print_serv_out(get, peer->sending_buffer);
        break;
    default:
        printf("unknown type of message\n");
        break;
    }
}
