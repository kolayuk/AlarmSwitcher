
#ifndef ALARMSWITCHER_PAN_H
#define ALARMSWITCHER_PAN_H

/** AlarmSwitcher application panic codes */
enum TAlarmSwitcherPanics
	{
	EAlarmSwitcherUi = 1
	// add further panics here
	};

inline void Panic(TAlarmSwitcherPanics aReason)
	{
	_LIT(applicationName,"AlarmSwitcher");
	User::Panic(applicationName, aReason);
	}

#endif // ALARMSWITCHER_PAN_H
