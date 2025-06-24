/*=============================================================================|
|  PROJECT SnapModbus                                                    1.0.1 |
|==============================================================================|
|  Copyright (C) 2023, 2025 Davide Nardella                                    |
|  All rights reserved.                                                        |
|==============================================================================|
|  SnapModbus is free software: you can redistribute it and/or modify          |
|  it under the terms of the Lesser GNU General Public License as published by |
|  the Free Software Foundation, either version 3 of the License, or           |
|  (at your option) any later version.                                         |
|                                                                              |
|  It means that you can distribute your commercial software linked with       |
|  SnapModbus without the requirement to distribute the source code of your    |
|  application and without the requirement that your application be itself     |
|  distributed under LGPL.                                                     |
|                                                                              |
|  SnapModbus is distributed in the hope that it will be useful,               |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of              |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
|  Lesser GNU General Public License for more details.                         |
|                                                                              |
|  You should have received a copy of the GNU General Public License and a     |
|  copy of Lesser GNU General Public License along with Snap7.                 |
|  If not, see  http://www.gnu.org/licenses/                                   |
|=============================================================================*/
#include "mb_libinterface.h"

#ifndef SNAP_OS_WINDOWS
void libinit(void) __attribute__((constructor));
void libdone(void) __attribute__((destructor));
#endif

static bool libresult = true;

void libinit(void)
{
     // in future expansions here can be inserted some initialization code
#ifdef SNAP_OS_WINDOWS
    timeBeginPeriod(1);
#endif
    libresult=true;
}

void libdone(void)
{
#ifdef SNAP_OS_WINDOWS
    // in future expansions here can be inserted some destruction code
    timeEndPeriod(1);
#endif
}

#ifdef SNAP_OS_WINDOWS
BOOL APIENTRY DllMain (HINSTANCE hInst,
                       DWORD reason,
                       LPVOID reserved)
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        libinit();
        break;
      case DLL_PROCESS_DETACH:
        libdone();
        break;
      case DLL_THREAD_ATTACH:
        break;
      case DLL_THREAD_DETACH:
        break;
    }
    return libresult;
}
#endif
