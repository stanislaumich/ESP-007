#ifndef MyTeleBot
#define MyTeleBot
#include "common.h"
#include "defs.h"
#include "myTime.h"
#include "myDisplay.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

BearSSL::WiFiClientSecure client;
UniversalTelegramBot bot(myToken, client); 

volatile bool debug=0;


int Bot_mtbs = 1000; 
long Bot_lasttime;   
bool Start = false;

const int ledPin = 13;
int ledStatus = 0; 


String from_name="";
String execCommand(String chat_id, String text);
String getTimestr(void);

String sendtobot(String ch_id, String mess){
  String m="="+ch_id+"="+myName+"="+mess;
  ch_id==LzName?bot.sendMessage(LzName, m, ""):bot.sendMessage(S868, m, "");
  return m;
}

String millis2time();

void answerbot(String chat_id, String text){   
  //String mess="-? > "+text;
  if(text.indexOf("=")==0){
    text.remove(0,1);
    int p = text.indexOf('=');
    String name = text.substring(0, p);
    text.remove(0,p+1);
    p = text.indexOf('=');
    name = text.substring(0,p);
    text.remove(0,p+1);
    text.trim();
    sendtobot(name, execCommand(chat_id,text));
   }
   else{
    bot.sendMessage(chat_id,execCommand(chat_id,text));
   }  
 }
 
String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
 }  

String execCommand(String chat_id, String text){
   String answ="? - > "+text;
   if (text == "/d0") {
       debug=0;
      answ="+debug set OFF";
    } 
    if (text == "/d1") {
       debug=1;
      answ="+debug set ON";
    } 
   return answ; 
 }

void handleNewMessages(int numNewMessages) {
  for (int i=0; i<numNewMessages; i++) {
    //bot.sendMessage(myTele, "Проверка00", "");
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;
    from_name = bot.messages[i].from_name;
    if (from_name == "") from_name = "UNKNOWN";
    if (debug){
      bot.sendMessage(myTele, "Debug==1(/d0 to OFF)! :> "+text, "");      
    }
    answerbot(chat_id,text);
   }
 } 

void MyTeleBotInit(void){
  client.setInsecure(); // иначе не соединяется без этой команды
 } 

void goBot(void){
    if (millis() > Bot_lasttime + (unsigned int)Bot_mtbs)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while(numNewMessages) {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    Bot_lasttime = millis();
  } 
 }

#endif