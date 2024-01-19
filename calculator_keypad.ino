#include <Keypad.h>

const int dim = 4;
char dugmici[dim][dim]={
  {'1','2','3','A'},
  {'4','5','6', 'B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte pinovi_vrsta[dim]= {9,8,7,6};
byte pinovi_kolona[dim] = {5,4,3,2};

Keypad key = Keypad(makeKeymap(dugmici),pinovi_vrsta,pinovi_kolona,dim,dim);

boolean rezultat = false;
long rez = 0;
int broj = 0;
int broj2=0;
char znak = ' ';
char taster;


void setup() {
  Serial.begin(9600);
}


void loop() {
  taster = key.getKey();
  if (taster!=NO_KEY) {
    Pritisnut_taster();
  }

  if (rezultat==true) {
    Racunanje();
  }
}


long Racunanje(){
  rez=0;
  if (znak=='+') {
    rez = broj+broj2;
    Serial.println("First number: ");
    Serial.println(broj);
    Serial.println("Second number: ");
    Serial.println(broj2);
    Serial.println("Result: ");
    Serial.println(rez);
  }
  if (znak=='-') {
    rez=broj-broj2;
    Serial.println("First number: ");
    Serial.println(broj);
    Serial.println("Second number: ");
    Serial.println(broj2);
    Serial.println("Result: ");
    Serial.println(rez);
  } 
  if (znak=='/') {
    rez= broj/broj2;
    Serial.println("First number: ");
    Serial.println(broj);
    Serial.println("Second number: ");
    Serial.println(broj2);
    Serial.println("Result: ");
    Serial.println(rez);
  } 
  if (znak=='*') {
    rez = broj * broj2;
    Serial.println("First number: ");
    Serial.println(broj);
    Serial.println("Second number: ");
    Serial.println(broj2);
    Serial.println("Result: ");
    Serial.println(rez);
  }
  rezultat=false;
}


void Pritisnut_taster() {
  if (taster=='C') {
    rez=broj=broj2=0;
    rezultat=false;
  }
  
  if (taster == '1') {
    if (broj==0) {
      broj==1;
    } else {
      broj = (broj*10)+1;
    }
  }

  if (taster=='2') {
    if (broj==0) {
      broj=2;
    } else {
      broj = (broj*10)+2;
    }
  }

  if (taster=='3') {
    if (broj==0) {
      broj=3;
    } else {
      broj = (broj*10)+3;
    }
  }

  if (taster=='4') {
    if (broj==0) {
      broj=4;
    } else {
      broj = (broj*10)+4;
    }
  }

  if (taster=='5') {
    if (broj==0) {
      broj=5;
    } else {
      broj = (broj*10)+5;
    }
  }

  if (taster=='6') {
    if (broj==0) {
      broj=6;
    } else {
      broj = (broj*10)+6;
    }
  }

  if (taster=='7') {
    if (broj==0) {
      broj=7;
    } else {
      broj = (broj*10)+7;
    }
  }


  if (taster=='8') {
    if (broj==0) {
      broj=8;
    } else {
      broj = (broj*10)+8;
    }
  }

  if (taster=='9') {
    if (broj==0) {
      broj=9;
    } else {
      broj = (broj*10)+9;
    }
  }

  if (taster=='#') {
    rezultat = true;
  }

  if (taster == 'A' || taster == 'B' || taster == '*' || taster == 'D') {
    
    if (taster == 'A') {
      znak='+';
      broj2=broj;
      broj=0;
    }

    if (taster == '*') {
      znak='*';
      broj2=broj;
      broj=0;
    }

    if (taster == 'D') {
      znak='/';
      broj2=broj;
      broj=0;
    }

    if (taster == 'B') {
     znak='-';
     broj2=broj;
     broj=0;
    }
  }

  delay(150);
}


