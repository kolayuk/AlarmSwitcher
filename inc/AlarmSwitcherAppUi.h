/*
========================================================================
 Name        : AlarmSwitcherAppUi.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
#ifndef ALARMSWITCHERAPPUI_H
#define ALARMSWITCHERAPPUI_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknviewappui.h>
// ]]] end generated region [Generated Includes]
#include <AlarmSwitcher_aif.mbg>
// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMainView;
// ]]] end generated region [Generated Forward Declarations]

/**
 * @class	CAlarmSwitcherAppUi AlarmSwitcherAppUi.h
 * @brief The AppUi class handles application-wide aspects of the user interface, including
 *        view management and the default menu, control pane, and status pane.
 */
class CAlarmSwitcherAppUi : public CAknViewAppUi
	{
public: 
	// constructor and destructor
	CAlarmSwitcherAppUi();
	virtual ~CAlarmSwitcherAppUi();
	void ConstructL();
	CGulIcon* LoadIcon(TInt,TInt,TSize size);
public:
	// from CCoeAppUi
	TKeyResponse HandleKeyEventL(
				const TKeyEvent& aKeyEvent,
				TEventCode aType );

	// from CEikAppUi
	void HandleCommandL( TInt aCommand );
	void HandleResourceChangeL( TInt aType );

	// from CAknAppUi
	void HandleViewDeactivation( 
			const TVwsViewId& aViewIdToBeDeactivated, 
			const TVwsViewId& aNewlyActivatedViewId );

private:
	void InitializeContainersL();
	// [[[ begin generated region: do not modify [Generated Methods]
public: 
	// ]]] end generated region [Generated Methods]
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
private: 
	CMainView* iMainView;
	// ]]] end generated region [Generated Instance Variables]
	
	
	// [[[ begin [User Handlers]
protected: 
	// ]]] end [User Handlers]
	
	};

#endif // ALARMSWITCHERAPPUI_H			
