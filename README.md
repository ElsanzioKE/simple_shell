# Simple Shell Project

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

A simple shell implementation in C that provides basic command-line functionality.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Basic shell prompt
- Command execution
- Pipe support
- Redirection support
- Background execution
- Signal handling

## Getting Started

### Prerequisites

- GCC compiler
- Linux-based operating system

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/ElsanzioKE/simple_shell.git
    ```

2. Compile the code:

    ```bash
    cd simple-shell
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    ```

## Usage

1. Run the shell:

    ```bash
    ./simple_shell
    ```

2. Enter commands at the prompt:

    ```bash
    $ ls -l
    ```

    The shell will execute the command and display the output.

## Contributing

Contributions are welcome! Please follow the [Contribution Guidelines](CONTRIBUTING.md) before submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

