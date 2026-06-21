# F1 Race Strategy Simulator

A C++ simulator for Formula 1 race strategy, modelling tyre degradation, pit stop timing, and race pace using real 2024 season data.

## Features

- Tyre compound modelling (Soft / Medium / Hard) with lap-by-lap degradation
- Pit stop strategy simulation (1-stop, 2-stop, undercut/overcut)
- Driver and car performance profiles based on 2024 F1 data
- Track-specific configurations (lap time, pit loss delta, tyre wear rate)
- Race simulation with stint-by-stint output

## Project Structure

```
f1-sim/
├── src/
│   ├── main.cpp        # Entry point
│   ├── race.cpp/h      # Race loop and lap simulation
│   ├── strategy.cpp/h  # Strategy engine and pit stop logic
│   ├── tire.cpp/h      # Tyre compound and degradation model
│   ├── car.h           # Car performance parameters
│   ├── driver.h        # Driver profile definitions
│   ├── track.h         # Track configuration
│   └── api.h           # Data interface (WIP)
├── CMakeLists.txt
└── README.md
```

## Build

```bash
mkdir build && cd build
cmake ..
make
```

## Run

```bash
./build/f1sim
```

## Data

Tyre degradation curves, lap time baselines, and car performance figures are based on 2024 Formula 1 season references. Live data API integration is planned.

## Tech Stack

- **Language:** C++17
- **Build System:** CMake

## Author

[Joe](https://github.com/cybs-joe) — CS student @ BUE, cybersecurity track
