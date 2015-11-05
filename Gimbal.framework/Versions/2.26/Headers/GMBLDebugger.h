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

@interface GMBLDebugger :  NSObject


/// Enables beacon sighting logs. These logs gives more information about beacon sightings your application
/// is currently seeing.
+ (void)enableBeaconSightingsLogging;

/// Disables beacon sighting logs.
+ (void)disableBeaconSightingsLogging;

/// Gets current state of logging beacon sightings.
+ (BOOL)isBeaconSightingsEnabled;

@end
