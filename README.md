# 16-Bit Virtual Machine & CPU Emulator

A software-based 16-bit virtual machine written in C, featuring a custom instruction set, assembler, binary instruction encoding, simulated registers and memory, and a fetch-decode-execute execution cycle.

> **Status:** Active development

## Overview

This project implements a simple 16-bit processor architecture entirely in software.

The project consists of two main components:

1. **Assembler** – Parses assembly instructions and converts them into 16-bit binary machine instructions.
2. **Virtual CPU** – Loads the binary instruction stream into simulated code memory, decodes each instruction, and executes it using a register file, program counter, status register, and data memory.

The project was developed to explore instruction set design, binary encoding, CPU execution, memory organization, and low-level programming in C.

---

## Architecture

The virtual processor consists of:

- **Word Size:** 16 bits
- **Registers:** 32 × 16-bit general-purpose registers
- **Program Counter (PC):** 16-bit
- **Status Register:** 8-bit
- **Code Memory:** 32,768 × 16-bit words
- **Data Memory:** 32,768 × 16-bit words
- **Instruction Width:** 16 bits

### Instruction Format

Each instruction is encoded into a fixed-width 16-bit word:

```text
15                 11 10        6 5         0
+-------------------+------------+-+---------+
|      Opcode       | Dest Reg   |I| Operand |
+-------------------+------------+-+---------+
       5 bits            5 bits   1   5 bits
