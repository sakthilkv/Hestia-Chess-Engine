# Hestia Chess Engine

## Overview

Hestia is a high-performance chess engine written in C++, designed to be both powerful and efficient. Named after the Greek goddess of hearth and home, Hestia aims to bring warmth and intelligence to the game of chess through advanced algorithms and a robust architecture. The project is currently under development and is a long-term endeavor, with continuous improvements and optimizations planned over the years.

Work in progress...

## Features

- **Bitboard Representation:** Utilizes bitboards for efficient board representation and manipulation.
- **Advanced Search Algorithms:** Implements sophisticated search techniques like Alpha-Beta pruning.
- **Move Generation:** Efficient move generation and evaluation.
- **Customizable Evaluation Function:** A dynamic evaluation function that can be fine-tuned for different play styles.
- **Multithreading Support:** Leveraging modern C++ concurrency features to enhance performance.
- **Extensible Architecture:** Designed to be modular and extensible, allowing for easy addition of new features and improvements.

## Getting Started

### Prerequisites

- **C++ Compiler:** Ensure you have a modern C++ compiler that supports C++17 or later.
- **CMake:** Build system generator to manage the build process.
- **SFML:** Simple and Fast Multimedia Library for graphical interface (optional, for GUI).

### Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/yourusername/hestia-chess-engine.git
    cd hestia-chess-engine
    ```

2. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the engine:**
    ```sh
    ./hestia
    ```

### Usage

Hestia can be used as a standalone application or integrated with GUI applications that support the UCI (Universal Chess Interface) protocol. Detailed usage instructions and configuration options will be provided in future updates.

## Development Roadmap

- **Phase 1: Core Engine Development**
  - Implement bitboard representation and basic move generation.
  - Develop search algorithms and evaluation function.
  - Optimize performance and ensure stability.

- **Phase 2: Feature Enhancements**
  - Add support for advanced search techniques.
  - Integrate with popular chess GUIs.
  - Introduce multithreading for improved performance.

- **Phase 3: Continuous Improvement**
  - Regularly update and optimize the engine.
  - Expand the evaluation function to cover more complex scenarios.
  - Engage with the community for feedback and contributions.

## Contributing

Contributions to Hestia are welcome and encouraged. Whether you are fixing bugs, adding new features, or improving documentation, your help is valuable. Please read the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines on how to contribute.

## License

Hestia is released under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Thank you for your interest in Hestia. We look forward to your contributions and feedback as we continue to develop this powerful chess engine.
