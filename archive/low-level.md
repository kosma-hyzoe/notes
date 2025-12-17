* general purpose registers
* stack pointer (SP) - top of stack
* link register (LR) - function return address, used as a jump back
* PC -> LR
* status register (APSR, IPSR, EPSR) - status and flag information
* program counter (ARM) /instruction pointer (x86) - contains the address of the
  next instruction to execute

* long term mem. -> main mem. -> cache  -> registers
* bus can either pass code through an instruction decoder to arithmetic logic
  unit (ALU) or data that needs to be stored in the registers
* control unit controls what gets done when: either fetching, decoding or
  executing

* interrupts
  * save the state (usually to stack, or use shadow registers)
  * identify the source
  * call a routine (Interrupt Service Routine, ISR)
  * are mapped
  * use no interrupts
  * have no returns
  * irq - interrput request
