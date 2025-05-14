#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Configuración WiFi
const char* ssid = "HackerspaceX";
const char* password = "Nohaypass";

// Configuración MQTT
const char* mqtt_server = "broker.hivemq.com";  // Puedes usar otro broker si deseas
const int mqtt_port = 1883;
const char* mqtt_topic = "esp8266/dht22";

// Configuración del DHT22
#define DHTPIN D2          // Pin al que está conectado el DHT22
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Objetos WiFi y MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Función para conectar al WiFi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

// Función para conectar al broker MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando al broker MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("conectado");
    } else {
      Serial.print("falló, rc=");
      Serial.print(client.state());
      Serial.println(" intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leer datos del DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Fallo al leer del sensor DHT22");
    return;
  }

  // Crear el mensaje JSON
  String payload = "{\"temperatura\": ";
  payload += String(t);
  payload += ", \"humedad\": ";
  payload += String(h);
  payload += "}";

  // Enviar al broker MQTT
  client.publish(mqtt_topic, payload.c_str());
  Serial.println("Datos enviados: " + payload);

  // Esperar 10 segundos
  delay(10000);
}
