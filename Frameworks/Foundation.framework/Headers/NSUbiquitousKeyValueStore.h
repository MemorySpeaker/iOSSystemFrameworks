/*	NSUbiquitousKeyValueStore.h
	Copyright (c) 2011-2015, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

@class NSArray, NSDictionary<KeyType, ObjectType>, NSData, NSString;

NS_ASSUME_NONNULL_BEGIN

// 云端键值对存储
NS_CLASS_AVAILABLE(10_7, 5_0)
@interface NSUbiquitousKeyValueStore : NSObject {
@private
    id _private1;
    id _private2;
    id _private3;
    void *_private4;
    void *_reserved[3];
    int _daemonWakeToken;
#if DEPLOYMENT_TARGET_MACOSX
    BOOL _disabledSuddenTermination;
#endif
}

//获取单例对象
+ (NSUbiquitousKeyValueStore *)defaultStore;

//获取;设置;删除aKey对应的值
- (nullable id)objectForKey:(NSString *)aKey;
- (void)setObject:(nullable id)anObject forKey:(NSString *)aKey;
- (void)removeObjectForKey:(NSString *)aKey;

//获取aKey对应的相应类型value值,如果aKey不存在或者value不是指定类型返回nil
- (nullable NSString *)stringForKey:(NSString *)aKey;
- (nullable NSArray *)arrayForKey:(NSString *)aKey;
- (nullable NSDictionary<NSString *, id> *)dictionaryForKey:(NSString *)aKey;
- (nullable NSData *)dataForKey:(NSString *)aKey;
- (long long)longLongForKey:(NSString *)aKey;
- (double)doubleForKey:(NSString *)aKey;
- (BOOL)boolForKey:(NSString *)aKey;

//设置aKey的value为指定类型值
- (void)setString:(nullable NSString *)aString forKey:(NSString *)aKey;
- (void)setData:(nullable NSData *)aData forKey:(NSString *)aKey;
- (void)setArray:(nullable NSArray *)anArray forKey:(NSString *)aKey;
- (void)setDictionary:(nullable NSDictionary<NSString *, id> *)aDictionary forKey:(NSString *)aKey;
- (void)setLongLong:(long long)value forKey:(NSString *)aKey;
- (void)setDouble:(double)value forKey:(NSString *)aKey;
- (void)setBool:(BOOL)value forKey:(NSString *)aKey;

//所有keyValue对的字典表示
@property (readonly, copy) NSDictionary<NSString *, id> *dictionaryRepresentation;

//同步内存存储
- (BOOL)synchronize;

@end

//从云端获取到数据的通知
FOUNDATION_EXPORT NSString * const NSUbiquitousKeyValueStoreDidChangeExternallyNotification NS_AVAILABLE(10_7, 5_0);
FOUNDATION_EXPORT NSString * const NSUbiquitousKeyValueStoreChangeReasonKey NS_AVAILABLE(10_7, 5_0);
FOUNDATION_EXPORT NSString * const NSUbiquitousKeyValueStoreChangedKeysKey NS_AVAILABLE(10_7, 5_0);

NS_ENUM(NSInteger) {
    NSUbiquitousKeyValueStoreServerChange NS_ENUM_AVAILABLE(10_7, 5_0),
    NSUbiquitousKeyValueStoreInitialSyncChange NS_ENUM_AVAILABLE(10_7, 5_0),
    NSUbiquitousKeyValueStoreQuotaViolationChange NS_ENUM_AVAILABLE(10_7, 5_0),
    NSUbiquitousKeyValueStoreAccountChange NS_ENUM_AVAILABLE(10_8, 6_0)
};

NS_ASSUME_NONNULL_END
