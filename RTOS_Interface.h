#ifndef RTOS_Interface_H_
#define RTOS_Interface_H_
void RTOS_VidCreateTask(u16 Copyperiodicity,u8 copyfirstdelay, u8 priority, void (*pvFunc)(void));
void RTOS_voidSchedular(void);
void RTOS_suspend(u8 priority);
void RTOS_resumed(u8 priority);
#endif