# 16-bit Virtual Machine

> Building a custom 16-bit Virtual Machine from scratch in C, starting with an assembler and gradually expanding into a complete CPU emulator.

## Overview

This project is an ongoing implementation of a custom 16-bit Virtual Machine (VM) written in C. The primary objective is to gain a deeper understanding of computer architecture, instruction set design, binary encoding, and low-level systems programming by building every component from the ground up.

The project is being developed incrementally. The current milestone focuses on implementing the assembler, which translates human-readable assembly instructions into binary machine code.

---

## Current Features

### Implemented

- Custom assembly instruction parser
- Opcode generation
- Register encoding
- Immediate value encoding
- Binary instruction generation
- Binary (`.bin`) file output

---

## Supported Instructions

| Instruction | Description |
|------------|-------------|
| `MOV` | Move immediate value or register value |
| `ADD` | Add register or immediate value |
| `SUB` | Subtract register or immediate value |

---

## Register Set

The current architecture supports four general-purpose registers.

| Register | Binary Encoding |
|----------|-----------------|
| R0 | 00 |
| R1 | 01 |
| R2 | 10 |
| R3 | 11 |

---

## Immediate Values

The current instruction format supports immediate values ranging from:

```
0 - 7
```

---

## Example Assembly Program

```asm
MOV R0,5
MOV R2,2
MOV R3,R1
ADD R1,R2
ADD R3,4
```

The assembler converts these instructions into compact binary machine code stored in a `.bin` file.

---

## Instruction Encoding

Each instruction is currently encoded into a single byte using the following format:

```
+--------+--------+-----+--------+
| Opcode | Dest   | Imm | Source |
| 2 bits | 2 bits |1 bit| 3 bits |
+--------+--------+-----+--------+
```

Where:

- **Opcode** identifies the instruction.
- **Destination** specifies the destination register.
- **Immediate Flag** determines whether the source operand is an immediate value or a register.
- **Source** stores either the source register or the immediate value.

---

## Project Structure

```
.
├── assembler.c
├── assembler_functions.c
├── code.txt
├── code.bin
└── README.md
```

---

## Building

Compile the project using GCC.

```bash
gcc assembler.c -o assembler
```

Run the assembler.

```bash
./assembler
```

The generated machine code will be written to:

```
code.bin
```

---

## Current Limitations

This is the first milestone of the project. At the moment:

- Only three instructions are supported (`MOV`, `ADD`, `SUB`).
- Only four registers (`R0`–`R3`) are available.
- Immediate values are limited to **0–7**.
- Labels and branching are not yet implemented.
- No CPU execution or instruction simulation is currently available.

---

## Roadmap

### Phase 1 — Assembler ✅

- [x] Assembly parser
- [x] Opcode generation
- [x] Register encoding
- [x] Immediate value encoding
- [x] Binary file generation

### Phase 2 — CPU Emulator

- [ ] Binary loader
- [ ] Instruction decoder
- [ ] Register execution
- [ ] Program Counter
- [ ] Execution loop

### Phase 3 — Memory System

- [ ] RAM implementation
- [ ] Load and Store instructions
- [ ] Memory addressing

### Phase 4 — ISA Expansion

- [ ] Logical instructions
- [ ] Branch instructions
- [ ] Shift operations
- [ ] Comparison instructions
- [ ] Additional arithmetic operations

### Phase 5 — Stack Support

- [ ] Stack Pointer
- [ ] PUSH
- [ ] POP
- [ ] CALL
- [ ] RET

---

## Motivation

Most modern programming languages abstract away how processors execute instructions. This project explores the complete software execution pipeline by manually implementing an instruction set, assembler, binary encoding, and eventually a CPU emulator.

The long-term goal is to build an educational 16-bit virtual architecture that demonstrates how software interacts with hardware at the lowest level.

---

## Future Work

This assembler is the first component of a larger virtual machine ecosystem. Future updates will introduce a CPU emulator capable of loading and executing the generated machine code, followed by memory management, stack support, branching instructions, and an expanded instruction set.
