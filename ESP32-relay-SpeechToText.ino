#include <WiFi.h>
#include <HTTPClient.h>

// Relay pin configuration
const int relayPin = 5;  // GPIO pin connected to relay IN

// State tracking
String latestCommand = "";
unsigned long lastRequestTime = 0;
const unsigned long requestInterval = 1000; // Interval for HTTP requests in milliseconds (1 second)

void setup() {
  Serial.begin(115200);

  // Initialize relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Ensure relay is off initially (active-low relay)

  // Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin("SSID", "PASSWORD"); // Replace with actual SSID and password

  int attempts = 0;
  const int maxAttempts = 20;

  while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to WiFi");
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if the request interval has passed
  if (currentMillis - lastRequestTime >= requestInterval) {
    lastRequestTime = currentMillis;

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin("http://your-server-address/RobotProj1/speech_to_text.php"); // Update with your server address and script if needed

      int httpCode = http.GET();
      String payload;

      if (httpCode == HTTP_CODE_OK) {
        payload = http.getString();
        payload.trim();  // Remove any extra whitespace
        Serial.println("Payload: " + payload);

        // Update LED state based on the command
        if (payload == "1") {  // Command is "open"
          if (latestCommand != "open") {
            Serial.println("Turning ON relay");
            digitalWrite(relayPin, HIGH);  // Relay is active-low
            latestCommand = "open";
          }
        } else if (payload == "0") {  // Command is "close"
          if (latestCommand != "close") {
            Serial.println("Turning OFF relay");
            digitalWrite(relayPin, LOW); // Relay is active-low
            latestCommand = "close";
          }
        } else {
          Serial.println("Unexpected payload: " + payload);
        }
      } else {
        Serial.println("HTTP request failed with code: " + String(httpCode));
      }

      http.end();
    } else {
      Serial.println("Disconnected from WiFi");
    }
  }

  delay(100);  // Short delay to prevent excessive request rate
}
