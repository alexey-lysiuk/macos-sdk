//
//  AddressBookUI.h
//  AddressBook Framework
//
//  Copyright (c) 2003-2007 Apple Inc.  All rights reserved.
//

#if __OBJC__

#import <AddressBook/ABPeoplePickerView.h>
#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_7
#import <AddressBook/ABPersonView.h>
#endif
#import <AddressBook/ABActions.h>

#else
    #include <AddressBook/ABPeoplePickerC.h>
    #include <AddressBook/ABActionsC.h>
#endif

