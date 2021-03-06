#include "server.h"

static int callback(void *data, int argc, char **argv, char **cols) {
    cJSON *contact = cJSON_CreateObject();
    int uid = atoi(argv[0]);

    if (uid != MX_VINT(data, "uid")) {
        cJSON_AddNumberToObject(contact, "uid", uid);
        cJSON_AddStringToObject(contact, "login", argv[1]);
        cJSON_AddItemToArray(cJSON_GetObjectItem(data, "users"), contact);
    }
    return 0;
}

cJSON *mx_search_user(sqlite3 *db, cJSON *jsn) {
    char *query = NULL;
    char *err = NULL;
    int rc = 0;

    asprintf(&query, "SELECT id, login FROM users;");
    cJSON_AddArrayToObject(jsn, "users");
    rc = sqlite3_exec(db, query, callback, jsn, &err);

    if (mx_check(rc, err, "find user login") != SQLITE_OK) {
        MX_SET_TYPE(jsn, failed_search_user);
    }
    else {
        MX_SET_TYPE(jsn, success_search_user);
    }
    free(query);
    return jsn;
}
