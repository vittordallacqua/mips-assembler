# 🖥️ MIPS.c – MIPS Instruction Simulator in C

This project is a C-based simulator for a subset of the MIPS (Microprocessor without Interlocked Pipeline Stages) instruction set architecture. Developed as part of the *Computer Systems Architecture* course, it aims to provide a practical understanding of how MIPS instructions are executed at a low level.

### 🎥 <a href="https://www.youtube.com/watch?v=rXakvhSg9VA"> Presentation video (portuguese only) </a>

---

## 📚 Project Overview

**Purpose:**  
To simulate the execution of MIPS assembly instructions, facilitating the study of computer architecture concepts such as instruction decoding, register manipulation, and memory operations.

**Technologies Used:**
- **Language:** C
- **Paradigm:** Procedural Programming
- **Platform:** Cross-platform (Linux, macOS, Windows)

---


- **`MIPS.c`**: Contains the main source code implementing the MIPS instruction simulator.
- **`README.md`**: Provides documentation and usage instructions for the project.

---

## 🧠 Supported MIPS Instructions

The simulator supports a subset of MIPS instructions, including:

- **Arithmetic Instructions:**
  - `ADD`, `SUB`, `MUL`, `DIV`
- **Logical Instructions:**
  - `AND`, `OR`, `XOR`, `NOR`
- **Memory Access Instructions:**
  - `LW` (Load Word), `SW` (Store Word)
- **Branch Instructions:**
  - `BEQ` (Branch if Equal), `BNE` (Branch if Not Equal)
- **Jump Instructions:**
  - `J` (Jump), `JR` (Jump Register), `JAL` (Jump and Link)
- **Immediate Instructions:**
  - `ADDI`, `ANDI`, `ORI`, `XORI`

*Note: The actual supported instructions may vary. Please refer to the source code for the complete list.*

---

## ⚙️ How It Works

1. **Instruction Parsing:**  
   The simulator reads MIPS assembly instructions from an input source, parsing each line to identify the operation and its operands.

2. **Instruction Decoding:**  
   Parsed instructions are decoded to determine the specific operation to perform and the registers or memory addresses involved.

3. **Execution:**  
   The simulator performs the operation, updating the state of registers and memory as needed.

4. **Output:**  
   After execution, the simulator may display the updated state of the registers and memory, depending on the implementation.

---

## 🧪 How to Compile and Run

### Prerequisites

- A C compiler (e.g., `gcc`)

### Compilation

Open a terminal in the project directory and run:

```bash
gcc -o mips_simulator MIPS.c
```
This will compile the source code and generate an executable named ```mips_simulator```.

### Execution

Run the simulator using:
```bash
gcc -o mips_simulator MIPS.c
```

```Note: The simulator may require an input file containing MIPS instructions or accept input via standard input.``` <br>
```Refer to the source code for specific usage details.```

---

## 📌 Educational Objectives

- Understanding Instruction Execution:
Learn how individual MIPS instructions are processed, including fetching, decoding, and execution stages.

- Register and Memory Management:
Gain insights into how data is moved and manipulated within the CPU and memory.

- Control Flow:
Study how branching and jumping affect the flow of program execution.

---

## 📎 License

This project is intended for educational purposes and does not have a specified license.


