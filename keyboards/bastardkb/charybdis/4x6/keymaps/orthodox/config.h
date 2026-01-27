#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 16
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 1
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 2000
#endif // POINTING_DEVICE_ENABLE

#define TAPPING_TERM 150
/*#define TAPPING_TERM_PER_KEY*/
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// #define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */
// INFO: breaks ONESHOT_TAP_TOGGLE
// INFO: need to: when press key on first layer, then hold same key for layer
// jump, it will go to that layer, not double press key
// ex: ' 1' - space, space button (num layer), 1
#define QUICK_TAP_TERM 0
