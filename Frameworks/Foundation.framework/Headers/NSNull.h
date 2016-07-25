/*	NSNull.h
	Copyright (c) 1994-2015, Apple Inc. All rights reserved.
*/
/*
 * 由MemorySpeaker维护
 * 联系邮箱:wangnistronger@icloud.com
 * 本文件对应维护地址:
 */

#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

// 空对象,什么也没有,但仍是对象.一些不能使用nil的地方可以使用空对象占位,比如数组中
@interface NSNull : NSObject <NSCopying, NSSecureCoding>

// 实例化一个空对象
+ (NSNull *)null;

@end

NS_ASSUME_NONNULL_END
