/* MIT License
 *
 * Copyright (c) 2024 Alexander (@alkuzin)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. */

/**
 * @file  irq.h
 * @brief IRQ (Interrupt Request). Contains definitions related to interrupt handling.
 * 
 * @details This header file includes constants, structures, and functions 
 * related to managing interrupts in the kernel. 
 * 
 * ISR (Interrupt Service Routine). An ISR is a software function or routine that 
 * is executed in response to an interrupt generated by hardware or software.
 * 
 * ISRs are used to manage various types of interrupts, such as hardware interrupts 
 * from devices like keyboards or timers, or software interrupts triggered
 * by specific instructions.
 * 
 * @author Alexander Kuzin (<a href="https://github.com/alkuzin">alkuzin</a>)
 * @date   17.05.2024 
 */

#ifndef _NOS_KERNEL_IRQ_H_
#define _NOS_KERNEL_IRQ_H_

#include <stdint.h>

#include <nos/irq.h>

/** @brief Structure representing interrupt register state */
struct int_reg_s {
    u32 cr2;        ///< Control Register 2
    u32 ds;         ///< Data Segment
    u32 edi;        ///< Destination Index
    u32 esi;        ///< Source Index
    u32 ebp;        ///< Base Pointer
    u32 esp;        ///< Stack Pointer
    u32 ebx;        ///< Base Register
    u32 edx;        ///< Data Register
    u32 ecx;        ///< Counter Register
    u32 eax;        ///< Accumulator Register
    u32 int_no;     ///< Interrupt Number
    u32 err_code;   ///< Error Code
    u32 eip;        ///< Instruction Pointer
    u32 csm;        ///< Code Segment
    u32 eflags;     ///< Flags Register
    u32 useresp;    ///< User Stack Pointer
    u32 ss;         ///< Stack Segment
} __attribute__((packed)); /*Prevent the compiler from optimizing*/

/** @brief Typedef for int_reg_s */
typedef struct int_reg_s int_reg_t;

/** @brief Typedef for IRQ handler function pointer */
typedef void (*irq_handler_t) (int_reg_t *);

/**
 * @brief ISR handler function.
 * 
 * @param [in] regs - given pointer to interrupt register state.
 */
void isr_handler(int_reg_t *regs);

/**
 * @brief IRQ handler function.
 * 
 * @param [in] regs - given pointer to interrupt register state.
 */
void irq_handler(int_reg_t *regs);

/**
 * @brief Install handler for IRQ.
 * 
 * @param [in] irq - given IRQ number.
 * @param [in] handler - given pointer to IRQ handler function.
 */
void irq_install_handler(int irq, irq_handler_t handler);

/**
 * @brief Uninstall handler for IRQ.
 * 
 * @param [in] irq - given IRQ number.
 */
void irq_uninstall_handler(int irq);

/** @brief Declare ISR functions for hardware interrupts 0-31. */
extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);

/** @brief Declare ISR functions for system calls. */
extern void isr128(void);
extern void isr177(void);

/** @brief Declare ISR functions for hardware interrupts 0-15. */
extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);

#endif /* _NOS_KERNEL_IRQ_H_ */