# Edge AI-Based Smart EV Charging Station Optimizer

An IoT-enabled smart EV charging station optimization project designed to monitor charging bays, analyze charging conditions at the edge, and support intelligent load management using ESP32 and ThingsBoard.

## Project Overview

As electric vehicle adoption increases, charging stations need efficient load management, real-time monitoring, and protection against electrical overloads.

This project explores an **Edge AI-based EV charging station optimizer** using three simulated charging bays. ESP32-based controllers collect charging-related data and communicate with a ThingsBoard dashboard using MQTT. Edge-side decision logic supports charging optimization and monitoring.

## Key Features

- **Three Charging Bays:** Separate ESP32-based implementations for BAY_1, BAY_2, and BAY_3.
- **Real-Time Monitoring:** Send charging telemetry to ThingsBoard using MQTT.
- **Edge Intelligence:** Incorporate edge-side logic for charging decisions and arrival-probability estimation.
- **Load Optimization:** Support charging decisions based on station load and configured thresholds.
- **Overload Monitoring:** Monitor load conditions and support overload alerts.
- **Hardware Simulation:** Develop and test the ESP32-based system using Wokwi.
- **Remote Monitoring:** Use ThingsBoard for telemetry visualization and device interaction.

## Technologies Used

| Technology | Purpose |
|---|---|
| ESP32 | Embedded controller |
| Arduino/C++ | Firmware development |
| MQTT | Device-to-platform communication |
| ThingsBoard | IoT dashboard and device monitoring |
| Wokwi | ESP32 hardware simulation |
| PlatformIO | Firmware build environment |
| Edge AI | Edge-side intelligent decision logic |

## System Architecture

The project follows this high-level workflow:

1. **Data Collection:** Simulated sensors and user inputs provide charging-related information.
2. **Edge Processing:** The ESP32 firmware processes inputs and evaluates configured conditions.
3. **Optimization Logic:** Charging decisions are made according to the implemented control logic and load thresholds.
4. **Communication:** MQTT transmits telemetry to ThingsBoard.
5. **Monitoring:** The dashboard displays device telemetry and supports remote interaction where implemented.

## Project Structure

```text
Edge_AI_project/
├── README.md
├── .gitignore
├── BAY_1/
│   ├── include/
│   ├── src/
│   ├── test/
│   └── platformio.ini
├── BAY_2/
│   ├── include/
│   ├── src/
│   ├── test/
│   └── platformio.ini
└── BAY_3/
    ├── include/
    ├── src/
    ├── test/
    └── platformio.ini
```

Each bay contains its own firmware project and simulation-related files.

## Development and Simulation

The project uses PlatformIO with the ESP32 Arduino framework and Wokwi for hardware simulation.

To work with a bay:

1. Clone or download this repository.
2. Open the desired bay folder (`BAY_1`, `BAY_2`, or `BAY_3`) in VS Code.
3. Install the PlatformIO IDE extension.
4. Configure the required Wi-Fi and ThingsBoard connection details in a local `config.cpp` file.
5. Build the firmware and launch the Wokwi simulation using the project's configured workflow.
6. Verify telemetry and device connectivity in ThingsBoard.

**Configuration and security:** Use the example configuration as a reference when creating your local `config.cpp`. Provide your own connection details and device access token. Never publish real Wi-Fi passwords, access tokens, or other credentials.

## Learning Outcomes

This project brings together embedded firmware development, IoT communication, hardware simulation, telemetry monitoring, and edge-side decision-making in a multi-bay EV charging use case.

## Future Improvements

- Validate optimization decisions under different station-load scenarios.
- Improve edge-side prediction and decision-making algorithms.
- Add further telemetry analysis and performance evaluation.
- Extend testing to physical hardware and real charging-system requirements.

## Author

**Anjali Sharma**

GitHub: [@anjali-flip](https://github.com/anjali-flip)
