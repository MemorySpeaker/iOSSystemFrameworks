/*	NSObject.h
	Copyright (c) 1994-2012, Apple Inc. All rights reserved.
*/

#ifndef _OBJC_NSOBJECT_H_
#define _OBJC_NSOBJECT_H_

#if __OBJC__

#include <objc/objc.h>
#include <objc/NSObjCRuntime.h>

@class NSString, NSMethodSignature, NSInvocation;

@protocol NSObject

// 是否相等
- (BOOL)isEqual:(id)object;
// hash值
@property (readonly) NSUInteger hash;

// 当前对象的父类类对象
@property (readonly) Class superclass;
// 当前对象的类对象.swift中使用'anObject.dynamicType'替代
- (Class)class OBJC_SWIFT_UNAVAILABLE("use 'anObject.dynamicType' instead");
// 所在方法中的对象(实例对象或类对象)
- (instancetype)self;

// 执行aSelector方法(消息)
- (id)performSelector:(SEL)aSelector;
// 执行aSelector方法(消息),可携带一个参数object
- (id)performSelector:(SEL)aSelector withObject:(id)object;
// 执行aSelector方法(消息),可携带两个参数object1,object2
- (id)performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;

// 是否是Proxy
- (BOOL)isProxy;

// 是否为aClass或者aClass子类的实例
- (BOOL)isKindOfClass:(Class)aClass;
//是否为aClass的直接实例
- (BOOL)isMemberOfClass:(Class)aClass;
//是否遵循aProtocol协议
- (BOOL)conformsToProtocol:(Protocol *)aProtocol;

//是否可处理aSelector消息（是否有aSelector方法）
- (BOOL)respondsToSelector:(SEL)aSelector;

/*MRC中使用的手动控制引用计数*/
//引用计数+1
- (instancetype)retain OBJC_ARC_UNAVAILABLE;
//引用计数-1
- (oneway void)release OBJC_ARC_UNAVAILABLE;
//放入自动释放池
- (instancetype)autorelease OBJC_ARC_UNAVAILABLE;
//获取当前引用计数的数值
- (NSUInteger)retainCount OBJC_ARC_UNAVAILABLE;

- (struct _NSZone *)zone OBJC_ARC_UNAVAILABLE;

// 描述信息;当输出某个对象时,默认调用
@property (readonly, copy) NSString *description;
@optional
@property (readonly, copy) NSString *debugDescription;

@end


__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0)
OBJC_ROOT_CLASS
OBJC_EXPORT
@interface NSObject <NSObject> {
    Class isa  OBJC_ISA_AVAILABILITY;
}

// 应用启动时类被加载到内存时调用
+ (void)load;

+ (void)initialize;
//默认内存初始化
- (instancetype)init
#if NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER
    NS_DESIGNATED_INITIALIZER
#endif
    ;

// 等同于alloc+init
+ (instancetype)new OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
// alloc会调用该方法
+ (instancetype)allocWithZone:(struct _NSZone *)zone OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
//申请分配内存
+ (instancetype)alloc OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
//对象内存被销毁时系统自己调用。可以拿来重写，但不要自己手动调用该方法
- (void)dealloc OBJC_SWIFT_UNAVAILABLE("use 'deinit' to define a de-initializer");

- (void)finalize;

// 创建副本
- (id)copy;
- (id)mutableCopy;

+ (id)copyWithZone:(struct _NSZone *)zone OBJC_ARC_UNAVAILABLE;
+ (id)mutableCopyWithZone:(struct _NSZone *)zone OBJC_ARC_UNAVAILABLE;

// 实例是否实现了aSelector方法
+ (BOOL)instancesRespondToSelector:(SEL)aSelector;
// 是否遵循protocol协议
+ (BOOL)conformsToProtocol:(Protocol *)protocol;
- (IMP)methodForSelector:(SEL)aSelector;
+ (IMP)instanceMethodForSelector:(SEL)aSelector;
- (void)doesNotRecognizeSelector:(SEL)aSelector;

- (id)forwardingTargetForSelector:(SEL)aSelector __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
- (void)forwardInvocation:(NSInvocation *)anInvocation OBJC_SWIFT_UNAVAILABLE("");
- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector OBJC_SWIFT_UNAVAILABLE("");

+ (NSMethodSignature *)instanceMethodSignatureForSelector:(SEL)aSelector OBJC_SWIFT_UNAVAILABLE("");

- (BOOL)allowsWeakReference UNAVAILABLE_ATTRIBUTE;
- (BOOL)retainWeakReference UNAVAILABLE_ATTRIBUTE;

//是否为aClass的子类
+ (BOOL)isSubclassOfClass:(Class)aClass;

+ (BOOL)resolveClassMethod:(SEL)sel __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
+ (BOOL)resolveInstanceMethod:(SEL)sel __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

+ (NSUInteger)hash;
+ (Class)superclass;
+ (Class)class OBJC_SWIFT_UNAVAILABLE("use 'aClass.self' instead");
+ (NSString *)description;
+ (NSString *)debugDescription;

@end

#endif

#endif
