//
//  UILocalNotification.h
//  UIKit
//
//  Copyright (c) 2007-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class CLRegion;

// In iOS 8.0 and later, your application must register for user notifications using -[UIApplication registerUserNotificationSettings:] before being able to schedule and present UILocalNotifications
// 本地通知
NS_CLASS_AVAILABLE_IOS(4_0) __TVOS_PROHIBITED @interface UILocalNotification : NSObject<NSCopying, NSCoding>       // added in iOS 4.0

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

// timer-based scheduling
// 触发日期
@property(nullable, nonatomic,copy) NSDate *fireDate;
// the time zone to interpret fireDate in. pass nil if fireDate is an absolute GMT time (e.g. for an egg timer).
// pass a time zone to interpret fireDate as a wall time to be adjusted automatically upon time zone changes (e.g. for an alarm clock).
//通知触发时间参照的时区
@property(nullable, nonatomic,copy) NSTimeZone *timeZone;

// 重复间隔.0表示不重复
@property(nonatomic) NSCalendarUnit repeatInterval;      // 0 means don't repeat
//重复间隔参照的日历
@property(nullable, nonatomic,copy) NSCalendar *repeatCalendar;

// location-based scheduling

// set a CLRegion object to trigger the notification when the user enters or leaves a geographic region, depending upon the properties set on the CLRegion object itself. registering multiple UILocalNotifications with different regions containing the same identifier will result in undefined behavior. the number of region-triggered UILocalNotifications that may be registered at any one time is internally limited. in order to use region-triggered notifications, applications must have "when-in-use" authorization through CoreLocation. see the CoreLocation documentation for more information.
@property(nullable, nonatomic,copy) CLRegion *region NS_AVAILABLE_IOS(8_0);

// when YES, the notification will only fire one time. when NO, the notification will fire every time the region is entered or exited (depending upon the CLRegion object's configuration). default is YES.
@property(nonatomic,assign) BOOL regionTriggersOnce NS_AVAILABLE_IOS(8_0);

// alerts
//本地通知消息体
@property(nullable, nonatomic,copy) NSString *alertBody;      // defaults to nil. pass a string or localized string key to show an alert
//是否显示Action
@property(nonatomic) BOOL hasAction;                // defaults to YES. pass NO to hide launching button/slider
//当设备处于锁屏时,显示在通知的警告框下方的title;会自动加上'滑动来'前缀
@property(nullable, nonatomic,copy) NSString *alertAction;    // used in UIAlert button or 'slide to unlock...' slider in place of unlock
//通过此本地通知启动应用时的启动图
@property(nullable, nonatomic,copy) NSString *alertLaunchImage;   // used as the launch image (UILaunchImageFile) when launch button is tapped
//标题
@property(nullable, nonatomic,copy) NSString *alertTitle NS_AVAILABLE_IOS(8_2);  // defaults to nil. pass a string or localized string key

// sound
//通知声音
@property(nullable, nonatomic,copy) NSString *soundName;      // name of resource in app's bundle to play or UILocalNotificationDefaultSoundName

// badge
//badge图标值
@property(nonatomic) NSInteger applicationIconBadgeNumber;  // 0 means no change. defaults to 0

// user info
//附加信息
@property(nullable, nonatomic,copy) NSDictionary *userInfo;   // throws if contains non-property list types

// category identifer of the local notification, as set on a UIUserNotificationCategory and passed to +[UIUserNotificationSettings settingsForTypes:categories:]
@property (nullable, nonatomic, copy) NSString *category NS_AVAILABLE_IOS(8_0);

@end

//默认通知声音
UIKIT_EXTERN NSString *const UILocalNotificationDefaultSoundName NS_AVAILABLE_IOS(4_0) __TVOS_PROHIBITED;

NS_ASSUME_NONNULL_END
