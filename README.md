# ESP32 Marauder Ex

<p align="center"><img alt="Marauder logo" src="https://github.com/justcallmekoko/ESP32Marauder/blob/master/pictures/marauder_skull_patch_04_full_final.png?raw=true" width="300"></p>
<p align="center">

A modification of original ESP32 Marauder to extend its firmware into interfacing with non-touch screens, such as OLED screens of variable sizes, as well as enable button navigation. The other planned features are listed in the **Key Features** section.

## Key features (planned)

- Interfacing with OLED screens of variable sizes.
- Configurable button navigation.
- Wifi Repeater/NAT Router mode.
- Extended support for CLI commands.
- Web UI for general usage
- RF detection/jamming
- Save PMKID/EAPOL capture packets even without WiFi
- USB Tethering

## Building

### Using Arduino IDE

1. Clone the repository
```bash
git clone --recursive https://github.com/execphantasmagoria/ESP32MarauderOLED_BN.git
```

2. Plug in ESP32
3. Open the cloned folder in Arduino IDE
4. Connect it (choose the board and port)
5. Install the following libraries using Library Manager:
    ```
    - ESP32Ping
    - ... will be filled later ...
    ```
6. Verify the build (click the Tick)
7. Flash it
8. Open the Serial Monitor to operate via CLI (optional)

## Contributing

All PRs are welcome.

## License
MIT. Same as original.