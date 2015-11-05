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

/*!
 The GMBLEstablishedLocationManager defines the interface for getting established locations to your Gimbal enabled
 application. You use an instance of this class to start or stop place monitoring.
 
 */

@interface GMBLEstablishedLocationManager : NSObject

/// Starts generation of established locations based on the users locations.
+ (void)startMonitoring;

/// Stops generation of established locations.
+ (void)stopMonitoring;

/// Returns the monitoring state
+ (BOOL)isMonitoring;


/*!
 Get established locations. Returns empty array if established locations aren't generated yet.
 @return NSArray of GMBLEstablishedLocation. The array returned is ordered by score. Higher the score more relevant the established locations is.
 */
+ (NSArray *)establishedLocations;

@end
