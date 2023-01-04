// Uncomment next line if you use ProMicro
// #define PRO_MICRO

// Uncomment next line if your PC thinks this is US keyboard.
// #define JP_KEYBOARD

#include "Keyboard.h"

#ifdef PRO_MICRO

// COLS = 9,8,7,6,5,4
// ROWS = 18,15,14,16,10

typedef enum {
  C0 = 9,
  C1 = 8,
  C2 = 7,
  C3 = 6,
  C4 = 5,
  C5 = 4,
  R0 = 18,
  R1 = 15,
  R2 = 14,
  R3 = 16,
  R4 = 10,
} Pin;

#define PINS 11
Pin pins[] = {C0, C1, C2, C3, C4, C5, R0, R1, R2, R3, R4};

#else

// COLS = PD0, PD1, PD2, PD3, PD4, PD5
// ROWS = PB0, PB1, PB2, PB3, PB4

#define COL B10000000
#define ROW B00000000

typedef enum {
  C0 = COL + 0,
  C1 = COL + 1,
  C2 = COL + 2,
  C3 = COL + 3,
  C4 = COL + 4,
  C5 = COL + 5,

  R0 = ROW + 0,
  R1 = ROW + 1,
  R2 = ROW + 2,
  R3 = ROW + 3,
  R4 = ROW + 4,
  R5 = ROW + 5,
  R6 = ROW + 6,
  R7 = ROW + 7,
  R8 = ROW + 0,
  R9 = ROW + 1,
  R10 = ROW + 4,
  R11 = ROW + 5

} Pin;

typedef enum {
  PortB = 0,
  PortD = 1,
  PortF = 2  
} Port;

#endif

#define ROWS 5
#define COLS 12

//Pin keys[5][12][2] = {
//    {
//        {C0, R4},
//        {C1, R0},
//        {C2, R1},
//        {C3, R2},
//        {C4, R3},
//        {C5, R4},
//        {R0, C0},
//        {R1, C1},
//        {R2, C2},
//        {R3, C3},
//        {R4, C4},
//        {R0, C5},
//    },
//    {
//        {C0, R3},
//        {C1, R4},
//        {C2, R0},
//        {C3, R1},
//        {C4, R2},
//        {C5, R3},
//        {R4, C0},
//        {R0, C1},
//        {R1, C2},
//        {R2, C3},
//        {R3, C4},
//        {R4, C5},
//    },
//    {
//        {C0, R2},
//        {C1, R3},
//        {C2, R4},
//        {C3, R0},
//        {C4, R1},
//        {C5, R2},
//        {R3, C0},
//        {R4, C1},
//        {R0, C2},
//        {R1, C3},
//        {R2, C4},
//        {R3, C5},
//    },
//    {
//        {C0, R1},
//        {C1, R2},
//        {C2, R3},
//        {C3, R4},
//        {C4, R0},
//        {C5, R1},
//        {R2, C0},
//        {R3, C1},
//        {R4, C2},
//        {R0, C3},
//        {R1, C4},
//        {R2, C5},
//    },
//    {
//        {C0, R0},
//        {C1, R1},
//        {C2, R2},
//        {C3, R3},
//        {C4, R4},
//        {C5, R0},
//        {R1, C0},
//        {R2, C1},
//        {R3, C2},
//        {R4, C3},
//        {R0, C4},
//        {R1, C5},
//    },
//};

Pin keys[5][12][2] = {
    {
        {C3, R5},
        {C2, R4},
        {C1, R3},
        {C0, R2},
        {C5, R1},
        {C4, R0},
        {C3, R11},
        {C2, R10},
        {C1, R9},
        {C0, R8},
        {C5, R7},
        {C4, R6},
    },
    {
        {C2, R5},
        {C1, R4},
        {C0, R3},
        {C5, R2},
        {C4, R1},
        {C3, R0},
        {C2, R11},
        {C1, R10},
        {C0, R9},
        {C5, R8},
        {C4, R7},
        {C3, R6},
    },
    {
        {C1, R5},
        {C0, R4},
        {C5, R3},
        {C4, R2},
        {C3, R1},
        {C2, R0},
        {C1, R11},
        {C0, R10},
        {C5, R9},
        {C4, R8},
        {C3, R7},
        {C2, R6},
    },
    {
        {C0, R5},
        {C5, R4},
        {C4, R3},
        {C3, R2},
        {C2, R1},
        {C1, R0},
        {C0, R11},
        {C5, R10},
        {C4, R9},
        {C3, R8},
        {C2, R7},
        {C1, R6},
    },
    {
        {C5, R5},
        {C4, R4},
        {C3, R3},
        {C2, R2},
        {C1, R1},
        {C0, R0},
        {C5, R11},
        {C4, R10},
        {C3, R9},
        {C2, R8},
        {C1, R7},
        {C0, R6},
    },
};

uint16_t chars[5][12] = {
    {
        'f',  // f
        'v',  // v
        KEY_LEFT_ALT,  // alt
        KEY_UP_ARROW,  // up
        0xEE,  // fn
        ',',  // ,
        'l',  // l
        'o',  // o
        '9',  // 9
        '\n',  // enter
        '4',  // 4
        'r',  // r
    },
    {
        'd',  // d
        'c',  // c
        '/',  // /
        ' ',  // 
        KEY_BACKSPACE,  // back
        'm',  // m
        'k',  // k
        'i',  // i
        '8',  // 8
        KEY_TAB,  // tab
        '3',  // 3
        'e',  // e
    },
    {
        's',  // s
        'x',  // x
        '\\',  // |
        '[',  // [
        ']',  // ]
        'n',  // n
        'j',  // j
        'u',  // u
        '7',  // 7
        '`',  // `
        '2',  // 2
        'w',  // w
    },
    {
        'a',  // a
        'z',  // z
        '\'',  // '
        '-',  // -
        '=',  // =
        'b',  // B
        'h',  // H
        'y',  // Y
        '6',  // 6
        KEY_ESC,  // ESC+CAP
        '1',  // 1  
        'q',  // q
    },
    {
        'g',  // g
        KEY_LEFT_SHIFT,  // shift
        KEY_LEFT_ARROW,  // left
        KEY_DOWN_ARROW,  // down
        KEY_RIGHT_ARROW,  // right
        '.',  // .
        ';',  // ;
        'p',  // p
        '0',  // 0
        KEY_LEFT_CTRL,  // ctrl
        '5',  // 5
        't',  // t
    },
};

uint16_t shift_chars[5][12] = {
    {
        'f',  // f
        'v',  // v
        KEY_LEFT_ALT,  // alt
        KEY_UP_ARROW,  // up
        0xEE,  // fn
        ',',  // ,
        'l',  // l
        'o',  // o
        '9',  // 9
        '\n',  // enter
        '4',  // 4
        'r',  // r
    },
    {
        'd',  // d
        'c',  // c
        '/',  // /
        ' ',  // 
        KEY_BACKSPACE,  // back
        'm',  // m
        'k',  // k
        'i',  // i
        '8',  // 8
        KEY_TAB,  // tab
        '3',  // 3
        'e',  // e
    },
    {
        's',  // s
        'x',  // x
        '\\',  // |
        '[',  // [
        ']',  // ]
        'n',  // n
        'j',  // j
        'u',  // u
        '7',  // 7
        '`',  // `
        '2',  // 2
        'w',  // w
    },
    {
        'a',  // a
        'z',  // z
        '\'',  // '
        '-',  // -
        '=',  // =
        'b',  // B
        'h',  // H
        'y',  // Y
        '6',  // 6
        KEY_ESC,  // ESC+CAP
        '1',  // 1  
        'q',  // q
    },
    {
        'g',  // g
        KEY_LEFT_SHIFT,  // shift
        KEY_LEFT_ARROW,  // left
        KEY_DOWN_ARROW,  // down
        KEY_RIGHT_ARROW,  // right
        '.',  // .
        ';',  // ;
        'p',  // p
        '0',  // 0
        KEY_LEFT_CTRL,  // ctrl
        '5',  // 5
        't',  // t
    },
};

void selectRow(Pin p,Port po) {
  byte mask = 1 << (p & B01111111);
//  if (mask == 1)Serial.println("Ding ");
  switch(po){
    case PortB:
      DDRB = mask;
      PORTB = ~mask;
      break;

    case PortD:
      DDRD = mask;
      PORTD = ~mask;
      break;

    case PortF:
      DDRF = mask;
      PORTF = ~mask;
      break;

    default:
      break;  
  }
}

void unselectRows() {
  DDRD = 0;
  PORTD = B00111111;
  DDRB = 0x08;
  PORTB = B11111111;
  DDRF = 0x08;
  PORTF = B00110011;
}

bool readCol(Pin p) {
  byte mask = 1 << (p & B01111111);
  byte val = 0;
  val = PIND;
  
  return (PIND & mask) == 0;
}

void setup() {
  Keyboard.begin();
  Serial.begin(9600);

  unselectRows();

  delay(100);
}

#define KEYBOARD_REPORT_ID 2

void sendKeyPush(uint8_t code, bool shift) {
  KeyReport keys;
  keys.keys[0] = 0;
  keys.keys[1] = 0;
  keys.keys[2] = 0;
  keys.keys[3] = 0;
  keys.keys[4] = 0;
  keys.keys[5] = 0;
  keys.modifiers = 0x00;
  if (shift) {
    keys.modifiers = 0x02;
    HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  }
  keys.keys[0] = code;
  HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  keys.keys[0] = 0;
  HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  if (shift) {
    keys.modifiers = 0;
    HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  }
}

#define KEY_0 0x27
#define KEY_1 0x1e
#define KEY_2 0x1f
#define KEY_3 0x20
#define KEY_4 0x21
#define KEY_5 0x22
#define KEY_6 0x23
#define KEY_7 0x24
#define KEY_8 0x25
#define KEY_9 0x26

#define KEY_A 0x04
#define KEY_B 0x05
#define KEY_C 0x06
#define KEY_D 0x07
#define KEY_E 0x08
#define KEY_F 0x09
#define KEY_U 0x18
#define KEY_EQUAL 0x2e
#define KEY_SEMICOLON 0x33
#define KEY_SPC 0x2c
#define KEY_ENT 0x28

void sendHex(int16_t in) {
  static const uint8_t codes[] = {
      KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7,
      KEY_8, KEY_9, KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F,
  };
  static const bool shifts[] = {
      false, false, false, false, false, false, false, false,
      false, false, true,  true,  true,  true,  true,  true,
  };
  for (int i = 0; i < 4; i++) {
    byte f = (in >> ((3 - i) * 4)) & 0xf;
    sendKeyPush(codes[f], shifts[f]);
  }
}

int c = 0;

void loop() {
  // delay(10);
//  Serial.println("--------");
  selectRow(R4,PortB);
  bool shiftd = readCol(C4);
  delayMicroseconds(50);
  if (shiftd) Keyboard.press(KEY_LEFT_SHIFT);
  else Keyboard.release(KEY_LEFT_SHIFT);
  unselectRows();
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      Pin* key = keys[r][c];
      if ((c <= 9) && (c >= 6)){
        selectRow(key[1],PortF);
      } else {
        selectRow(key[1],PortB);
      }
      delayMicroseconds(50);
      bool pushed = readCol(key[0]);
//      Serial.print(pushed ? "1" : "0");
      if (pushed) {
        Keyboard.write(chars[r][c]);
        // if (shiftd) Keyboard.write('D');
        // sendHex(chars[r][c]);
        // sendKeyPush(KEY_SPC, false);
        // sendKeyPush(KEY_SPC, false);
        // sendKeyPush(KEY_ENT, false);

        delay(200);
      }
      unselectRows();
    }
//    Serial.println();
  }
  // Keyboard.releaseAll();
}
