#include QMK_KEYBOARD_H
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

//#define XXX_RAIS LT(_RAISE,KC_XXX)
#define ESC_RAIS LT(_RAISE,KC_ESC)
#define TAB_LOWR LT(_LOWER,KC_TAB)
#define ENT_LOWR LT(_LOWER,KC_ENT)
#define ESC_ADJ  LT(_ADJUST,KC_ESC)
#define LCTL_SPC LCTL_T(KC_SPC)
#define RCTL_SPC RCTL_T(KC_SPC)
#define ALT_MHEN RALT_T(KC_MHEN)
#define ALT_HENK RALT_T(KC_HENK)
#define SFT_BSLS RSFT_T(JP_BSLS)
#define LCTL_YEN LCTL_T(JP_YEN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |EscRas|   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  \|  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  -=  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ;+  |  :*  |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |  ,<  |  .>  |   /  |  \_  |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |AltMhn|CtlSpc| Bksp |TabLwr|EntLwr|Space |CtlSpc|Raise |AltHen|
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  ESC_RAIS,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_YEN, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_MINS, \
  LCTL_YEN,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_COLN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, JP_LBRC, JP_RBRC, KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, SFT_BSLS, \
                 KC_LGUI,ALT_MHEN,LCTL_SPC, KC_BSPC,TAB_LOWR,ENT_LOWR, KC_SPC,  RCTL_SPC,RAISE,   ALT_HENK \
),

/* Colemak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |AltMhn|CtlSpc| Bksp |TabLwr|EntLwr|Space |CtlSpc|Raise |AltHen|
 *               `---------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, JP_LBRC, JP_RBRC, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
                 KC_LGUI,ALT_MHEN,LCTL_SPC, KC_BSPC,TAB_LOWR,ENT_LOWR, KC_SPC,  RCTL_SPC,RAISE,   ALT_HENK \
),

/* Dvorak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |   ]  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |AltMhn|CtlSpc| Bksp |TabLwr|EntLwr|Space |CtlSpc|Raise |AltHen|
 *               `---------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, JP_LBRC, JP_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
                 KC_LGUI,ALT_MHEN,LCTL_SPC, KC_BSPC,TAB_LOWR,ENT_LOWR, KC_SPC,  RCTL_SPC,RAISE,   ALT_HENK \
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | Calc |   ?  |      |   ;  |   :  |   <  |             |   >  |   7  |   8  |   9  |   *  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  Tab |   !  |   "  |   #  |   $  |   [  |             |   ]  |   4  |   5  |   6  |   -  |  =   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   ~  |   '  |   @  |   &  |   (  |             |   )  |   1  |   2  |   3  |   +  |  ^   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   %  |   `  |   _  |   |  |   {  |   [  |   ]  |   }  |   0  |   ,  |   .  |   /  | Enter|
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |AltMhn|CtlSpc| Bksp |      |      |  Spc |   0  |      |AltHen|
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_CALC, KC_QUES, _______, JP_SCLN, JP_COLN, JP_LT,                     JP_GT,   KC_7,    KC_8,    KC_9,    JP_ASTR, KC_BSPC, \
  KC_TAB,  JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,  JP_LBRC,                   JP_RBRC, KC_4,    KC_5,    KC_6,    JP_MINS, JP_EQL, \
  LCTL_YEN,JP_TILD, JP_QUOT, JP_AT,   JP_AMPR, JP_LPRN,                   JP_RPRN, KC_1,    KC_2,    KC_3,    JP_PLUS, JP_CIRC, \
  KC_LSFT, JP_PERC, JP_GRV,  JP_UNDS, JP_PIPE, JP_LCBR, JP_LBRC, JP_RBRC, JP_RCBR, KC_0,    JP_COMM, JP_DOT,  JP_SLSH, KC_ENT, \
                    KC_LGUI,ALT_MHEN,LCTL_SPC, KC_BSPC, _______, _______, KC_SPC,  KC_0,     _______,ALT_HENK \
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |  INS |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |ZenHan|      |      |      |      |      |             |  F11 |  F12 |  ↑   |      |      |  DEL |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |             |      |  ←   |  ↓   |  →   | HOME | PGUP |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |  Ins |  Del |      |      |  ↓   |      |  END | PGDN |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |AltMhn|CtlSpc| Bksp |      |      |  Spc |CtlSpc|      |AltHen|
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS, \
  JP_ZHTG, _______, _______, _______, _______, _______,                   KC_F11,  KC_F12,  KC_UP  , _______, _______, KC_DEL, \
  KC_LCTL, _______, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_PGUP, \
  KC_LSFT, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______, _______, KC_DOWN, _______, KC_END,  KC_PGDN, \
                    KC_LGUI,ALT_MHEN,LCTL_SPC, KC_BSPC, _______, _______, KC_SPC,  RCTL_SPC,_______,ALT_HENK \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______, \
  QWERTY,  COLEMAK, DVORAK,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
