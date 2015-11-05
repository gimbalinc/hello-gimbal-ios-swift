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

@class GMBLPlace;

/*!
 The GMBLVisit class contains information about a visit to a place. A GMBLVisit 
 begins when a receiver enters a place and ends when the receiver leaves the place.
 */
@interface GMBLVisit : NSObject <NSCopying, NSSecureCoding>

/// Date timestamp when the visit began
@property (readonly, nonatomic) NSDate *arrivalDate;

/// Duration of the current visit
@property (readonly, nonatomic) NSTimeInterval dwellTime;

/// Date timestamp when the visit ended or nil if the visit is still in progress
@property (readonly, nonatomic) NSDate *departureDate;

/// The place associated with the visit
@property (readonly, nonatomic) GMBLPlace *place;

@end
