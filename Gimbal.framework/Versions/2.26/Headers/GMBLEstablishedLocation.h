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

@import CoreLocation;

@class GMBLCircle;

/*!
 The GMBLEstablishedLocation class contains information about locations commonly visits by user and is ranked by score value. 
 */
@interface GMBLEstablishedLocation : NSObject <NSCopying, NSSecureCoding>

/// Score of the established location. Higher the score more relevant the location is to the user.
@property (readonly, nonatomic) double score;

/// Boundary of the established location, that has center and radius.
@property (readonly, nonatomic) GMBLCircle *boundary;

@end
