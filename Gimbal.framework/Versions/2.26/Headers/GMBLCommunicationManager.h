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
#import <UIKit/UIKit.h>

@class GMBLCommunication;
@class GMBLVisit;

@protocol GMBLCommunicationManagerDelegate;

/*!
 The GMBLCommunicationManager defines the interface for delivering communication events to your Gimbal enabled
 application.
 
 In order to receive communications associated to place entry and exit events, you must assign a class that conforms to
 the GMBLCommunicationManagerDelegate protocol to the delegate property of GMBLCommunicationManager.
 */
@interface GMBLCommunicationManager : NSObject

/// The delegate object to receive communication events.
@property (weak, nonatomic) id<GMBLCommunicationManagerDelegate> delegate;

+ (void)startReceivingCommunications;

+ (void)stopReceivingCommunications;

+ (BOOL)isReceivingCommunications;

/*!
 Used to parse a Gimbal Communication from a remote notification userInfo
 @param userInfo The userInfo object representing the remote notification
 */
+ (GMBLCommunication *)communicationForRemoteNotification:(NSDictionary *)userInfo;

/*!
 Used to parse a Gimbal Communication from a local notification
 @param notification The local notification
 */
+ (GMBLCommunication *)communicationForLocalNotification:(UILocalNotification *)notification;

@end

/*!
 The GMBLCommunicationManagerDelegate protocol defines the methods used to receive events for the
 GMBLCommunicationManager object.
 */
@protocol GMBLCommunicationManagerDelegate <NSObject>

@optional

/*!
 Called when a Gimbal Event (for instance Place Arrival) results in Gimbal Communications retrieved from the Gimbal Manager.
 Any Comminications returned in the result will be posted as a UILocalNotification
 @param manager
 @param communications Communications retrieved from the Gimbal Manager
 @param visit The visit that triggered the communication
 @return An array containing all the GMBLCommunication objects you would like Gimbal to post a UILocalNotification
 */
- (NSArray *)communicationManager:(GMBLCommunicationManager *)manager presentLocalNotificationsForCommunications:(NSArray *)communications forVisit:(GMBLVisit *)visit;

@end