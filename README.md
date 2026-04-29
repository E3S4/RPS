# 🪨📄✂️ Rock Paper Scissors (C Terminal Game)

A simple but upgraded command-line Rock Paper Scissors game written in C, featuring animations, a UI-style interface, and a basic adaptive computer opponent.

---

## 🎮 Features

- Player vs Computer gameplay
- Score tracking system
- ASCII battle animation before each round
- Terminal UI-style status box
- Input validation (no crashing on wrong input)
- Adaptive computer opponent (predicts player patterns)
- Clean round-based system
- Replay support until user quits

---

## 🧠 How the AI Works

The computer doesn’t just pick randomly.

It:
- Stores your previous moves
- Detects the most frequently used choice
- Tries to counter your pattern

So if you spam Rock… it adapts.

It’s not real AI, but it *feels* like it is.

---

## 🕹️ How to Run

### Compile:
```bash
gcc main.c -o rps