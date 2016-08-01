/*	NSNotification.h
	Copyright (c) 1994-2015, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

@class NSString, NSDictionary, NSOperationQueue;

NS_ASSUME_NONNULL_BEGIN

/****************	Notifications	****************/

// 通知对象
@interface NSNotification : NSObject <NSCopying, NSCoding>

// 通知名称
@property (readonly, copy) NSString *name;
// 发送通知的对象object
@property (nullable, readonly, retain) id object;
// 通知携带的额外信息userInfo
@property (nullable, readonly, copy) NSDictionary *userInfo;

// 快捷对象实例化方法
- (instancetype)initWithName:(NSString *)name object:(nullable id)object userInfo:(nullable NSDictionary *)userInfo NS_AVAILABLE(10_6, 4_0) NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

// 创建通知的分类
@interface NSNotification (NSNotificationCreation)

// 使用通知名和发送对象创建
+ (instancetype)notificationWithName:(NSString *)aName object:(nullable id)anObject;
// 使用通知名和发送对象创建.但是可以携带自定义的信息aUserInfo
+ (instancetype)notificationWithName:(NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;

//不要使用这个方法初始化,这是一个无效的实例化通知方法.   不作就不会死!
- (instancetype)init /*NS_UNAVAILABLE*/;	/* do not invoke; not a valid initializer for this class */

@end

/****************	Notification Center	****************/

// 通知中心对象
@interface NSNotificationCenter : NSObject {
    @package
    void * __strong _impl;
    void * __strong _callback;
    void *_pad[11];
}

// 获取通知中心单例对象
+ (NSNotificationCenter *)defaultCenter;

// 向通知中心注册监听.当收到anObject发送的aName通知时,调用observer的aSelector方法.如果anObject为空,则表示不限定发送对象.
- (void)addObserver:(id)observer selector:(SEL)aSelector name:(nullable NSString *)aName object:(nullable id)anObject;

// 发送一个通知对象
- (void)postNotification:(NSNotification *)notification;
// 由anObject对象发送一个aName通知.方法内部生成通知对象
- (void)postNotificationName:(NSString *)aName object:(nullable id)anObject;
// 由anObject对象发送一个aName通知,可以携带自定义信息.方法内部生成通知对象
- (void)postNotificationName:(NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;

// 从通知中心移除监听者observer的所有监听
- (void)removeObserver:(id)observer;
// 从通知中心移除监听者observer对anObject发出的aName通知的监听
- (void)removeObserver:(id)observer name:(nullable NSString *)aName object:(nullable id)anObject;

// ?
- (id <NSObject>)addObserverForName:(nullable NSString *)name object:(nullable id)obj queue:(nullable NSOperationQueue *)queue usingBlock:(void (^)(NSNotification *note))block NS_AVAILABLE(10_6, 4_0);
    // The return value is retained by the system, and should be held onto by the caller in
    // order to remove the observer with removeObserver: later, to stop observation.

@end

NS_ASSUME_NONNULL_END
