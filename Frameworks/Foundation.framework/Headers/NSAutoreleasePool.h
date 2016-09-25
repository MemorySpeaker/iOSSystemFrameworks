/*	NSAutoreleasePool.h
	Copyright (c) 1994-2015, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

//自动释放池
//在其自身结束时向池中的所有元素发送一次release消息
NS_AUTOMATED_REFCOUNT_UNAVAILABLE
@interface NSAutoreleasePool : NSObject {
@private
    void	*_token;
    void	*_reserved3;
    void	*_reserved2;
    void	*_reserved;
}

// 添加元素到池中
+ (void)addObject:(id)anObject;
- (void)addObject:(id)anObject;

// 主动向池中所有对象发送一次release消息
- (void)drain;

@end

NS_ASSUME_NONNULL_END
