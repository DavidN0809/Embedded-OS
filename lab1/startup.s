.global _Reset
_Reset:
	b Reset_Handler
	b . /* Undefined */
	b . /* SWI */
	b . /* Prefetch Abort */
	b . /* Data Abort */
	b . /* reserved */
	b . /* IRQ */
	b . /* FIQ */
.section .text	
Reset_Handler:
	ldr sp, =stack_top
 	bl c_entry
 	b .
