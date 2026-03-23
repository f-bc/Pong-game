# 🏓 Pong Game in C++

A classic Pong arcade game built with **C++** and **Raylib**, featuring a responsive player paddle and a CPU opponent with basic AI. Fast, lightweight, and fun — right in your terminal's compiled binary.

---

## 📸 Demo

> _Add a gameplay GIF or screenshot here._
>
> ![Demo Placeholder](assets/demo.gif)
>
> _To record a demo, you can use tools like [ScreenToGif](https://www.screentogif.com/) (Windows) or `peek` (Linux)._

---

## ✨ Features

- 🎮 **Player vs CPU** — Challenge a basic AI opponent that tracks the ball in real time
- 🧠 **CPU AI** — The CPU paddle follows the ball's Y position for a realistic challenge
- 🏆 **Scoring System** — Live score display for both player and CPU on screen
- 🎱 **Ball Physics** — Realistic ball bouncing off walls and paddles
- 🔄 **Auto Reset** — Ball resets to the center after each point is scored
- 🖼️ **Polished Visuals** — Rounded paddles, center court circle, dividing line, and custom color palette
- ⚡ **60 FPS** — Smooth gameplay locked at 60 frames per second

---

## 🛠️ Technologies Used

| Tool        | Purpose                              |
|-------------|--------------------------------------|
| **C++**     | Core game logic and OOP structure    |
| **Raylib**  | Window management, rendering, input  |
| **g++**     | Compilation                          |

---

## 📦 Installation & Setup

### Prerequisites

Make sure you have the following installed:

- A C++ compiler (`g++` recommended)
- [Raylib](https://www.raylib.com/) library

#### Install Raylib

**Ubuntu / Debian:**
```bash
sudo apt update
sudo apt install libraylib-dev
```

**Arch Linux:**
```bash
sudo pacman -S raylib
```

**macOS (via Homebrew):**
```bash
brew install raylib
```

**Windows:**
Download the pre-built binaries from [raylib.com/download](https://www.raylib.com/) and follow the setup guide for your IDE or compiler.

---

### Clone the Repository

```bash
git clone https://github.com/your-username/pong-cpp.git
cd pong-cpp
```

---

### Compile

```bash
g++ -o pong main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

> **Windows users**, replace the linker flags with:
> ```bash
> g++ -o pong.exe main.cpp -lraylib -lopengl32 -lgdi32 -lwinmm
> ```

---

### Run

```bash
./pong
```

---

### Using the Makefile _(optional)_

If you have `make` installed, simply run:

```bash
make        # Build the project
make run    # Build and run
make clean  # Remove the compiled binary
```

---

## 🎮 How to Play

| Key        | Action              |
|------------|---------------------|
| `↑` Arrow  | Move paddle **up**  |
| `↓` Arrow  | Move paddle **down** |
| `Esc`      | Quit the game       |

### Rules

- You control the **right paddle**
- The **CPU** controls the left paddle automatically
- If the ball passes your paddle → **CPU scores**
- If the ball passes the CPU paddle → **You score**
- First to... well, keep playing — there's no win condition yet! _(See Future Improvements)_

---

## 📁 Project Structure

```
pong-cpp/
├── main.cpp          # All game logic (Ball, Paddle, CPU_paddle classes + main loop)
├── Makefile          # Optional build automation
├── assets/
│   └── demo.gif      # Gameplay demo (add your own)
└── README.md         # Project documentation
```

### Code Overview

| Class / Component | Description |
|-------------------|-------------|
| `Ball`            | Handles ball position, movement, wall collisions, and reset logic |
| `Paddle`          | Player-controlled paddle with keyboard input and boundary clamping |
| `CPU_paddle`      | Inherits from `Paddle`; overrides `update()` with AI tracking logic |
| `main()`          | Initializes Raylib window, game objects, runs the game loop |

---

## 🚀 Future Improvements

- [ ] **Win condition** — First to 10 points wins, with a victory screen
- [ ] **Main menu** — Start screen with Play / Quit options
- [ ] **Sound effects** — Ball hit, score, and win sounds using Raylib audio
- [ ] **Difficulty levels** — Adjust CPU speed for Easy / Medium / Hard
- [ ] **2-Player mode** — Second player controls via `W` / `S` keys
- [ ] **Pause menu** — Press `P` to pause and resume
- [ ] **Ball speed scaling** — Ball gradually speeds up each rally for more tension
- [ ] **Visual polish** — Add particle effects on paddle hits and score events

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

- [Raylib](https://www.raylib.com/) — A simple and easy-to-use library to enjoy videogames programming
- Inspired by the original **Pong** (Atari, 1972)
