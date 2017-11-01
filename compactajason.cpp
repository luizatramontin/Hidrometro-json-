# Hidrometro-jason-

#include <ArduinoJson.h>

// Step 1: Reserva espaço de memória
DynamicJsonBuffer jsonBuffer;

void setup() {
  
  Serial.begin(9600);
  String str1 = "{\"serial\":\"3234fd7077\",\"data_hora\":\"2017-01-10  11:11:11\",\"pulso\":20}";
  String str2 = "{\"serial\":\"3234fd7077\",\"data_hora\":\"2017-01-10  22:22:22\",\"pulso\":40}";
  String retorno = compactaJson(str1, str2);
  Serial.println(retorno);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

String compactaJson(String um, String dois) {
  JsonObject& jsonUm = jsonBuffer.parseObject(um);
  if (!jsonUm.success())
  {
    Serial.println("parseObject(um) falhou");
    return "";
  }
  JsonObject& jsonDois = jsonBuffer.parseObject(dois);
  if (!jsonDois.success())
  {
    Serial.println("parseObject(dois) falhou");
    return "";
  }
  // Step 3: Retrieve the values
  long   pulso  = 0;
  pulso  +=  long(jsonUm["pulso"]);
  pulso  +=  long(jsonDois["pulso"]);
  jsonUm["pulso"] = pulso;
  
  jsonUm.printTo(um);
  return um;
  //aqui tem de destrui os dois json para liberar a memoria...(só acho)

}
