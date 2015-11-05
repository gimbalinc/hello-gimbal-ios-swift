/**
 * Copyright (C) 2015 Gimbal, Inc. All rights reserved.
 *
 * This software is the confidential and proprietary information of Gimbal, Inc.
 *
 * The following sample code illustrates various aspects of the Gimbal SDK.
 *
 * The sample code herein is provided for your convenience, and has not been
 * tested or designed to work on any particular system configuration. It is
 * provided AS IS and your use of this sample code, whether as provided or
 * with any modification, is at your own risk. Neither Gimbal, Inc.
 * nor any affiliate takes any liability nor responsibility with respect
 * to the sample code, and disclaims all warranties, express and
 * implied, including without limitation warranties on merchantability,
 * fitness for a specified purpose, and against infringement.
 */
#import <Foundation/Foundation.h>

/**
 Defines the status of location services .
 */
typedef NS_ENUM(NSInteger, GMBLLocationStatus) {
    // User has given the application the necessary location permissions for Gimbal
    // to operate correctly.
    GMBLLocationStatusOK,
    // The user is unable to provide the application with the necessary location permissions
    // for Gimbal to operate correctly and the current permissions are insufficent.
    GMBLLocationStatusAdminRestricted,
    // The user has denied the application necessary location permissions for Gimbal to operate
    // correctly
    GMBLLocationStatusNotAuthorizedAlways,
};

/**
 Defines the state of Bluetooth.
 */
typedef NS_ENUM(NSInteger, GMBLBluetoothStatus) {
    // User has given the application the necessary bluetooth permissions for Gimbal
    // to operate correctly.
    GMBLBluetoothStatusOK,
    // The user is unable to provide the application with the necessary bluetooth permissions
    // for Gimbal to operate correctly and the current permissions are insufficent.
    GMBLBluetoothStatusAdminRestricted,
    // The user has denied the application necessary bluetooth permissions for Gimbal to operate
    // correctly
    GMBLBluetoothStatusPoweredOff
};

@protocol GMBLApplicationStatusDelegate;

/**!
 The GMBLServicesState class is designed to find out if services required by
 Gimbal are available from iOS.
 **/
// GMBLApplicationStatus
@interface GMBLApplicationStatus : NSObject

/// Delegate receiving notifications on iOS service state changes
@property (nonatomic, weak) id<GMBLApplicationStatusDelegate> delegate;

/// Retrieves the current authorization state for location
+ (GMBLLocationStatus)locationStatus;

/// Retrieves the current state for Bluetooth
+ (GMBLBluetoothStatus)bluetoothStatus;

/// Returns string containing a problem statement for services required by Gimbal
+ (NSString *)statusDescription;

@end

/**!
 The GMBLServicesStateDelegate protocol defines the methods used to receive events for the
 GMBLServicesState object.
 **/
@protocol GMBLApplicationStatusDelegate <NSObject>

@optional

/**!
 Tells the delegate that location status has changed.
 @param servicesState The services state object reporting the event.
 @param locationAuthorizationStatus The new location authorization status.
 **/
- (void)applicationStatus:(GMBLApplicationStatus *)applicationStatus didChangeLocationStatus:(GMBLLocationStatus)locationStatus;

/**!
 Tells the delegate that bluetooth state has changed.
 @param servicesState The services state object reporting the event.
 @param bluetoothState The new bluetooth state.
 **/
- (void)applicationStatus:(GMBLApplicationStatus *)applicationStatus didChangeBluetoothStatus:(GMBLBluetoothStatus)bluetoothStatus;

@end
