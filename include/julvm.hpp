#pragma once

#include <cstdint>

typedef int32_t word;

constexpr word OP_HALT    = 0x0000; // halt machine
constexpr word OP_HCF     = 0x0001; // halt and catch fire
constexpr word OP_FETCH   = 0x0002; // push variable x on stack
constexpr word OP_STORE   = 0x0003; // pop variable x
constexpr word OP_PUSH    = 0x0004; // push const on stack
constexpr word OP_POP     = 0x0005; // pop const
constexpr word OP_INC     = 0x0006; // inc
constexpr word OP_DEC     = 0x0007; // dec
constexpr word OP_ADD     = 0x0008; // add
constexpr word OP_SUB     = 0x0009; // sub
constexpr word OP_MUL     = 0x000A; // mul
constexpr word OP_DIV     = 0x000B; // div
constexpr word OP_MOD     = 0x000C; // mod
constexpr word OP_AND     = 0x000D; // and
constexpr word OP_OR      = 0x000E; // or
constexpr word OP_XOR     = 0x000F; // xor
constexpr word OP_NOT     = 0x0010; // not
constexpr word OP_SHL     = 0x0011; // shl
constexpr word OP_SHR     = 0x0012; // shr
constexpr word OP_JMP     = 0x0013; // jump
constexpr word OP_JZ      = 0x0014; // jump if zero
constexpr word OP_EQ      = 0x0015; // equal
constexpr word OP_NEQ     = 0x0016; // not equal
constexpr word OP_LT      = 0x0017; // less then
constexpr word OP_LEQ     = 0x0018; // less or equal
constexpr word OP_GT      = 0x0019; // great then
constexpr word OP_GEQ     = 0x001A; // great or equal
constexpr word OP_BITAND  = 0x001B; // bit or
constexpr word OP_BITOR   = 0x001C; // bit or
constexpr word OP_BITXOR  = 0x001D; // bit xor
constexpr word OP_CALL    = 0x001E; // call function
constexpr word OP_RET     = 0x001F; // return from function
constexpr word OP_INT     = 0x0020; // interrupt

class VirtualMachine {
  word *Memory;                                     // memory
  word MemoryCapacity;                              // size oif memory
  word IP;                                          // instruction pointer
  word SP;                                          // stack pointer
  word BP;                                          // base pointer
  void interrupt(word Num);                         // programm interrupt

  void operator=(const VirtualMachine &rhs);        // block assign
  VirtualMachine(const VirtualMachine &vm);         // block copy

public:
  VirtualMachine(word _MemoryCapacity = 0xFFFF);
  ~VirtualMachine();
  void run();
  void memoryDumb();
};
