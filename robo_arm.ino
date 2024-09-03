#include <IRremote.h>
#include <Servo.h>

IRrecv r = IRrecv(7);
Servo sb = Servo();
Servo sx = Servo();
Servo sy = Servo();
Servo sh = Servo();

decode_results d = decode_results();
int sbv = 90;
int sxv = 90;
int syv = 90;
int shv = 180;


void setup() {
  r.enableIRIn();
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  sb.attach(6);
  sb.write(sbv);
  sx.attach(5);
  sx.write(sxv);
  sy.attach(4);
  sy.write(syv);
  sh.attach(3);
  sh.write(shv);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  if (r.decode(&d)) {

    int v = d.value;

    if (v == 31365) {
      if (0 < sbv < 180) {
        for (int x = 0; x < 10; x++) {
          sbv = sbv + 1;
          sb.write(sbv);
          Serial.println(sbv);
          delay(30);
        }
      }

    } else if (v == 12495) {
      if (0 < sbv < 180) {
        for (int x = 0; x < 10; x++) {
          sbv = sbv - 1;
          sb.write(sbv);
          Serial.println(sbv);
          delay(30);
        }
      }

    } else if (v == 4335) {
      if (0 < sxv < 180) {
        for (int x = 0; x < 10; x++) {
          sxv = sxv + 1;
          sx.write(sxv);
          Serial.println(sxv);
          delay(30);
        }
      }

    } else if (v == 17085) {
      if (0 < sxv < 180) {
        for (int x = 0; x < 10; x++) {
          sxv = sxv - 1;
          sx.write(sxv);
          Serial.println(sxv);
          delay(30);
        }
      }

    } else if (v == 14535) {
      if (0 < syv < 180) {
        for (int x = 0; x < 10; x++) {
          syv = syv - 1;
          sy.write(syv);
          Serial.println(syv);
          delay(30);
        }
      }
    } else if (v == 19125) {
      if (0 < syv < 180) {
        for (int x = 0; x < 10; x++) {
          syv = syv + 1;
          sy.write(syv);
          Serial.println(syv);
          delay(30);
        }
      }

    } else if (v == 21165) {
      if (0 < shv < 180) {
        for (int x = 0; x < 10; x++) {
          shv = shv - 1;
          sh.write(shv);
          Serial.println(shv);
          delay(30);
        }
      }

    } else if (v == 23205) {
      if (0 < shv < 180) {
        for (int x = 0; x < 10; x++) {
          shv = shv + 1;
          sh.write(shv);
          Serial.println(shv);
          delay(30);
        }
      }

    } else if (v == 6375) {
      int dif = 0;
      if (sbv > 90) {
        dif = sbv - 90;
        for (int x = 0; x < dif; x++) {
          sbv = sbv - 1;
          sb.write(sbv);
          delay(15);
        }
      } else if (sbv < 90) {
        dif = 90 - sbv;
        for (int x = 0; x < dif; x++) {
          sbv = sbv + 1;
          sb.write(sbv);
          Serial.println(sbv);
          delay(15);
        }
      }
      if (sxv > 90) {
        dif = sxv - 90;
        for (int x = 0; x < dif; x++) {
          sxv = sxv - 1;
          sx.write(sxv);
          delay(15);
        }
      } else if (sxv < 90) {
        dif = 90 - sxv;
        for (int x = 0; x < dif; x++) {
          sxv = sxv + 1;
          sx.write(sxv);
          Serial.println(sxv);
          delay(15);
        }
      }
      delay(20);

      if (syv > 90) {
        dif = syv - 90;
        for (int x = 0; x < dif; x++) {
          syv = syv - 1;
          sy.write(syv);
          delay(15);
        }
      } else if (syv < 90) {
        dif = 90 - syv;
        for (int x = 0; x < dif; x++) {
          syv = syv + 1;
          sy.write(syv);
          Serial.println(syv);
          delay(15);
        }
      }

      delay(20);

      if (shv < 180) {
        dif = 180 - shv;
        for (int x = 0; x < dif; x++) {
          shv = shv + 1;
          sh.write(shv);
          Serial.println(shv);
          delay(15);
        }
      }
    }

    Serial.println(v);

    r.resume();
  }
}
