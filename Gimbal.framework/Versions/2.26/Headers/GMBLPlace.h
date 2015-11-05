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

@class GMBLAttributes;

/*!
 The GMBLPlace class defines a place which is represented by a geofence (circular or polygonal) or a series of beacons.
 A place is defined in the Gimbal Manager portal.
 */
@interface GMBLPlace : NSObject <NSCopying, NSSecureCoding>

/// A unique string identifier that Gimbal generates and assigns to the Place upon creation of the Place
@property (readonly, nonatomic) NSString *identifier;

/// The name for the GMBLPlace, this can be set via the Gimbal Manager
@property (readonly, nonatomic) NSString *name;

/// The attributes for the GMBLPlace, these can be set via the Gimbal Manager
@property (readonly, nonatomic) GMBLAttributes *attributes;

@end
