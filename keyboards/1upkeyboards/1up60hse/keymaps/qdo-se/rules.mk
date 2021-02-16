# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

BOOTMAGIC_ENABLE = lite   # Virtual DIP switch configuration

EXTRAKEY_ENABLE = yes     # Audio control and System control
NKRO_ENABLE = yes         # USB Nkey Rollover. If this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality
MOUSEKEY_ENABLE = no      # Mouse keys
CONSOLE_ENABLE = no       # Console for debug
COMMAND_ENABLE = no       # Commands for debug and configuration
SLEEP_LED_ENABLE = no     # Breathing sleep LED during USB suspend. Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
MIDI_ENABLE = no          # MIDI support
UNICODE_ENABLE = no       # Unicode
BLUETOOTH_ENABLE = no     # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no         # Audio output on port C6
FAUXCLICKY_ENABLE = no    # Use buzzer to emulate clicky switches
EXTRAFLAGS += -flto

LAYOUTS = 60_ansi
