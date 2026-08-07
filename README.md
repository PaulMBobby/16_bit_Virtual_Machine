# 16-Bit Virtual Machine & CPU Emulator

A C-based software implementation of a custom 16-bit processor architecture featuring a standalone assembler, binary instruction encoder, and CPU emulator. Built entirely using the C Standard Library to demonstrate instruction set design, machine code generation, memory organization, and instruction execution through a fetch–decode–execute pipeline.

---

# Overview

The 16-Bit Virtual Machine & CPU Emulator is a modular systems programming project that simulates the core components of a simple processor architecture. The project consists of a custom Instruction Set Architecture (ISA), an assembler that translates assembly programs into executable machine code, and a software CPU capable of decoding and executing binary instructions.

Built entirely without external libraries, the project demonstrates low-level systems programming concepts including instruction encoding, binary file generation, register manipulation, memory management, opcode decoding, and CPU execution flow.

The emulator executes programs through a complete fetch–decode–execute cycle while maintaining separate instruction and data memory, closely mirroring the operation of a physical processor.

---

# Features

## Custom 16-Bit Instruction Set

Implements a custom-designed Instruction Set Architecture (ISA) featuring fixed-width 16-bit instructions with dedicated opcode, register, and operand fields.

Supported instruction categories include:

- Data movement
- Arithmetic operations
- Logical operations
- Comparison instructions
- Memory access instructions

---

## Standalone Assembler

Parses human-readable assembly programs and converts them into executable 16-bit machine instructions.

The assembler performs:

- Opcode translation
- Register encoding
- Immediate operand encoding
- Binary instruction generation
- Machine code output (.bin)

---

## Software CPU Emulator

Implements a software processor capable of executing compiled machine code.

The CPU includes:

- General-purpose register file
- Program Counter (PC)
- Status Register
- Code Memory
- Data Memory

Instructions are executed through a complete fetch–decode–execute pipeline.

---

## Binary Program Loader

Loads compiled binary programs directly into instruction memory before execution.

The emulator reads the generated binary image and initializes the virtual processor without requiring any external runtime.

---

## Memory Organization

Separates program instructions from runtime data using independent memory spaces.

- Code Memory stores executable instructions.
- Data Memory stores runtime variables and application data.

This closely resembles the organization of real embedded processors.

---

## Instruction Decoder

Extracts instruction fields using bitwise operations to decode:

- Opcode
- Destination register
- Immediate flag
- Source register / Immediate value

Decoded instructions are dispatched to their corresponding execution routines.

---

# Project Structure

```text
.
├── assembler.c
├── emulator.c
├── program.asm
├── code.bin
└── README.md
```

### `assembler.c`

Implements the complete assembly pipeline, including:

- Instruction parsing
- Opcode lookup
- Register encoding
- Binary instruction generation
- Executable binary creation

### `emulator.c`

Implements the virtual processor, including:

- Binary loader
- Instruction decoder
- Register file
- Memory subsystem
- Fetch–Decode–Execute loop
- Opcode execution engine

### `program.asm`

Sample assembly program demonstrating the supported instruction set.

### `code.bin`

Generated binary executable produced by the assembler and consumed by the emulator.

---

# Getting Started

## Prerequisites

- GCC or Clang

---

## Compilation

Clone the repository:

```bash
git clone https://github.com/PaulMBobby/16-bit-virtual-machine.git

cd 16-bit-virtual-machine
```

Compile the assembler:

```bash
gcc assembler.c -o assembler
```

Compile the emulator:

```bash
gcc emulator.c -o emulator
```

---

# Usage

Assemble the source program:

```bash
./assembler
```

This generates:

```text
code.bin
```

Execute the generated binary:

```bash
./emulator
```

The emulator loads the binary into instruction memory and executes each instruction until the HALT instruction is encountered.

---

# Execution Pipeline

```text
Assembly Program (.asm)
          │
          ▼
     Instruction Parser
          │
          ▼
     Machine Code Encoder
          │
          ▼
      Binary Image (.bin)
          │
          ▼
     Binary Program Loader
          │
          ▼
 Instruction Memory
          │
          ▼
 Fetch → Decode → Execute
          │
          ▼
 Register & Memory Updates
```

---

# Technologies Used

- C
- C Standard Library
- Binary File I/O
- Bitwise Operations
- Systems Programming
- Command-Line Interface (CLI)

---

# Concepts Demonstrated

- Computer Architecture
- Instruction Set Architecture (ISA) Design
- Assembler Design
- Binary Encoding
- Opcode Decoding
- Register-Based Computing
- Memory Organization
- Fetch–Decode–Execute Cycle
- Binary File Processing
- Bit Manipulation
- Modular Software Architecture
- Low-Level Systems Programming

---

# Current Instruction Set

| Category | Instructions |
|----------|--------------|
| Data Transfer | MOV |
| Arithmetic | ADD, SUB, INC, DEC |
| Logical | AND, OR, XOR, NOT |
| Comparison | EQ |
| Memory | LOAD, STORE |

---

# Sample Assembly Program

```assembly
MOV R0,1
MOV R12,2
ADD R1,R0
ADD R1,R12
INC R3
EQ R0,R3
MOV R3,15
MOV R4,5
STORE R3,R4
LOAD R2,R3
HALT
```

---

# Future Improvements

- Conditional branching instructions
- Function call and stack support
- Interrupt handling
- Label resolution
- Macro support
- Multi-pass assembler
- Debugger with breakpoints
- Memory-mapped I/O
- Pipeline simulation
- Cache simulation

---

# License

This project is intended for educational purposes to explore computer architecture, assembler design, and low-level systems programming.
