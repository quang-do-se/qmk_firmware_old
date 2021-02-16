# MCU name
MCU = STM32F072

# Build Options
#   comment out to disable the options.
#

BOOTMAGIC_ENABLE = lite		# Virtual DIP switch configuration

BACKLIGHT_ENABLE = yes		# Enable keyboard backlight functionality
EXTRAKEY_ENABLE = yes			# Audio control and System control
NKRO_ENABLE = yes					# USB Nkey Rollover

MOUSEKEY_ENABLE = no			# Mouse keys
CONSOLE_ENABLE = no				# Console for debug
COMMAND_ENABLE = no				# Commands for debug and configuration
SLEEP_LED_ENABLE = no			# Breathing sleep LED during USB suspend
CUSTOM_MATRIX = no				# Custom matrix file
BLUETOOTH_ENABLE = no     # Bluetooth support
AUDIO_ENABLE = no         # Audio output
MIDI_ENABLE = no          # MIDI support
FAUXCLICKY_ENABLE = no    # Use buzzer to emulate clicky switches

RGBLIGHT_ENABLE = no      # Disable keyboard RGB underglow
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = spi				# spi or pwm - https://github.com/qmk/qmk_firmware/blob/master/docs/ws2812_driver.md

LAYOUTS = 60_ansi

# Wildcard to allow APM32 MCU
DFU_SUFFIX_ARGS = -p FFFF -v FFFF

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
