/*
========================================================================
 Name        : AlarmSwitcherAppUi.cpp
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
#include <eikmenub.h>
#include <akncontext.h>
#include <akntitle.h>
#include <AlarmSwitcher.rsg>
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated User Includes]
#include "AlarmSwitcherAppUi.h"
#include "AlarmSwitcher.hrh"
#include "MainView.h"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

#include <asclisession.h>
#include <asshdalarm.h>
#include <w32std.h>
#include <aknsutils.h>
#include <gulicon.h>
#include <akniconutils.h>
#include <bautils.h>
#include <eikapp.h>
//#include <AlarmSwitcher_aif.mbg>

/**
 * Construct the CAlarmSwitcherAppUi instance
 */ 
CAlarmSwitcherAppUi::CAlarmSwitcherAppUi()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * The appui's destructor removes the container from the control
 * stack and destroys it.
 */
CAlarmSwitcherAppUi::~CAlarmSwitcherAppUi()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

// [[[ begin generated function: do not modify
void CAlarmSwitcherAppUi::InitializeContainersL()
	{
	iMainView = CMainView::NewL();
	AddViewL( iMainView );
	SetDefaultViewL( *iMainView );
	}
// ]]] end generated function

/**
 * Handle a command for this appui (override)
 * @param aCommand command id to be handled
 */
void CAlarmSwitcherAppUi::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{ // code to dispatch to the AppUi's menu and CBA commands is generated here
		default:
			break;
		}
	
		
	if ( !commandHandled ) 
		{
		if ( aCommand == EAknSoftkeyExit || aCommand == EEikCmdExit )
			{
			Exit();
			}
		}
	// ]]] end generated region [Generated Code]
	
	}

/** 
 * Override of the HandleResourceChangeL virtual function
 */
void CAlarmSwitcherAppUi::HandleResourceChangeL( TInt aType )
	{
	CAknViewAppUi::HandleResourceChangeL( aType );
	// [[[ begin generated region: do not modify [Generated Code]
	// ]]] end generated region [Generated Code]
	
	}
				
/** 
 * Override of the HandleKeyEventL virtual function
 * @return EKeyWasConsumed if event was handled, EKeyWasNotConsumed if not
 * @param aKeyEvent 
 * @param aType 
 */
TKeyResponse CAlarmSwitcherAppUi::HandleKeyEventL(
		const TKeyEvent& aKeyEvent,
		TEventCode aType )
	{
	// The inherited HandleKeyEventL is private and cannot be called
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	return EKeyWasNotConsumed;
	}

/** 
 * Override of the HandleViewDeactivation virtual function
 *
 * @param aViewIdToBeDeactivated 
 * @param aNewlyActivatedViewId 
 */
void CAlarmSwitcherAppUi::HandleViewDeactivation( 
		const TVwsViewId& aViewIdToBeDeactivated, 
		const TVwsViewId& aNewlyActivatedViewId )
	{
	CAknViewAppUi::HandleViewDeactivation( 
			aViewIdToBeDeactivated, 
			aNewlyActivatedViewId );
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here. 
 */ 
void CAlarmSwitcherAppUi::ConstructL()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	
	BaseConstructL( EAknEnableSkin  | 
					 EAknEnableMSK ); 
	InitializeContainersL();
	// ]]] end generated region [Generated Contents]
	
	RASCliSession session;
	session.Connect();
	RArray<TInt> ids;
	session.GetAlarmIdListL(ids);
	TASShdAlarm tempAlarm;
	TASShdAlarm aAlarmInfo;
	TAlarmStatus newstat;
	TInt MaskID=EMbmAlarmswitcher_aifQgn_menu_alarmswitcher;
	TInt ImageID=EMbmAlarmswitcher_aifQgn_menu_alarmswitcher_mask;
	CEikonEnv::Static()->RootWin().SetOrdinalPosition(-4);
	RWindowGroup* iWinGroup = new (ELeave) RWindowGroup(CEikonEnv::Static()->WsSession());
	iWinGroup->Construct((TUint32)iWinGroup);
    iWinGroup->EnableReceiptOfFocus(EFalse); // Don't capture any key events.
	iWinGroup->SetOrdinalPosition(0, ECoeWinPriorityAlwaysAtFront);
	for (TInt i=0;i<ids.Count();i++)
		{
		TInt err=session.GetAlarmDetails(ids[i],tempAlarm);
		if (err!=KErrNone){continue;}
		if (tempAlarm.Status()==EAlarmStatusDisabled){ImageID=EMbmAlarmswitcher_aifAlarmon; MaskID=EMbmAlarmswitcher_aifAlarmon_mask; newstat=EAlarmStatusEnabled;}
		else {ImageID=EMbmAlarmswitcher_aifAlarmoff;MaskID=EMbmAlarmswitcher_aifAlarmoff_mask;newstat=EAlarmStatusDisabled;}
		tempAlarm.iStatus=newstat;
		session.SetAlarmStatus(ids[i],newstat);
		err=session.GetAlarmDetails(ids[i],tempAlarm);
		RDebug::Print(_L("%d"),i);
		}
	session.Close();
	RWsSprite* iSprite= new (ELeave) RWsSprite(CEikonEnv::Static()->WsSession());
	iSprite->Construct(*iWinGroup,TPoint(0,0),0);
	
	TInt ScrX=CEikonEnv::Static()->ScreenDevice()->SizeInPixels().iWidth;
	TInt ScrY=CEikonEnv::Static()->ScreenDevice()->SizeInPixels().iHeight;
	TInt min=ScrX/2;
	if (ScrX>ScrY){min=ScrY/2;}
	else {min=ScrX/2;}
	TSize size=TSize(min/2,min/2);
	TSpriteMember Member;
	CGulIcon* icon=LoadIcon(ImageID,MaskID,size);
	Member.iBitmap=icon->Bitmap();
	Member.iMaskBitmap=icon->Mask();
	Member.iOffset=TPoint(0,0);
	Member.iInterval=TTimeIntervalMicroSeconds32(60*1000000);
	Member.iInvertMask=EFalse;
	iSprite->AppendMember(Member);
	
	TInt BitX=Member.iBitmap->SizeInPixels().iWidth;
	TInt BitY=Member.iBitmap->SizeInPixels().iHeight;	
		
	iSprite->SetPosition(TPoint(ScrX/2-BitX/2,ScrY/2-BitY/2));
	iSprite->Activate();
	CEikonEnv::Static()->WsSession().Flush();
	User::After(2000000);
	User::Exit(0);
	}
CGulIcon* CAlarmSwitcherAppUi::LoadIcon(TInt aImID, TInt aMskID,TSize size)
	{
	CFbsBitmap* mask;
	CFbsBitmap* icon;
	TBuf<255> KPath;
	KPath.Copy(CEikonEnv::Static()->EikAppUi()->Application()->AppFullName().Left(2));
	KPath.Append(_L("\\resource\\apps\\AlarmSwitcher_aif.mif"));
	RDebug::Print(KPath);
	TBool isfile=BaflUtils::FileExists(CEikonEnv::Static()->FsSession(),KPath);
	AknIconUtils::CreateIconL(icon,mask,KPath,aImID,aMskID);
	AknIconUtils::SetSize(icon,size,EAspectRatioNotPreserved);
	AknIconUtils::SetSize(mask,size,EAspectRatioNotPreserved);
	return CGulIcon::NewL(icon,mask);
	}
