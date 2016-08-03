/*	NSRunLoop.h
	Copyright (c) 1994-2015, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>
#import <CoreFoundation/CFRunLoop.h>

@class NSTimer, NSPort, NSArray<ObjectType>, NSString;

NS_ASSUME_NONNULL_BEGIN

// 默认运行模式
FOUNDATION_EXPORT NSString * const NSDefaultRunLoopMode;
// 通用运行模式
FOUNDATION_EXPORT NSString * const NSRunLoopCommonModes NS_AVAILABLE(10_5, 2_0);

// 运行循环对象
@interface NSRunLoop : NSObject {
@private
    id          _rl;
    id          _dperf;
    id          _perft;
    id          _info;
    id		_ports;
    void	*_reserved[6];
}

// 当前运行循环的对象
+ (NSRunLoop *)currentRunLoop;
// 主运行循环对象
+ (NSRunLoop *)mainRunLoop NS_AVAILABLE(10_5, 2_0);

// 当前的模式
@property (nullable, readonly, copy) NSString *currentMode;

// 转换为CFRunLoopRef
- (CFRunLoopRef)getCFRunLoop CF_RETURNS_NOT_RETAINED;

// 向运行循环对象中添加定时器,指定以mode模式运行
- (void)addTimer:(NSTimer *)timer forMode:(NSString *)mode;

// 向运行循环对象中添加,删除端口,指定以mode模式
- (void)addPort:(NSPort *)aPort forMode:(NSString *)mode;
- (void)removePort:(NSPort *)aPort forMode:(NSString *)mode;

// ?
- (nullable NSDate *)limitDateForMode:(NSString *)mode;
- (void)acceptInputForMode:(NSString *)mode beforeDate:(NSDate *)limitDate;

@end

@interface NSRunLoop (NSRunLoopConveniences)

// 开始运行
- (void)run; 
// 直到limitDate再运行
- (void)runUntilDate:(NSDate *)limitDate;
// 在limitDate之前在mode模式下运行
- (BOOL)runMode:(NSString *)mode beforeDate:(NSDate *)limitDate;

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
- (void)configureAsServer NS_DEPRECATED(10_0, 10_5, 2_0, 2_0);
#endif

@end

/**************** 	Delayed perform	 ******************/

// NSObject的延迟执行分类
@interface NSObject (NSDelayedPerforming)

// 延迟delay秒后执行对象的aSelector方法,可携带一个参数anArgument.可指定模式?
- (void)performSelector:(SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay inModes:(NSArray<NSString *> *)modes;
// 延迟delay秒后执行对象的aSelector方法,可携带一个参数anArgument
- (void)performSelector:(SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay;
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(nullable id)anArgument;
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget;

@end

@interface NSRunLoop (NSOrderedPerform)

- (void)performSelector:(SEL)aSelector target:(id)target argument:(nullable id)arg order:(NSUInteger)order modes:(NSArray<NSString *> *)modes;
- (void)cancelPerformSelector:(SEL)aSelector target:(id)target argument:(nullable id)arg;
- (void)cancelPerformSelectorsWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_END
