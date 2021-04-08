#include "STD_TYPES.h"
#include "bit.h"
#include"GIE_Interface.h"
#include"Timer_Interface.h"
#include "RTOS_Private.h"
#include "RTOS_Config.h"
TASK_T systasks[3];
#define TASK_READY 1
#define TASK_SUSPENDED 0
void RTOS_VidCreateTask(u16 Copyperiodicity,u8 copyfirstdelay, u8 priority, void (*pvFunc)(void))
{
	systasks[priority].periodicity=Copyperiodicity;
	systasks[priority].pfun=pvFunc;
systasks[priority].first_delay=	copyfirstdelay;
systasks[priority].state=TASK_READY;

}

void RTOS_voidSchedular(void)
{
	for(i=0;i<3;i++)
	{if(systasks[i].first_delay==0)
		{
			if(systasks[i].state==TASK_READY)
			{
			systasks[i].pfun();
			systasks[i].first_delay=(systasks[i].periodicity)-1;
			}
				else
			systasks[i].first_delay--;
		}
		else
			systasks[i].first_delay--;

}
void RTOS_suspend(u8 priority)
{
	systasks[priority].state=TASK_SUSPENDED;
}
void RTOS_resumed(u8 priority)
{
	systasks[priority].state=TASK_READY;
}
}