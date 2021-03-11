
int cero[] = {1, 1, 1, 1, 1, 1, 0}, uno[] = {0, 0, 1, 1, 0, 0, 0}, dos[] = {1, 1, 0, 1, 1, 0, 1},
             tres[] = {0, 1, 1, 1, 1, 0, 1}, cuatro[] = {0, 0, 1, 1, 0, 1, 1}, cinco[] = {0, 1, 1, 0, 1, 1, 1},
                      seis[] = {1, 1, 1, 0, 1, 1, 1}, siete[] = {0, 0, 1, 1, 1, 0, 0}, ocho[] = {1, 1, 1, 1, 1, 1, 1},
                               nueve[] = {0, 0, 1, 1, 1, 1, 1};

int leds[] = {1, 2, 3, 4, 5, 6, 7};


void setup() {
  for (int i = 1; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
}


void Alumbrado(int x[]) {
  for (int i = 0; i < 7; i++) {
    if (x[i] == true) {
      digitalWrite(leds[i], HIGH);
    }
  }
}

void Impresor(int num, int posicion) {
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  for (int i = 0; i < 7; i++) {
    digitalWrite(leds[i], LOW);
  }
  switch (num) {
    case 0:
      Alumbrado(cero);
      digitalWrite((8 + posicion), LOW);
      break;
    case 1:
      Alumbrado(uno);
      digitalWrite((8 + posicion), LOW);
      break;
    case 2:
      Alumbrado(dos);
      digitalWrite((8 + posicion), LOW);
      break;
    case 3:
      Alumbrado(tres);
      digitalWrite((8 + posicion), LOW);
      break;
    case 4:
      Alumbrado(cuatro);
      digitalWrite((8 + posicion), LOW);
      break;
    case 5:
      Alumbrado(cinco);
      digitalWrite((8 + posicion), LOW);
      break;
    case 6:
      Alumbrado(seis);
      digitalWrite((8 + posicion), LOW);
      break;
    case 7:
      Alumbrado(siete);
      digitalWrite((8 + posicion), LOW);
      break;
    case 8:
      Alumbrado(ocho);
      digitalWrite((8 + posicion), LOW);
      break;
    case 9:
      Alumbrado(nueve);
      digitalWrite((8 + posicion), LOW);
      break;

  }
}


int l = 0, k = 0, j = 0, i = 0;

void loop() {


  if (digitalRead(22) == HIGH) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
          for (int l = 0; l < 10; l++) {
            int tiempo = 500;
            while (tiempo != 0) {
              tiempo--;
              Impresor(l, 0);
              Impresor(k, 1);
              Impresor(j, 2);
              Impresor(i, 3);
              if (digitalRead(22) == LOW) {
                return 0;
              }
            }
          }
        }
      }
    }
  }



  if (digitalRead(24) == HIGH) {

    l = l + 1;
    if (l > 9) {
      l = 0;
      k += 1;
    }
    if (k > 9) {
      k = 0;
      j += 1;
    }
    if (j > 9) {
      j = 0;
      i += 1;
    }
    if (i > 9) {
      l = 0;
      k = 0;
      j = 0;
      i = 0;
    }
  }



  if (digitalRead(26) == HIGH) {
    l = 0;
    k = 0;
    j = 0;
    i = 0;
    Impresor(l, 0);
    Impresor(k, 1);
    Impresor(j, 2);
    Impresor(i, 3);
  }
  
  if (digitalRead(28) == HIGH) {
    l = l - 1;
    if (l <= -1) {
      l = 9;
      k -= 1;
    }
    if (k <= -1) {
      k = 9;
      j -= 1;
    }
    if (j <= -1) {
      j = 9;
      i -= 1;
    }
    if (i <= -1) {
      l = 9;
      k = 9;
      j = 9;
      i = 9;
    }
  }

  int tiempo = 200;
  while (tiempo != 0) {
    tiempo--;
    Impresor(l, 0);
    Impresor(k, 1);
    Impresor(j, 2);
    Impresor(i, 3);

  }

}
