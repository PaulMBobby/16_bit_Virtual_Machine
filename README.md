# 16-bit Virtual Machine

> A custom 16-bit Virtual Machine built entirely in C, featuring a custom Instruction Set Architecture (ISA), assembler, binary encoder, and CPU emulator.

---

## Overview

This project explores the fundamentals of computer architecture by implementing a complete instruction execution pipeline from scratch.

Instead of relying on an existing architecture such as ARM or RISC-V, this project defines a custom Instruction Set Architecture (ISA), develops an assembler to translate assembly code into machine code, and implements a virtual CPU capable of executing the generated instructions.

The project is designed as a long-term educational project and will continue to evolve with additional CPU features, memory management, branching, stack operations, and debugging tools.

---

## Current Features

### Assembler

- Parses custom assembly language
- Converts instructions into 16-bit machine code
- Generates executable binary (`code.bin`)
- Supports register and immediate operands

### CPU Emulator

- Loads binary machine code
- Decodes instructions
- Executes instructions sequentially
- Simulates a register file
- Displays register contents after execution

---

## Supported Instructions

| Instruction | Description |
|------------|-------------|
| MOV | Move data |
| ADD | Addition |
| SUB | Subtraction |
| AND | Bitwise AND |
| OR | Bitwise OR |
| XOR | Bitwise XOR |
| NOT | Bitwise NOT |
| INC | Increment |
| DEC | Decrement |

---

## Register File

The virtual CPU currently provides:

- **32 General Purpose Registers**
- Registers are named:

```
R0 - R31
```

---

## Instruction Format

Each instruction occupies **16 bits**.

```
+-------------+-----------+-----------+-----------+
| Opcode (5)  | Dest (5)  | I (1)     | Source(5) |
+-------------+-----------+-----------+-----------+
```

| Field | Description |
|--------|-------------|
| Opcode | Operation to perform |
| Destination | Destination register |
| Immediate Flag | Indicates register/immediate operand |
| Source | Source register or immediate value |

---

## Example Program

```asm
MOV R0,1
MOV R12,2
ADD R1,R0
ADD R1,R12
INC R3
```

Assembly source is translated into machine code and executed by the virtual CPU.

---

## Project Structure

```
16-bit-virtual-machine
│
├── assembler.c
├── assembler_functions.c
├── binary.c
├── code.txt
├── code.bin
└── README.md
```

---

## How It Works

```
Assembly Source
       │
       ▼
+----------------+
|   Assembler    |
+----------------+
       │
       ▼
16-bit Machine Code
       │
       ▼
+----------------+
|  CPU Emulator  |
+----------------+
       │
       ▼
Instruction Decode
       │
       ▼
Execute on Registers
```

---

## Build

Compile the assembler

```bash
gcc assembler.c -o assembler
```

Run the assembler

```bash
./assembler
```

Compile the emulator

```bash
gcc binary.c -o vm
```

Run the virtual machine

```bash
./vm
```

---

## Current Limitations

This project is still under active development.

Current limitations include:

- No RAM implementation
- No Program Counter abstraction
- No stack support
- No branching or jump instructions
- No labels or symbol table
- No function calls
- No interrupts
- No debugger

---

## Roadmap

### Phase 1 — Instruction Set

- [x] Custom ISA
- [x] 16-bit instruction encoding

### Phase 2 — Assembler

- [x] Assembly parser
- [x] Binary generation

### Phase 3 — CPU Emulator

- [x] Binary loader
- [x] Instruction decoder
- [x] Register execution
- [x] Arithmetic operations
- [x] Logical operations

### Phase 4 — Memory

- [ ] RAM
- [ ] Load/Store instructions
- [ ] Addressing modes

### Phase 5 — Control Flow

- [ ] JMP
- [ ] CMP
- [ ] Conditional branches
- [ ] Loops

### Phase 6 — Stack

- [ ] Stack Pointer
- [ ] PUSH
- [ ] POP
- [ ] CALL
- [ ] RET

### Phase 7 — Advanced Features

- [ ] Debugger
- [ ] Labels
- [ ] Symbol table
- [ ] Memory-mapped I/O
- [ ] Interrupt handling

---

## Motivation

Modern software development often abstracts away the underlying hardware. This project aims to bridge that gap by implementing a complete software-based processor from the ground up.

The objective is to gain practical experience in:

- Instruction Set Architecture (ISA) Design
- Computer Architecture
- Binary Encoding
- CPU Design
- Low-Level Programming
- Systems Programming

---

## Future Goals

The long-term vision is to transform this project into a modular educational virtual computer inspired by real-world processor architectures. Planned enhancements include memory management, control flow instructions, stack operations, debugging capabilities, and a richer instruction set while maintaining a clean and extensible design.
