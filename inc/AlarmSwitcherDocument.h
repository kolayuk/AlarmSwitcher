/*
========================================================================
 Name        : AlarmSwitcherDocument.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
#ifndef ALARMSWITCHERDOCUMENT_H
#define ALARMSWITCHERDOCUMENT_H

#include <akndoc.h>
		
class CEikAppUi;

/**
* @class	CAlarmSwitcherDocument AlarmSwitcherDocument.h
* @brief	A CAknDocument-derived class is required by the S60 application 
*           framework. It is responsible for creating the AppUi object. 
*/
class CAlarmSwitcherDocument : public CAknDocument
	{
public: 
	// constructor
	static CAlarmSwitcherDocument* NewL( CEikApplication& aApp );

private: 
	// constructors
	CAlarmSwitcherDocument( CEikApplication& aApp );
	void ConstructL();
	
public: 
	// from base class CEikDocument
	CEikAppUi* CreateAppUiL();
	};
#endif // ALARMSWITCHERDOCUMENT_H
