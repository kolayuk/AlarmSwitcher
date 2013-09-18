/*
========================================================================
 Name        : AlarmSwitcherDocument.cpp
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated User Includes]
#include "AlarmSwitcherDocument.h"
#include "AlarmSwitcherAppUi.h"
// ]]] end generated region [Generated User Includes]

/**
 * @brief Constructs the document class for the application.
 * @param anApplication the application instance
 */
CAlarmSwitcherDocument::CAlarmSwitcherDocument( CEikApplication& anApplication )
	: CAknDocument( anApplication )
	{
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here.  
 */ 
void CAlarmSwitcherDocument::ConstructL()
	{
	}
	
/**
 * Symbian OS two-phase constructor.
 *
 * Creates an instance of CAlarmSwitcherDocument, constructs it, and
 * returns it.
 *
 * @param aApp the application instance
 * @return the new CAlarmSwitcherDocument
 */
CAlarmSwitcherDocument* CAlarmSwitcherDocument::NewL( CEikApplication& aApp )
	{
	CAlarmSwitcherDocument* self = new ( ELeave ) CAlarmSwitcherDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * @brief Creates the application UI object for this document.
 * @return the new instance
 */	
CEikAppUi* CAlarmSwitcherDocument::CreateAppUiL()
	{
	return new ( ELeave ) CAlarmSwitcherAppUi;
	}
				
