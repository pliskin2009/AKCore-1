#pragma once

#include "SharedType.h"
#include "GsFunctions.h"



RwUInt32 AcquireSerialId(void)
{
	if(m_uiSerialId++)
	{
		if(m_uiSerialId == 0xffffffff)//INVALID_SERIAL_ID)
			m_uiSerialId = 0;
	}

	return m_uiSerialId;
}


