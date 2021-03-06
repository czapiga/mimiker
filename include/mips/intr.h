#ifndef _MIPS_INTR_H_
#define _MIPS_INTR_H_

#include <stdbool.h>

/*! \file mips/intr.h */

typedef enum {
  MIPS_SWINT0,
  MIPS_SWINT1,
  MIPS_HWINT0,
  MIPS_HWINT1,
  MIPS_HWINT2,
  MIPS_HWINT3,
  MIPS_HWINT4,
  MIPS_HWINT5,
} mips_intr_t;

typedef struct intr_handler intr_handler_t;
typedef struct exc_frame exc_frame_t;

/*! \brief Disables interrupts by setting SR.IE to 0.
 *
 * \warning Do not use these if you don't know what you're doing!
 * Use \a intr_disable instead.
 *
 * \see intr_enable
 * \see intr_disable
 */
void mips_intr_disable(void);

/*! \brief Enables interrupts by setting SR.IE to 1. */
void mips_intr_enable(void);

/*! \brief Check if interrupts are disabled.
 *
 * Interrupts are enabled when SR.IE = 1 and SR.EXL = 0 and SR.ERL = 0,
 * according to MIPS documentation.
 *
 * The kernel leaves Exception (EXL) or Error Level (ERL) as soon as possible,
 * hence we consider exceptions to be disabled if and only if SR.IE = 0.
 */
bool mips_intr_disabled(void);

void mips_intr_init(void);
void mips_intr_handler(exc_frame_t *frame);
void mips_intr_setup(intr_handler_t *ih, mips_intr_t irq);
void mips_intr_teardown(intr_handler_t *ih);

#endif
