
# Проект NG-Live 

<p>
<strong>NG-Live</strong> - Аналог соц-сети
по типу telegram или instagram. С возможностью AnyDesk 
(контроль пк на которых установлен cпециальный клиент)
</p>


## Стеки

- **Frontend-client**
    - React (vite)
        - TypeScript
        - WebRTC 
        - Axios  
        - Socket.io 
        - Redux Toolkit 
        ... 

- **Main-server**
    - Java 
        - Vert.x
            - vertx-sql-client
            - vertx-pg-client
            - vertx-mongo-client
            - vertx-redis-client
            - vertx-web-auth-jwt
            - vertx-web-graphql
            ... 
             
- **Database**
    - PostgreSQL
    - Redis
    - MongoDB 


- **Desk-control-app**
    - C++
        - CMake
        - uWebSockets
        - GLFW 
        ... 




## Структура 

<pre>
<code>

desk-control-app/ <-- Невидимый клиент для контроля пк 
    ... 


main-server/ <-- Backend 
    ...


webapp-client/ <-- Frontend 
    ... 

</code> 
</pre>




