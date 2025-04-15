# STM32 Reaction Time Game (Bare Metal)

A simple reaction time game built entirely in bare-metal C for the STM32 using PlatformIO.

## 🕹️ How It Works

- Press **Button 1** to start.
- After a **random delay** (1.5–5 seconds), the **red LED turns on**.
- As fast as you can, press **Button 2** when you see the red LED.
- Your reaction time is measured and sent over **UART**.

## ⚙️ Features

- Fully bare-metal (no HAL or libraries)
- Two external interrupts
- Three hardware timers:
  - Random delay generator (using a timer's counter value as a seed for randomness)
  - Reaction time stopwatch
  - Countdown trigger
- UART communication for feedback
- **High score system coming soon**: I plan to add a feature to track and display high scores.
- **LCD display coming soon**: I will be integrating an LCD to display reaction times, scores, and other data alongside UART output.
- **Debouncing with capacitors**: Two capacitors are used to debounce the buttons for more reliable input detection.

## 🧠 Implementation Notes

- The **random number generation** was initially attempted using a separate RNG module (`rng.c` and `rng.h`). When it didn’t work as expected, I switched to using a **timer's counter value** as a pseudo-random seed, providing a usable random delay for the game.

## 🎥 Demo

[Add a YouTube link or GIF here if you have one]

## 🛠️ Requirements

- STM32 board 
- PlatformIO
- Serial terminal (e.g., PuTTY, CoolTerm)

## 🧠 Notes

This was built as a first-year  electrical engineering student project to explore embedded systems beyond classwork.  
The goal was to apply raw register-level programming and real-time logic on STM32.
