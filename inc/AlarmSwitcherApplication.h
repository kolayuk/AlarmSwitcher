/*
========================================================================
 Name        : AlarmSwitcherApplication.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
#ifndef ALARMSWITCHERAPPLICATION_H
#define ALARMSWITCHERAPPLICATION_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknapp.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Constants]
const TUid KUidAlarmSwitcherApplication = { 0xEBCF890F };
// ]]] end generated region [Generated Constants]

/**
 *
 * @class	CAlarmSwitcherApplication AlarmSwitcherApplication.h
 * @brief	A CAknApplication-derived class is required by the S60 application 
 *          framework. It is subclassed to create the application's document 
 *          object.
 */
class CAlarmSwitcherApplication : public CAknApplication
	{
private:
	TUid AppDllUid() const;
	CApaDocument* CreateDocumentL();
	
	};
			
#endif // ALARMSWITCHERAPPLICATION_H		
