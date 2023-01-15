#include QMK_KEYBOARD_H
#include "keymap_danish.h"

#define _WOKMOK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _GAME 4
#define _GAMEFN 5

enum custom_keycodes {
  WOKMOK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Tap Dance declarations
enum {
    TD_A_AA,
    TD_O_OE,
    TD_E_AE
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_A_AA] = ACTION_TAP_DANCE_DOUBLE(DK_A, DK_ARNG),
    [TD_O_OE] = ACTION_TAP_DANCE_DOUBLE(DK_O, DK_OSTR),
    [TD_E_AE] = ACTION_TAP_DANCE_DOUBLE(DK_E, DK_AE),
};

// One Shot and modifier aliases
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)  
#define CTL_CMD CTL_T(KC_LCMD)

// Layer aliases
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define RSE_TAB LT(_RAISE, KC_TAB)
#define TG_GAME TG(_GAME)
#define MO_ADJ  MO(_ADJUST)

// Tap Dance aliases
#define TDA_AA TD(TD_A_AA)
#define TDE_AE TD(TD_E_AE)
#define TDO_OE TD(TD_O_OE)

#define CTL_RHT LCTL(KC_RGHT)
#define CTL_LFT LCTL(KC_LEFT)
#define RCS_RHT RCS(KC_RGHT)
#define RCS_LFT RCS(KC_LEFT)
#define CTL_DEL LCTL(KC_DEL)
#define CTL_BSP LCTL(KC_BSPC)

// Firefox tab control
#define TAB_NEW C(KC_T)
#define TAB_CLS C(KC_W)
#define TAB_RHT C(KC_PGDN)
#define TAB_LFT C(KC_PGUP)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WOKMOK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_BSPC,  
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  DK_Q,    DK_C,    DK_L,    DK_M,    DK_K,                               DK_Z,    DK_F,    DK_U,    DK_Y,    DK_COLN, DK_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_ALT, TDA_AA,  DK_S,    DK_R,    DK_T,    DK_G,                               DK_P,    DK_N,    TDE_AE,  DK_I,    TDO_OE,  DK_DQUO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_SFT, DK_X,    DK_V,    DK_W,    DK_D,    DK_J,    XXXXXXX,          TG_GAME, DK_B,    DK_H,    KC_COMM, KC_DOT,  DK_MINS, MO_ADJ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    CTL_CMD, LOW_BSP, KC_SPC,                    KC_ENT,  RSE_TAB, OSM_SFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
    
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     DK_DLR,  DK_AT,   DK_LBRC, DK_RBRC, DK_EXLM, DK_ASTR,                            DK_EQL,  DK_QUES, DK_LPRN, DK_RPRN, DK_SCLN, DK_PERC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     DK_CIRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DK_QUOT, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────| 
     DK_EURO, DK_TILD, DK_LCBR, DK_RCBR, DK_SLSH, DK_PIPE, XXXXXXX,          XXXXXXX, DK_AMPR, DK_BSLS, DK_LABK, DK_RABK, DK_UNDS, DK_HASH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, _______,                   _______, _______, DK_COLN
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     DK_GRV,  KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLU,                            KC_PGUP, KC_HOME, CTL_LFT, CTL_RHT, KC_END,  KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     DK_ACUT, TAB_CLS, TAB_LFT, TAB_RHT, TAB_NEW, KC_VOLD,                            KC_PGDN, KC_UP,   KC_LEFT, KC_RGHT, KC_BSPC, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DK_DIAE, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y), XXXXXXX,          XXXXXXX, KC_CAPS, KC_DOWN, RCS_LFT, RCS_RHT, CTL_BSP, CTL_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC,  _______, _______,                   _______, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, _______, RGB_SAI, RGB_HUI, RGB_VAI, RGB_SPI,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_SPD, XXXXXXX,          QK_BOOT, _______, _______, _______, _______, _______, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,          _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_GAMEFN),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_SPC,  KC_SPC,                    KC_RGUI, KC_ENT,  KC_RALT 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMEFN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case WOKMOK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_WOKMOK);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case ADJUST:
//       if (record->event.pressed) {
//         layer_on(_ADJUST);
//       } else {
//         layer_off(_ADJUST);
//       }
//       return false;
//       break;
//   }
//   return true;
// }

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {               // left encoder (not installed on keeb)
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {  // right encoder
      if (layer_state_is(_WOKMOK)) {
         if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
         } else {
            tap_code(KC_MS_WH_UP);
         }
      } else if (layer_state_is(_LOWER)) {
         if (clockwise) {
            tap_code16(C(KC_TAB));
         } else {
            tap_code16(S(C(KC_TAB)));
         }
      } else if (layer_state_is(_RAISE)) {
         if (clockwise) {
            // tap_code16(RGB_MOD);
            rgb_matrix_step();
         } else {
            // tap_code16(RGB_RMOD);
            rgb_matrix_step_reverse();
         } 
      }
   }
   return false;
}
