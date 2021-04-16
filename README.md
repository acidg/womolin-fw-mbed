# WomoLIN Firmware MBED
Firmware for the WomoLIN Main Unit based on [Mbed](https://os.mbed.com/).

## Build
1. Install the [mbed-cli](https://os.mbed.com/docs/mbed-os/v6.9/quick-start/build-with-mbed-cli.html)
2. Run `mbed compile -m WOMOLIN_V2 -t GCC_ARM`

## Development
You can develop with your favorite IDE by using the export function in mbed.  
`mbed export --supported ides` will give you a list of possible formats.
Use the format which suits your needs an export the configuration:  
`mbed export -i <format> -m WOMOLIN_V2 --profile debug`

Exporting a `Makefile` is also possible:  
`mbed export -i make_gcc_arm -m WOMOLIN_V2 --profile debug`
