 # uchat
 
 ### Description:
 Ucode project: develop uchat in one month. 
 ### Developers:
 [Tetiana Rohalska](https://github.com/trohalska): Server
 
 [Anton Balabin](https://github.com/MansTomb): Client
 
 [Oleksandr Afanasiev](https://github.com/wizaral): SQL database
 
 [Yurii Burienkov](https://github.com/ronald112): JSON
 
 Violetta Poliakova: Graphic part, presentation
 
 ### Usage:
 ```
 1. make
 2 ./ucat_server [port]
 3 ./uchat [ip] [port]
 ```
 ### Implemented:
 ```
 Simple chat.
 Server works on multiplexing technology - using function select.
 On server all messages are saving in database (SQLite).
 File transferring works.
 Client was written with GTK/Glade.
 Data transport - json structures.
 Data security - password hash only.
 ```
 ### Features:
 ```
 - able to change password;
 - using newline in messages;
 - adaptive UX/UI;
 - authorization notification;
 - reconnect to server;
 - administration app (login - root, password - root);
 - display of active users in real time;
 - ServerBot (input "/help" to look for command).
 ```
