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

@class GMBLBeaconSighting;

@protocol GMBLBeaconManagerDelegate;

/*!
 The GMBLBeaconManager defines the interface for delivering beacon sightings to your Gimbal enabled
 application. You use an instance of this class to start or stop beacon sightings.
 
 In order to use the beacon manager, you must assign a class that conforms to the GMBLBeaconDelegate to the
 delegate property in order to receive beacon sighted events.
 */
@interface GMBLBeaconManager : NSObject

/// The delegate object to receive place events.
@property(weak, nonatomic) id<GMBLBeaconManagerDelegate> delegate;

/// Starts to listen to sightings based on the users proximity to beacons.
- (void)startListening;

/// Stops listening to sightings of nearby beacons.
- (void)stopListening;

@end


/*!
 The GMBLBeaconDelegate protocol defines the methods used to receive events for the GMBLBeaconManager object.
 */
@protocol GMBLBeaconManagerDelegate <NSObject>

/*!
 Tells the delegate that the user has sighted a beacon
 @param sighting
 */
- (void)beaconManager:(GMBLBeaconManager *)manager didReceiveBeaconSighting:(GMBLBeaconSighting *)sighting;

@end
