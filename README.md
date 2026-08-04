# 16-bit Virtual Machine

A custom 16-bit virtual machine implemented in C, consisting of an assembler and a CPU emulator built around a custom instruction set architecture (ISA). The project demonstrates the complete execution pipeline, from translating assembly source into machine code to executing binary instructions on a software-defined processor.

---

## Overview

This project implements the core components of a simple processor architecture entirely in software.

The assembler parses a custom assembly language and generates a binary executable using a fixed-width 16-bit instruction format. The virtual machine loads the generated binary into memory, decodes each instruction, updates the processor state, and executes the program sequentially.

The objective is to build each architectural component from first principles while maintaining a modular design that can be extended as the instruction set evolves.

---

## Features

### Assembler

- Parses custom assembly source files
- Encodes instructions into a 16-bit machine instruction format
- Supports both register and immediate operands
- Generates executable binary output (`code.bin`)

### Virtual Machine

- Loads machine code into virtual memory
- Sequential instruction fetch and decode
- Software implementation of a program counter (PC)
- 32 general-purpose registers (`R0`–`R31`)
- Status register for processor flags
- Instruction execution engine

---

## Supported Instructions

| Instruction | Description |
|------------|-------------|
| MOV | Move register or immediate value |
| ADD | Addition |
| SUB | Subtraction |
| AND | Bitwise AND |
| OR | Bitwise OR |
| XOR | Bitwise XOR |
| NOT | Bitwise NOT |
| INC | Increment register |
| DEC | Decrement register |
| EQ | Compare two registers and update the status register |

---

## Processor Architecture

### Register File

- 32 General Purpose Registers
- Register names: `R0` – `R31`

### Memory

- 65,536 words of virtual memory

### Program Counter

- Sequential instruction execution using a software program counter.

### Status Register

The processor maintains an 8-bit status register used to store condition flags generated during instruction execution.

---

## Instruction Format

Each instruction occupies 16 bits.

```
 15                     0
+-------+------+---+------+
|Opcode | Dest | I | Src  |
+-------+------+---+------+
   5        5    1    5
```

| Field | Size |
|--------|-----:|
| Opcode | 5 bits |
| Destination Register | 5 bits |
| Immediate Flag | 1 bit |
| Source Register / Immediate | 5 bits |

---

## Example Program

```asm
MOV R0,1
MOV R12,2

ADD R1,R0
ADD R1,R12

INC R3

EQ R0,R3
```

---

## Project Structure

```
.
├── assembler.c
├── assembler_functions.c
├── vm.c
├── program.txt
├── code.bin
└── README.md
```

---

## Build

Compile the assembler

```bash
gcc assembler.c -o assembler
```

Generate machine code

```bash
./assembler
```

Compile the virtual machine

```bash
gcc vm.c -o vm
```

Execute the program

```bash
./vm
```

---

## Design Goals

The implementation emphasizes simplicity, modularity, and explicit control over each stage of instruction execution. Rather than relying on existing processor architectures, the project defines its own instruction set and execution model, making each component—from instruction encoding to register manipulation and memory access—fully transparent and independently extensible.
