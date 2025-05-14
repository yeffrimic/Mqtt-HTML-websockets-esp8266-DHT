# 🌡️🌸 Ejemplo de Sensores con ESP8266 y HTML por Yeffrimic

Este proyecto utiliza un **ESP8266** y un **sensor DHT22** para medir la **temperatura y la humedad** del ambiente, enviando los datos a un **broker MQTT público** (`broker.hivemq.com`). Luego, una página **HTML interactiva y kawaii** recibe y muestra estos datos en tiempo real.

---

## 📦 Requisitos

### Hardware
- ESP8266 (NodeMCU o similar)
- Sensor DHT22
- Resistencia de 10kΩ entre DATA y VCC

### Software
- Arduino IDE
- Librerías necesarias:
  - `DHT sensor library by Adafruit`
  - `PubSubClient`
  - `ESP8266WiFi`

---

## 📡 Funcionamiento

1. El **ESP8266** se conecta al WiFi.
2. Lee temperatura y humedad desde el **DHT22** cada 10 segundos.
3. Envía los datos como JSON al broker MQTT en el **topic `esp8266/dht22`**.
4. Una página **HTML** se conecta al broker MQTT por WebSocket y muestra los datos en vivo con íconos kawaii 🌡️ y 💧.

---

## 📁 Archivos

- `esp8266_dht22_mqtt.ino`: Código Arduino para el ESP8266.
- `index.html`: Página web que muestra los datos en tiempo real con MQTT.
- `README.md`: Este archivo 😉

---

## 🔌 Conexiones

| DHT22 Pin | ESP8266 (NodeMCU) |
|-----------|-------------------|
| VCC       | 3.3V              |
| DATA      | D2 (GPIO4)        |
| GND       | GND               |

**🔸 Importante:** Añade una resistencia de **10kΩ** entre **VCC** y **DATA**.

---

## 🌐 Vista HTML

<p align="center">
  <img src="https://raw.githubusercontent.com/tuusuario/tu-repo/main/demo.png" width="400" alt="Ejemplo de sensores kawaii">
</p>

---

## 🧪 Prueba en el navegador

1. Abre el archivo `index.html` en tu navegador.
2. Espera a que el ESP8266 publique datos.
3. Verás la temperatura y humedad actualizadas cada 10 segundos.

---

## 🔐 Broker MQTT

- Broker: `broker.hivemq.com`
- Puerto: `1883` (ESP8266) / `8884` (WebSocket seguro)
- Topic: `esp8266/dht22`

Puedes probarlo también con [HiveMQ Web MQTT Client](https://www.hivemq.com/demos/websocket-client/)

---

## ✨ Autor

Desarrollado con cariño por **Yeffrimic 💻🌸**  
[GitHub](https://github.com/yeffrimic)

---

## 📝 Licencia

Este proyecto está bajo la licencia MIT. Puedes usarlo y modificarlo libremente. ¡No olvides dar crédito!
