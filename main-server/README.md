# MainServer - backend часть для NG-Live

## Сервисы
<pre> 
<code>

main-server/
    common/ <-- Обший сервис для модулей настроке конфигов
    
    service-chat/ <-- Сервис для чатов (группы,сообщения)

    service-desk-control/ <-- Функция для контроля пк через с++ клиент (real-time)

    service-gateway/ <-- Общий сервис для распредления запросов 

    service-notifications/ <-- Сервис для уведомлений

    service-user/ <-- Сервис для аутентификации и хранения,контроля пользователей

    service-webrtc/ <-- Сервис для видео/аудио звонков
    

</code>
</pre>


## Зависимости
- `vertx`: Основной модуль. Быстрый ассинхроный event-loop сервер


