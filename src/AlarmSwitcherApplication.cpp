/*
========================================================================
 Name        : AlarmSwitcherApplication.cpp
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated System Includes]
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated Includes]
#include "AlarmSwitcherApplication.h"
#include "AlarmSwitcherDocument.h"
#ifdef EKA2
#include <eikstart.h>
#endif
// ]]] end generated region [Generated Includes]

/**
 * @brief Returns the application's UID (override from CApaApplication::AppDllUid())
 * @return UID for this application (KUidAlarmSwitcherApplication)
 */
TUid CAlarmSwitcherApplication::AppDllUid() const
	{
	return KUidAlarmSwitcherApplication;
	}

/**
 * @brief Creates the application's document (override from CApaApplication::CreateDocumentL())
 * @return Pointer to the created document object (CAlarmSwitcherDocument)
 */
CApaDocument* CAlarmSwitcherApplication::CreateDocumentL()
	{
	return CAlarmSwitcherDocument::NewL( *this );
	}

#ifdef EKA2

/**
 *	@brief Called by the application framework to construct the application object
 *  @return The application (CAlarmSwitcherApplication)
 */	
LOCAL_C CApaApplication* NewApplication()
	{
	return new CAlarmSwitcherApplication;
	}

/**
* @brief This standard export is the entry point for all Series 60 applications
* @return error code
 */	
GLDEF_C TInt E32Main()
	{
	return EikStart::RunApplication( NewApplication );
	}
	
#else 	// Series 60 2.x main DLL program code

/**
* @brief This standard export constructs the application object.
* @return The application (CAlarmSwitcherApplication)
*/
EXPORT_C CApaApplication* NewApplication()
	{
	return new CAlarmSwitcherApplication;
	}

/**
* @brief This standard export is the entry point for all Series 60 applications
* @return error code
*/
GLDEF_C TInt E32Dll(TDllReason /*reason*/)
	{
	return KErrNone;
	}

#endif // EKA2
