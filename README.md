# Hướng dẫn điều khiển thiết bị qua WebServer
---
1. giải thích `webserver.ino`.

- `// #define STA_MODE` dùng để định nghĩa sữ dụng chế độ nào của ESP8266. Nếu dùng ở chế độ lấy ESP8266 kết nối vào mạng WiFi thì bỏ dấu `//`.

- `WiFi.mode(WIFI_STA);` chọn mode kết nối vào mạng wifi nhà.

- `WiFi.begin(ssid, password);` kết nối vào wifi.

- `WiFi.mode(WIFI_AP);` chọn mode phát wifi.
- `server.on("/", handleRoot);` bắt đường dẫn `/` trả về `handleRoot`

- `server.send(200, "text/html", s1); ` gửi định dạng `text/html` tới client.

- `server.begin();` bắt đầu chạy server.

- `server.handleClient();` thực thi yêu cầu của client.

- `if (server.argName(i) == "LED1")` kiểm tra tham số trả về có bằng `LED` hay không.



2. giải thích `pageControl.h`.
- khai báo `PROGMEM` để lưu trữ trong bộ nhớ flash thay vì SRAM.
- `<form menthod='get'><input class='button' type='submit' name='LED1' value='ON' ></form>` tạo nút nhấn với `name='LED1'` và value='ON'.

- `name`và `value` là 2 tham số được dùng trong quá trình gửi nhận dữ liệu giữa người dùng thao tác trên trình duyệt Web và ESP8266.
---
