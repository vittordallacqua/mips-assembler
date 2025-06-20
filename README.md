# MIPS Instruction Simulator in C

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
![C](https://img.shields.io/badge/Built_with-C-blue)

This project is a C-based simulator for a subset of the MIPS (Microprocessor without Interlocked Pipeline Stages) instruction set architecture. Developed as part of the Computer Systems Architecture class, it aims to provide a practical understanding of how MIPS instructions are executed at a low level.

### > <a href="https://www.youtube.com/watch?v=rXakvhSg9VA"> Presentation video (portuguese only) </a> < 

## Project Overview

- **`MIPS.c`**: Contains the main source code implementing the MIPS instruction simulator.
- **`README.md`**: Provides documentation and usage instructions for the project.

## Supported MIPS Instructions

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

## How It Works

1. **Instruction Parsing:**  
   The simulator reads MIPS assembly instructions from an input source, parsing each line to identify the operation and its operands.

2. **Instruction Decoding:**  
   Parsed instructions are decoded to determine the specific operation to perform and the registers or memory addresses involved.

3. **Execution:**  
   The simulator performs the operation, updating the state of registers and memory as needed.

4. **Output:**  
   After execution, the simulator may display the updated state of the registers and memory, depending on the implementation.

## How to Compile and Run

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

*Note: The simulator may require an input file containing MIPS instructions or accept input via standard input. Refer to the source code for specific usage details.*

## License

This project is licensed under the MIT License.
