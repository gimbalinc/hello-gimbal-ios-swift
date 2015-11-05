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

@class GMBLBeacon;

/*!
 The GMBLBeaconSighting class defines a beacon sighting with beacon attributes defined in GMBLBeacon
 */
@interface GMBLBeaconSighting : NSObject <NSCopying, NSSecureCoding>

/// The rssi value for the beacon sighted
@property (readonly, nonatomic) NSInteger RSSI;

/// The field representing the beacon sighted date
@property (readonly, nonatomic) NSDate *date;

/// The beacon object with beacon attributes
@property (readonly, nonatomic) GMBLBeacon *beacon;

@end
