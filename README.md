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
```

## run
```
./rps
```
### Controls
---
Input	Action
---
* 1	  Rock
---
* 2	  Paper
---
* 3	  Scissors 
---
* y	  Play again
---
* n	  Quit
---


### Sample Result
```
===== FINAL SCORE =====
Player: 4 | Computer: 6
💀 Computer wins!
```

# yeah… I got cooked.
---

### Future Ideas
* Difficulty modes (easy / hard AI)
* Better prediction (Markov chain system)
* ASCII fighting arena
* Combo / streak system
---

### Built With
* C (no external libraries except standard ones)
* Pure terminal logic
* A bit of chaos and bad decisions
---

### 📌 Note

This project started as a simple Rock Paper Scissors game but slowly turned into a mini AI experiment + terminal game engine.