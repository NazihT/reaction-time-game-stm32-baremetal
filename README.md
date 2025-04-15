# reaction-time-game-stm32-baremetal
# STM32 Reaction Time Game (Bare Metal)

A simple reaction time game built entirely in bare-metal C for the STM32 using PlatformIO.

## 🕹️ How It Works

- Press **Button 1** to start.
- After a **random delay** (2–6 seconds), the **red LED turns on**.
- As fast as you can, press **Button 2** when you see the red LED.
- Your reaction time is measured and sent over **UART**.

## ⚙️ Features

- Fully bare-metal (no HAL or libraries)
- Two external interrupts
- Three hardware timers:
  - Random delay generator
  - Reaction time stopwatch
  - Countdown trigger
- UART communication for feedback
- **High score system coming soon**: I plan to add a feature to track and display high scores.
- **LCD display coming soon**: I will be integrating an LCD to display reaction times, scores, and other data alongside UART output.
- **Debouncing with capacitors**: Two capacitors are used to debounce the buttons for more reliable input detection.

## 📁 Structure

