# Webserver
Simple server like nginx as a team with jkassand and mgracefo.

This team project is about writing our own HTTP server.
HTTP is one of the most used protocols on the internet.
We test it with a few actual browsers.

We write a HTTP server in C++ 98. 
Executable run as follows:
1) Make
2) ./webserv default.conf

• A request to our server never hang forever.

• Server is compatible with Safari and Google Chrome browsers.

• We have HTTP response status codes.

• The Server have default error pages.

• We use fork for multi CGI's (Python, Bash and Java Script).

• We can serve a fully static website.

• Our clients can upload files.

• We have GET, POST, and DELETE methods.

• We made stress tests to our server (siege). It stay available at all cost.

• The Server is able to listen to multiple ports (see Configuration file).

• We support autoindex (see Configuration file).

• We have cookies (try changing the background color of the home page).

<img width="1168" alt="screen" src="https://user-images.githubusercontent.com/61458847/160602542-fe2b522c-b954-46ac-8baa-ca98d1984518.png">
<img width="1258" alt="server1" src="https://user-images.githubusercontent.com/61458847/160599993-b2c178ea-78e2-45d6-a046-6b06343fe9ed.png">
<img width="1245" alt="server2" src="https://user-images.githubusercontent.com/61458847/160600032-aab3ef03-2353-4fa5-9341-1bd937f922cc.png">
<img width="1275" alt="server3" src="https://user-images.githubusercontent.com/61458847/160600035-5d8c2a7d-553d-47b1-8df4-53a682698c76.png">
<img width="1224" alt="server4" src="https://user-images.githubusercontent.com/61458847/160600036-042a9aa8-7624-4587-bc80-b5c3365fa636.png">
<img width="1240" alt="server5" src="https://user-images.githubusercontent.com/61458847/160600038-8ce07f41-5004-4c81-84f8-bb4e7775ec59.png">
<img width="1267" alt="server6" src="https://user-images.githubusercontent.com/61458847/160600040-b25c112e-ece3-4e79-8706-2e9f9d2b827a.png">
