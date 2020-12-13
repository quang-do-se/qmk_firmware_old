- `led_setups` controls led patterns to use. It is located in `qmk_firmware/tmk_core/protocol/arm_atsam/md_rgb_matrix_programs.c`
- `LED_GCR_MAX` controls led max brightness. Its value is 165. It is located in `qmk_firmware/keyboards/massdrop/ctrl/config_led.h`
- `gcr_desired` controls led brightness. By default, it equals to `LED_GCR_MAX` and `ISSI3733_GCR_DEFAULT` or 165

