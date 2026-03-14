# Generala Game Engine

## 🎲 Overview
This project is a high-fidelity implementation of the classic dice game **Generala**, developed in C. It focuses on structured programming principles, procedural logic, and complex conditional scoring systems.

The engine simulates a competitive environment between a human player and an automated opponent, featuring a multi-round structure and dynamic score tracking.

## 🛠 Technical Features
- **Algorithmic Scoring:** Implements a robust `calculate_score` function to evaluate hand types (Straight, Full House, Four of a Kind, Generala) using frequency-based analysis.
- **Control Flow:** Demonstrates efficient use of pre-test loops and conditional branching to manage game states.
- **Randomization:** Utilizes `stdlib.h` time-seeded random number generation for unbiased dice rolls.
- **User Experience:** Provides a command-line interface (CLI) with input validation and interactive gameplay choices.

## 🧠 Logic & Implementation
As an aspiring researcher in computational logic, I designed this engine to handle:
1. **Decision Trees:** Evaluating whether to hold specific dice to maximize the probability of a higher hand.
2. **State Management:** Tracking scores across multiple rounds and determining turn order based on initial rolls.

## 🚀 How to Run
1. Ensure you have a C compiler (like `gcc`) installed.
2. Clone the repository:
   ```bash
   git clone [https://github.com/Aunrova/Generala-Game-Engine.git](https://github.com/Aunrova/Generala-Game-Engine.git)
3. Compile the code:
gcc main.c -o generala
4. Run the executable:
./generala

Developed by Ahmet Onur Taşgüzen - METU Computer Engineering Student.
