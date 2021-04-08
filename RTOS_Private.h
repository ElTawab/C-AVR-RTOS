#ifndef _RTOS_Private_H_
#define _RTOS_Private_H_
typedef struct
{
	u16 periodicity;
	void (*pfun)(void);
	u8 first_delay;
	u8 state;
}TASK_T;
#endif