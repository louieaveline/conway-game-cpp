# conway-game-cpp

A terminal-based implementation of Conway's Game of Life using C++. This project simulates a 2D grid of cells evolving over time based on simple rules, with support for classic patterns and toroidal edge wrapping. Built for learning and demonstration purposes.

---

## 🧠 What is the Game of Life?

The Game of Life is a cellular automaton devised by mathematician John Conway. It's a zero-player simulation: you set the initial state, and the system evolves automatically.

Each cell in the grid can be either **alive** or **dead**, and its state changes according to these rules:

1. Any live cell with 2 or 3 live neighbors survives.
2. Any dead cell with exactly 3 live neighbors becomes alive.
3. All other cells die or remain dead.

---

## 🚀 How to Use

After compiling, run the program and enter the grid configuration in this format:

```
<rows> <cols> <pattern>
```

Or type `help` to list available options.

---

## 🧩 Supported Patterns

| Name             | Type         | Description                                |
|------------------|--------------|--------------------------------------------|
| `glider`         | Spaceship    | A small diagonal repeating pattern         |
| `lwss`           | Spaceship    | Lightweight spaceship                      |
| `blinker`        | Oscillator   | Horizontal/vertical period-2 oscillator    |
| `toad`           | Oscillator   | Offset period-2 oscillator                 |
| `beacon`         | Oscillator   | Dual blinking squares                      |
| `pulsar`         | Oscillator   | Large symmetric period-3 oscillator        |
| `pentadecathlon` | Oscillator   | Period-15 oscillator                       |
| `block`          | Still life   | 2x2 static square                          |
| `boat`           | Still life   | Small stable pattern                       |
| `tub`            | Still life   | Ring-like static pattern                   |

Any unknown pattern name will initialize a random board.

---

## 🖥️ Example Usage

```
20 40 glider
30 60 pulsar
25 25 block
```

---

## 🛠️ Compile Instructions

```bash
g++ main.cpp src/GameOfLife.cpp -o game -std=c++11
```

Then run:

```bash
./game
```

---

## 🧪 Features

- Toroidal grid (edges wrap around)
- Predefined pattern loader
- Real-time terminal animation
- Clean C++ structure with dynamic memory

---

## 📜 License

MIT License — free for personal and educational use.
