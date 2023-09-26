// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
// Teams
// https://support.microsoft.com/en-gb/office/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2
// Zoom
// https://support.zoom.us/hc/en-us/articles/205683899-Hot-keys-and-keyboard-shortcuts
// Skype for Business
// https://support.microsoft.com/en-us/topic/keyboard-shortcuts-in-skype-for-business-42ff538f-67f2-4752-afe8-7169c207f659

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "version.h"
#include "keymap_german.h"

// define layer variable names
#define LTEAMS TO(_LTEAMS)
#define LZOOM TO(_LZOOM)
#define LSKYPE TO(_LSKYPE)
bool lteams_mode = false;
bool lzoom_mode  = false;
bool lskype_mode = false;
enum custom_layers {
    _LTEAMS = 0,
    _LZOOM,
    _LSKYPE,
};

// define combos
enum combos {
    _101_TEAMS_from_TEAMS = 0,
    _101_TEAMS_from_ZOOM,
    _101_TEAMS_from_SKYPE,
    _110_ZOOM_from_TEAMS,
    _110_ZOOM_from_ZOOM,
    _110_ZOOM_from_SKYPE,
    _111_SKYPE_from_TEAMS,
    _111_SKYPE_from_ZOOM,
    _111_SKYPE_from_SKYPE,
};

// Macro Variable Declarations, important to start this type of instatiation with SAFE_RANGE to ensure true compiled keycodes don't interfere with iso encoding
enum {
    QMK_BEST = SAFE_RANGE,
    Teams_Toggle_Mute,
    Teams_Toggle_Video,
    Teams_Screenshare,
    Zoom_Toggle_Mute,
    Zoom_Toggle_Video,
    Zoom_Screenshare,
    Skype_Toggle_Mute,
    Skype_Toggle_Video,
    Skype_Screenshare,
    Layer_LTEAMS,
    Layer_LZOOM,
    Layer_LSKYPE,
};

// Define combos
const uint16_t PROGMEM combo_101_teams_from_teams[] = {Teams_Toggle_Mute, Teams_Screenshare, COMBO_END};
const uint16_t PROGMEM combo_101_teams_from_zoom[]  = {Zoom_Toggle_Mute, Zoom_Screenshare, COMBO_END};
const uint16_t PROGMEM combo_101_teams_from_skype[] = {Skype_Toggle_Mute, Skype_Screenshare, COMBO_END};
const uint16_t PROGMEM combo_110_zoom_from_teams[]  = {Teams_Toggle_Mute, Teams_Toggle_Video, COMBO_END};
const uint16_t PROGMEM combo_110_zoom_from_zoom[]   = {Zoom_Toggle_Mute, Zoom_Toggle_Video, COMBO_END};
const uint16_t PROGMEM combo_110_zoom_from_skype[]  = {Skype_Toggle_Mute, Skype_Toggle_Video, COMBO_END};
const uint16_t PROGMEM combo_111_skype_from_teams[] = {Teams_Toggle_Mute, Teams_Toggle_Video, Teams_Screenshare, COMBO_END};
const uint16_t PROGMEM combo_111_skype_from_zoom[]  = {Zoom_Toggle_Mute, Zoom_Toggle_Video, Zoom_Screenshare, COMBO_END};
const uint16_t PROGMEM combo_111_skype_from_skype[] = {Skype_Toggle_Mute, Skype_Toggle_Video, Skype_Screenshare, COMBO_END};


// Define actions per combo
combo_t key_combos[] = {
    [_101_TEAMS_from_TEAMS] = COMBO(combo_101_teams_from_teams, Layer_LTEAMS),
    [_101_TEAMS_from_ZOOM]  = COMBO(combo_101_teams_from_zoom, Layer_LTEAMS),
    [_101_TEAMS_from_SKYPE] = COMBO(combo_101_teams_from_skype, Layer_LTEAMS),
    [_110_ZOOM_from_TEAMS]  = COMBO(combo_110_zoom_from_teams, Layer_LZOOM),
    [_110_ZOOM_from_ZOOM]   = COMBO(combo_110_zoom_from_zoom, Layer_LZOOM),
    [_110_ZOOM_from_SKYPE]  = COMBO(combo_110_zoom_from_skype, Layer_LZOOM),
    [_111_SKYPE_from_TEAMS] = COMBO(combo_111_skype_from_teams, Layer_LSKYPE),
    [_111_SKYPE_from_ZOOM]  = COMBO(combo_111_skype_from_zoom, Layer_LSKYPE),
    [_111_SKYPE_from_SKYPE] = COMBO(combo_111_skype_from_skype, Layer_LSKYPE),
};

// macro functions, this layout takes standard KC codes, make sure to unregister everything!
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int os = detected_host_os();
    switch (keycode) {
        case Teams_Toggle_Mute:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_LCMD);
                    register_code(KC_LSFT);
                    register_code(KC_M);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    register_code(KC_M);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_M);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCMD);
                } else {
                    unregister_code(KC_M);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case Teams_Toggle_Video:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_LCMD);
                    register_code(KC_LSFT);
                    register_code(KC_O);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    register_code(KC_O);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_O);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCMD);
                } else {
                    unregister_code(KC_O);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case Teams_Screenshare:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_LCMD);
                    register_code(KC_LSFT);
                    register_code(KC_E);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    register_code(KC_E);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_E);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCMD);
                } else {
                    unregister_code(KC_E);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case Zoom_Toggle_Mute:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_LCMD);
                    register_code(KC_LSFT);
                    register_code(KC_A);
                } else {
                    register_code(KC_LALT);
                    register_code(KC_A);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_A);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCMD);
                } else {
                    unregister_code(KC_A);
                    unregister_code(KC_LALT);
                }
            }
            return false;
        case Zoom_Toggle_Video:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_LCMD);
                    register_code(KC_LSFT);
                    register_code(KC_V);
                } else {
                    register_code(KC_LALT);
                    register_code(KC_V);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_V);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCMD);
                } else {
                    unregister_code(KC_V);
                    unregister_code(KC_LALT);
                }
            }
            return false;
        case Zoom_Screenshare:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_LCMD);
                    register_code(KC_LSFT);
                    register_code(KC_S);
                } else {
                    register_code(KC_LALT);
                    register_code(KC_S);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_S);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCMD);
                } else {
                    unregister_code(KC_S);
                    unregister_code(KC_LALT);
                }
            }
            return false;
        case Skype_Toggle_Mute:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_UP);
                    register_code(KC_LCMD);
                    register_code(KC_M);
                } else {
                    register_code(KC_LWIN);
                    register_code(KC_F4);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_M);
                    unregister_code(KC_LCMD);
                    unregister_code(KC_UP);
                } else {
                    unregister_code(KC_F4);
                    unregister_code(KC_LWIN);
                }
            }
            return false;
        case Skype_Toggle_Video:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_UP);
                    register_code(KC_LCMD);
                    register_code(KC_V);
                } else {
                    register_code(KC_LWIN);
                    register_code(KC_F5);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_V);
                    unregister_code(KC_LCMD);
                    unregister_code(KC_UP);
                } else {
                    unregister_code(KC_F5);
                    unregister_code(KC_LWIN);
                }
            }
            return false;
        case Skype_Screenshare:
            if (record->event.pressed) {
                // keydown event
                if (os == OS_MACOS) {
                    register_code(KC_UP);
                    register_code(KC_LCMD);
                    register_code(KC_S);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    register_code(KC_S);
                }
            } else {
                // keyup event
                if (os == OS_MACOS) {
                    unregister_code(KC_S);
                    unregister_code(KC_LCMD);
                    unregister_code(KC_UP);
                } else {
                    unregister_code(KC_S);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case Layer_LTEAMS:
            if (!record->event.pressed) {
                return false;
            }
            set_single_persistent_default_layer(_LTEAMS);
            return false;
        case Layer_LZOOM:
            if (!record->event.pressed) {
                return false;
            }
            set_single_persistent_default_layer(_LZOOM);
            return false;
        case Layer_LSKYPE:
            if (!record->event.pressed) {
                return false;
            }
            set_single_persistent_default_layer(_LSKYPE);
            return false;
        default:
            return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LTEAMS] = LAYOUT(Teams_Toggle_Mute, Teams_Toggle_Video, Teams_Screenshare),
    [_LZOOM]  = LAYOUT(Zoom_Toggle_Mute, Zoom_Toggle_Video, Zoom_Screenshare),
    [_LSKYPE] = LAYOUT(Skype_Toggle_Mute, Skype_Toggle_Video, Skype_Screenshare),
};
