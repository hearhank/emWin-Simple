/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.28 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIDEMO_Start.c
Purpose     : GUIDEMO initialization
----------------------------------------------------------------------
*/

#include "GUIDEMO.h"

/*********************************************************************
*
*       MainTask
*/
void MainTask(void)
{
#if GUI_WINSUPPORT
    WM_SetCreateFlags(WM_CF_MEMDEV); //自动使用存储设备（必须启用存储设备）
#endif
    GUI_Init();//初始化emWin窗口
#ifdef WIN32
    GUI_SPY_StartServer();
    //GUI_VNC_X_StartServer();
#endif
#if GUI_WINSUPPORT
    WM_MULTIBUF_Enable(1);//启用多缓冲器，以便把所有窗口都重绘了之后再显示。
#endif
    GUIDEMO_Main();
}

/*************************** End of file ****************************/

