//
//  UINib.h
//  UIKit
//
//  Copyright (c) 2008-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN
 
// nib文件对象    
NS_CLASS_AVAILABLE_IOS(4_0) @interface UINib : NSObject 

// If the bundle parameter is nil, the main bundle is used.
// Releases resources in response to memory pressure (e.g. memory warning), reloading from the bundle when necessary.
// 从bundle(nil时默认为mainbundle)中实例化名称为name的nib文件
+ (UINib *)nibWithNibName:(NSString *)name bundle:(nullable NSBundle *)bundleOrNil;

// If the bundle parameter is nil, the main bundle is used.
// 从bundle(nil时默认为mainbundle)中实例化data
+ (UINib *)nibWithData:(NSData *)data bundle:(nullable NSBundle *)bundleOrNil;

// Returns an array containing the top-level objects from the NIB.
// The owner and options parameters may both be nil.
// If the owner parameter is nil, connections to File's Owner are not permitted.
// Options are identical to the options specified with -[NSBundle loadNibNamed:owner:options:]
// 获取nib文件中所有直接对象组成的数组
- (NSArray *)instantiateWithOwner:(nullable id)ownerOrNil options:(nullable NSDictionary *)optionsOrNil;
@end

NS_ASSUME_NONNULL_END
