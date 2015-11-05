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
 The GMBLAttributes class defines a set of attributes defined as string keys and string values.
 */
@interface GMBLAttributes : NSObject <NSCopying, NSSecureCoding>

/*!
 Returns a new array containing the attributes keys
 @result A new array containing the attributes keys, or an empty array if the dictionary has no entries.
 */
- (NSArray *)allKeys;

/*!
 Returns the value associated with a given key.
 @result The value associated with a key, or nil if no value is associated with key.
 */
- (NSString *)stringForKey:(NSString *)key;

@end
