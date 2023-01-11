//muj kod
#include <FS.h>
#include <WiFiManager.h>


#ifdef ESP32
  #include <SPIFFS.h>
#endif



#include <ArduinoJson.h>
// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

// ESP32 #include <WiFi.h>
// ESP32 #include <SPIFFS.h>


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------


// Captive portal for configuring the WiFi

// Can be installed from the library manager (Search for "WifiManager", install the Alhpa version)
// https://github.com/tzapu/WiFiManager

#include <ESP_DoubleResetDetector.h>
// A library for checking if the reset button has been pressed twice
// Can be used to enable config mode
// Can be installed from the library manager (Search for "ESP_DoubleResetDetector")
//https://github.com/khoih-prog/ESP_DoubleResetDetector

#
// ArduinoJson is used for parsing and creating the config file.
// Search for "Arduino Json" in the Arduino Library manager
// https://github.com/bblanchon/ArduinoJson

#include "SSD1306Wire.h"  // legacy: #include "SSD1306.h"

/*
knihovna pro displej
https://github.com/ThingPulse/esp8266-oled-ssd1306
*/

// -------------------------------------
// -------   Other Config   ------
// -------------------------------------


#define JSON_CONFIG_FILE "/sample_config.json"

// Number of seconds after reset during which a
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 5 
// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

// -----------------------------

// -----------------------------

DoubleResetDetector *drd;

//flag for saving data
bool shouldSaveConfig = false;

const int vyska32 = 0;

char klic[350]="XXX"; //golemio api klic

//SSD1306Wire display(0x3c, D3, D4, GEOMETRY_128_32); //12832
SSD1306Wire display(0x3c, D3, D4);  //12864




//LiquidCrystal_I2C lcd(0x3F,20,4);

const char* ssid = "GolemioDisplay";
const char* password = "password";

int sloupecLinka = 0;
int sloupecCil = 4;
int sloupecCas = 15;
int delkaCile = 30;
int delkaLinky = 3;
String idZastavky = "58791"; //58762 balabenka
String parametry = "";
char parametryC[200]="?cisIds=58791&minutesBefore=1&minutesAfter=30&limit=5&mode=departures&filter=routeHeadingOnce&includeMetroTrains=true&order=real";

String retezec = "";


void saveConfigFile()
{
  Serial.println(F("Saving config"));
  StaticJsonDocument<512> json;
  json["klic"] = klic;
  json["parametryC"] = parametryC;
 

  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    Serial.println("failed to open config file for writing");
  }

  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    Serial.println(F("Failed to write to file"));
  }
  configFile.close();
}

bool loadConfigFile()
{
  //clean FS, for testing
  // SPIFFS.format();

  //read configuration from FS json
  Serial.println("mounting FS...");

  // May need to make it begin(true) first time you are using SPIFFS
  // NOTE: This might not be a good way to do this! begin(true) reformats the spiffs
  // it will only get called if it fails to mount, which probably means it needs to be
  // formatted, but maybe dont use this if you have something important saved on spiffs
  // that can't be replaced.
  if (SPIFFS.begin())
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        Serial.println("opened config file");
        StaticJsonDocument<512> json;
        DeserializationError error = deserializeJson(json, configFile);
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          Serial.println("\nparsed json");

          strcpy(parametryC, json["parametryC"]);
          strcpy(klic, json["klic"]);
          

          return true;
        }
        else
        {
          Serial.println("failed to load json config");
        }
      }
    }
  }
  else
  {
    Serial.println("failed to mount FS");
  }
  //end read
  return false;
}

//callback notifying us of the need to save config
void saveConfigCallback()
{
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

// This gets called when the config mode is launced, might
// be useful to update a display with this info.
void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entered Conf Mode");

  Serial.print("Config SSID: ");
  Serial.println(myWiFiManager->getConfigPortalSSID());

  Serial.print("Config IP Address: ");
  Serial.println(WiFi.softAPIP());

  display.drawString(0, 0,"Config SSID: ");
  display.drawString(0, 10,myWiFiManager->getConfigPortalSSID());
  display.drawString(0, 20,"Config IP Address: ");
  display.drawString(0, 30,WiFi.softAPIP().toString());
   display.drawString(0, 40,"Password: ");
  display.drawString(0, 50,password);
  display.display();

}

void setup()
{
 display.init();
  display.clear();
  
  Serial.begin(115200);
  Serial.println("displej bezi na SCL:" + String(SCL) + " SDA:" + String(SDA)); 
  display.flipScreenVertically();
  display.setFont(DejaVu_Sans_10);

  bool forceConfig = false;

  drd = new DoubleResetDetector(DRD_TIMEOUT, DRD_ADDRESS);
  if (drd->detectDoubleReset())
  {
    Serial.println(F("Forcing config mode as there was a Double reset detected"));
    forceConfig = true;
  }

  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }

  //WiFi.disconnect();
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  Serial.begin(115200);
  delay(10);

  // wm.resetSettings(); // wipe settings

  WiFiManager wm;

  //wm.resetSettings(); // wipe settings
  //set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  //--- additional Configs params ---

  // Text box (String)
 WiFiManagerParameter custom_text_box("api_key", "Golemio Klíč", klic, 350); // 50 == max length
WiFiManagerParameter custom_text_box2("parametry", "parametry dotazu", parametryC, 200); // 50 == max length


  //add all your parameters here
  wm.addParameter(&custom_text_box);
  wm.addParameter(&custom_text_box2);
  

  Serial.println("hello");

  
  if (forceConfig)
  {
    if (!wm.startConfigPortal(ssid, password))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }
  }
  else
  {
    if (!wm.autoConnect(ssid, password))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      // if we still have not connected restart and try all over again
      ESP.restart();
      delay(5000);
    }
  }

  Serial.println("connected...yeey :)");

  display.clear();

    

   // display.drawStringMaxWidth(0, 0, 128, retezec);
   




  

  Serial.println("");
  Serial.println("WiFi connected");

  display.clear();
  display.drawString(0, 0,"IP address: ");
  display.drawString(0, 10, WiFi.localIP().toString());
  display.display();

  delay(2000);

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Lets deal with the user config values

  // Copy the string value
  strncpy(klic, custom_text_box.getValue(), sizeof(klic));
  strncpy(parametryC, custom_text_box2.getValue(), sizeof(parametryC));

  display.clear();

   display.drawString(0, 0," klic: ");
  display.drawString(0, 10,klic);
  display.drawString(0, 20," parametry: ");
  display.drawStringMaxWidth(0, 30, 128,parametryC);

 

display.display();

 



  //save the custom parameters to FS
  if (shouldSaveConfig)
  {
    saveConfigFile();
  }

configTime(1 * 3600, 1, "pool.ntp.org", "time.nist.gov");
delay(3000);
}

void stahni() {

  if (WiFi.status() == WL_CONNECTED) {  //Check WiFi connection status

    WiFiClient client;
    HTTPClient http;  //Declare an object of class HTTPClient
    String celaAdresa = "http://api.golemio.cz/v2/pid/departureboards/";
    //celaAdresa += "?cisIds=" + idZastavky;

    celaAdresa += parametryC;
    //http.begin("http://www.mpvnet.cz/PID/x/62887?pocet=15&pz=true&t=true");  //Specify request destination
    http.begin(client, celaAdresa);
    http.addHeader("X-Access-Token", klic);


    int httpCode = http.GET();  //Send the request

    if (httpCode > 0) {  //Check the returning code

      Serial.println("kod: " + String(httpCode));
      String payload = http.getString();  //Get the request response payload
      Serial.println(payload);            //Print the response payload

      const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
      DynamicJsonDocument root(9000);




      DeserializationError error = deserializeJson(root, payload);

      // Test if parsing succeeds.
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }

      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      int maxPocetOdjezdu = 5;
      int cisloRadkuInfo = 5;
      if (vyska32 == 1) {
        maxPocetOdjezdu = 2;
        cisloRadkuInfo = 2;
      }



      int arraySize = root["departures"].size();
      Serial.println("pocet odjezdu:" + String(arraySize));

      int counter = 0;

      for (int i = 0; ((i < arraySize) && (i < maxPocetOdjezdu)); i++) {

        String cas = root["departures"][i]["departure_timestamp"]["minutes"].as<char*>();
        String linka = root["departures"][i]["route"]["short_name"].as<char*>();
        String cil = root["departures"][i]["trip"]["headsign"].as<char*>();
        Serial.println(linka + " " + cil + " " + cas);

        vykresliRadekOdjezdu(linka, cil, cas, counter);
        counter++;
      }

      String casPrikaz = "0:48";
      String den="";

      //////// cas

      time_t rawtime;
      struct tm* timeinfo;
      time(&rawtime);

      timeinfo = localtime(&rawtime);
      char buffer[80];

      //strftime(buffer, 80, "%Y%m%d",timeinfo);
      strftime(buffer, 80, "%d.%m.%Y  %R", timeinfo);      

      casPrikaz = buffer;
      strftime(buffer, 80, "%u", timeinfo);
      den = buffer;

      ////////konec casu

      vykresliSpodniRadekDatum(casPrikaz, nahradOled(cisloDoDne(den.toInt())), cisloRadkuInfo);
      display.display();

    }

    http.end();  //Close connection
  }

  delay(30000);  //Send a request every 30 seconds
}

void loop()
{
  drd->loop();
  stahni();
}



String nahradOled(String vstup) {
  //pro pouziti s knihovnou https://github.com/ThingPulse/esp8266-oled-ssd1306
  //vstup = vstup.substring(0, delkaCile);


  //vstup.replace("á", "a");
  // vstup.replace("Á", "A");
  vstup.replace("č", "c");
  vstup.replace("Č", "C");
  vstup.replace("ď", "d");
  vstup.replace("Ď", "D");

  //vstup.replace("é", "e");

  // vstup.replace("É", "E");
  vstup.replace("ě", "e");
  vstup.replace("Ě", "E");
  //  vstup.replace("í", "i");
  //  vstup.replace("Í", "I");
  vstup.replace("ň", "n");
  vstup.replace("Ň", "N");
  // vstup.replace("ó", "o");
  vstup.replace("Ó", "O");
  vstup.replace("ř", "r");
  vstup.replace("Ř", "r");
  vstup.replace("š", "s");
  vstup.replace("Š", "S");
  vstup.replace("ť", "t");
  vstup.replace("Ť", "T");
  //vstup.replace("ú", "u");
  // vstup.replace("Ú", "U");
  vstup.replace("ů", "u");
  vstup.replace("Ů", "U");
  //vstup.replace("ý", "y");
  //vstup.replace("Ý", "Y");
  vstup.replace("ž", "z");
  vstup.replace("Ž", "Z");

  //vstup.replace("", "");

  return vstup;
}


String zkratText(String vstup, int maxSirka) {
  String vystup = vstup;
  int puvodniDelka = vstup.length();
  int novaDelka = puvodniDelka;

  Serial.println("zacinam zmensovat puvodniDelka:" + String(puvodniDelka) + " maxSirka:" + String(maxSirka));
  while (display.getStringWidth(vystup) > abs(maxSirka)) {
    novaDelka--;
    vystup = vystup.substring(0, novaDelka);
  }

  return vystup;
}

String cisloDoDne(int vstup) {
  String vystup = "";
  String poleDnu[]={"","Pondělí","Úterý","Středa","Čtvrtek","Pátek","Sobota","Neděle"};
  
  if((vstup<0)||(vstup>7))
  {
    return "";
  }  
  
  vystup=poleDnu[vstup];
  
  return vystup;
}

void vykresliRadekOdjezdu(String linka, String cil, String cas, int radek) {
  int sloupecCile = 20;
  int vyskaRadku = 10;
  int sloupecCasu = 128;
  int pravyOkrajCile = 100;
  int maxSirkaTextu = sloupecCile - pravyOkrajCile;
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, radek * vyskaRadku, linka);


  //display.drawString(sloupecCile, radek * vyskaRadku, zkratText(cil, maxSirkaTextu));
  display.drawString(sloupecCile, radek * vyskaRadku, nahradOled(cil));

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(sloupecCasu, radek * vyskaRadku, cas);
}


void vykresliSpodniRadek(String cas, int aktStranka, int pocetStranek, int radek) {

  int vyskaRadku = 10;
  int sloupecCas = 128;
  int posunPc = 0;
  int posunNc = 0;
  int posun = 3;

  int y0 = 64 - vyskaRadku - posun + 1;
  if (vyska32 == 1) {
    posun = 1;
    y0 = 32 - vyskaRadku - posun + 1;
  }

  display.drawLine(0, y0, sloupecCas, y0);

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, radek * vyskaRadku + posun, String(aktStranka) + "/" + String(pocetStranek));


  //display.drawString(sloupecCile, counter*vyskaRadku, zkratText(cil,maxSirkaTextu));

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(sloupecCas, radek * vyskaRadku + posun, cas);
}

void vykresliSpodniRadekDatum(String cas, String den, int radek) {

  int vyskaRadku = 10;
  int sloupecCas = 128;
  int posunPc = 0;
  int posunNc = 0;
  int posun = 3;




  int y0 = 64 - vyskaRadku - posun + 1;
  if (vyska32 == 1) {
    posun = 1;
    y0 = 32 - vyskaRadku - posun + 1;
  }

  display.drawLine(0, y0, sloupecCas, y0);

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, radek * vyskaRadku + posun, den);


  //display.drawString(sloupecCile, counter*vyskaRadku, zkratText(cil,maxSirkaTextu));

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(sloupecCas, radek * vyskaRadku + posun, cas);
}


