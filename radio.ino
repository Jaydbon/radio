#include <LiquidCrystal.h>
String title = "Gabry Ponte, HANNAS -One By One-";
String bigTitle;
String song;
String artistShow;
String songShow;
int leng;
int mid;
int ii=0;
int ll=0;
int i,j,k=0,l=0, ok=0;
String toShow;
// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); // set up number of columns and row



  // Putting it on the screen
}

void loop()
{
if (Serial.available() > 0){
  title = Serial.readString();
  leng = title.length();
  mid = title.indexOf(" -");

  // to get song
  song = title.substring(mid + 2, leng - 1);

  // to get artist
  title.remove(mid, leng);
  //Serial.println(artist);
  //Serial.println("shit was sent");
  ii = 0;
  ll = 0;
} else {
int i,j,k=0,l=0, ok=0;
lcd.clear();
//delay(80);
artistShow = title.substring(ii,ii+16);
songShow = song.substring(ll,ll+16);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(songShow);
lcd.setCursor(0,1);
lcd.print(artistShow);
delay(900);
ii = ii + 1;
ll = ll + 1;
if(16>=title.length()) {
    ii = 0;
  }
if(16>=song.length()) {
  ll = 0;
  }
if(ii>(title.length()-16)) {
    ii = 0;
  }
if(ll>(song.length()-16)) {
    ll = 0;
  }



}}