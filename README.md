# -Snake-Game-in-C
This project is a simple **Snake Game** implemented in **C** using a **linked list** data structure to manage the snake's body. It runs in the **Windows console** and includes basic game logic such as collision detection, fruit generation, and dynamic growth.

---

## 🎮 Gameplay

- Use `W`, `A`, `S`, `D` keys to move the snake (↑ ← ↓ →).
- Eat the `@` fruit to grow and increase your score.
- Avoid colliding with the wall or your own body.
- Press `X` to exit the game anytime.

---

## 🛠️ Features

- Snake body is implemented using a **linked list**
- Real-time keyboard input using `_kbhit()` and `_getch()` from `<conio.h>`
- Uses `gotoxy()` to redraw the screen for smooth gameplay
- Custom structs and modular functions for clean logic
- Fruit generation and dynamic difficulty through speed and growth

---
