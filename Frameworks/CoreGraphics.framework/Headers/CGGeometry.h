/* CoreGraphics - CGGeometry.h
   Copyright (c) 1998-2011 Apple Inc.
   All rights reserved. */

#ifndef CGGEOMETRY_H_
#define CGGEOMETRY_H_

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <stdint.h>

CF_IMPLICIT_BRIDGING_ENABLED

CF_ASSUME_NONNULL_BEGIN

/* Points. */

// 点
struct CGPoint {
    CGFloat x;
    CGFloat y;
};
typedef struct CGPoint CGPoint;

/* Sizes. */

// 宽高尺寸
struct CGSize {
    CGFloat width;
    CGFloat height;
};
typedef struct CGSize CGSize;

/* Vectors. */

#define CGVECTOR_DEFINED 1

// 矢量
struct CGVector {
    CGFloat dx;
    CGFloat dy;
};
typedef struct CGVector CGVector;

/* Rectangles. */

// 矩形
struct CGRect {
    CGPoint origin;
    CGSize size;
};
typedef struct CGRect CGRect;

/* Rectangle edges. */

// 矩形边枚举
typedef CF_ENUM(uint32_t, CGRectEdge) {
    CGRectMinXEdge, CGRectMinYEdge, CGRectMaxXEdge, CGRectMaxYEdge
};

/* The "zero" point -- equivalent to CGPointMake(0, 0). */ 

// 0点
CG_EXTERN const CGPoint CGPointZero
      CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* The "zero" size -- equivalent to CGSizeMake(0, 0). */ 

// 0尺寸
CG_EXTERN const CGSize CGSizeZero
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* The "zero" rectangle -- equivalent to CGRectMake(0, 0, 0, 0). */ 

// 0矩形
CG_EXTERN const CGRect CGRectZero
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* The "empty" rect. This is the rectangle returned when, for example, we
   intersect two disjoint rectangles. Note that the null rect is not the
   same as the zero rect. */

// ?
CG_EXTERN const CGRect CGRectNull
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* The infinite rectangle. */

CG_EXTERN const CGRect CGRectInfinite
    CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Make a point from `(x, y)'. */

// 创建点
CG_INLINE CGPoint CGPointMake(CGFloat x, CGFloat y);

/* Make a size from `(width, height)'. */

// 创建尺寸
CG_INLINE CGSize CGSizeMake(CGFloat width, CGFloat height);

/* Make a vector from `(dx, dy)'. */

// 穿件矢量
CG_INLINE CGVector CGVectorMake(CGFloat dx, CGFloat dy);

/* Make a rect from `(x, y; width, height)'. */

// 创建矩形
CG_INLINE CGRect CGRectMake(CGFloat x, CGFloat y, CGFloat width,
  CGFloat height);

/* Return the leftmost x-value of `rect'. */

// 矩形在x方向的最小,中间,最大值
CG_EXTERN CGFloat CGRectGetMinX(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the midpoint x-value of `rect'. */

CG_EXTERN CGFloat CGRectGetMidX(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the rightmost x-value of `rect'. */

CG_EXTERN CGFloat CGRectGetMaxX(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the bottommost y-value of `rect'. */

// 矩形在y方向的最小,中间,最大值
CG_EXTERN CGFloat CGRectGetMinY(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the midpoint y-value of `rect'. */

CG_EXTERN CGFloat CGRectGetMidY(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the topmost y-value of `rect'. */

CG_EXTERN CGFloat CGRectGetMaxY(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the width of `rect'. */

// 矩形宽度
CG_EXTERN CGFloat CGRectGetWidth(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the height of `rect'. */

// 矩形高度
CG_EXTERN CGFloat CGRectGetHeight(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `point1' and `point2' are the same, false otherwise. */

//point1与point2是否相等
CG_EXTERN bool CGPointEqualToPoint(CGPoint point1, CGPoint point2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `size1' and `size2' are the same, false otherwise. */

//size1与size2是否相等
CG_EXTERN bool CGSizeEqualToSize(CGSize size1, CGSize size2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `rect1' and `rect2' are the same, false otherwise. */

//rect1与rect2是否相等
CG_EXTERN bool CGRectEqualToRect(CGRect rect1, CGRect rect2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Standardize `rect' -- i.e., convert it to an equivalent rect which has
   positive width and height. */

//将rect中的宽高变为正值
CG_EXTERN CGRect CGRectStandardize(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `rect' is empty (that is, if it has zero width or height),
   false otherwise. A null rect is defined to be empty. */

//rect宽高是否为0
CG_EXTERN bool CGRectIsEmpty(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `rect' is the null rectangle, false otherwise. */

// 是否是null矩形
CG_EXTERN bool CGRectIsNull(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `rect' is the infinite rectangle, false otherwise. */

// 是否是无限矩形
CG_EXTERN bool CGRectIsInfinite(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Inset `rect' by `(dx, dy)' -- i.e., offset its origin by `(dx, dy)', and
   decrease its size by `(2*dx, 2*dy)'. */

CG_EXTERN CGRect CGRectInset(CGRect rect, CGFloat dx, CGFloat dy)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Expand `rect' to the smallest rect containing it with integral origin and
   size. */

CG_EXTERN CGRect CGRectIntegral(CGRect rect)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the union of `r1' and `r2'. */

//并集矩形
CG_EXTERN CGRect CGRectUnion(CGRect r1, CGRect r2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the intersection of `r1' and `r2'. This may return a null rect. */

//交集矩形
CG_EXTERN CGRect CGRectIntersection(CGRect r1, CGRect r2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Offset `rect' by `(dx, dy)'. */

//偏移rect
CG_EXTERN CGRect CGRectOffset(CGRect rect, CGFloat dx, CGFloat dy)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Make two new rectangles, `slice' and `remainder', by dividing `rect' with
   a line that's parallel to one of its sides, specified by `edge' -- either
   `CGRectMinXEdge', `CGRectMinYEdge', `CGRectMaxXEdge', or
   `CGRectMaxYEdge'. The size of `slice' is determined by `amount', which
   measures the distance from the specified edge. */

CG_EXTERN void CGRectDivide(CGRect rect, CGRect *  slice,
    CGRect *  remainder, CGFloat amount, CGRectEdge edge)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `point' is contained in `rect', false otherwise. */

//point点是否在rect内
CG_EXTERN bool CGRectContainsPoint(CGRect rect, CGPoint point)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `rect2' is contained in `rect1', false otherwise. `rect2'
   is contained in `rect1' if the union of `rect1' and `rect2' is equal to
   `rect1'. */

//rect2是否被rect1包含
CG_EXTERN bool CGRectContainsRect(CGRect rect1, CGRect rect2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return true if `rect1' intersects `rect2', false otherwise. `rect1'
   intersects `rect2' if the intersection of `rect1' and `rect2' is not the
   null rect. */

//矩形之间是否有交集
CG_EXTERN bool CGRectIntersectsRect(CGRect rect1, CGRect rect2)
    CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/*** Persistent representations. ***/
// 点,矩形,尺寸与字典之间的转换

/* Return a dictionary representation of `point'. */

CG_EXTERN CFDictionaryRef  CGPointCreateDictionaryRepresentation(
    CGPoint point)
    CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Make a CGPoint from the contents of `dict' (presumably returned earlier
   from `CGPointCreateDictionaryRepresentation') and store the value in
   `point'. Returns true on success; false otherwise. */

CG_EXTERN bool CGPointMakeWithDictionaryRepresentation(
    CFDictionaryRef __nullable dict, CGPoint * __nullable point)
    CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Return a dictionary representation of `size'. */

CG_EXTERN CFDictionaryRef  CGSizeCreateDictionaryRepresentation(CGSize size)
    CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Make a CGSize from the contents of `dict' (presumably returned earlier
   from `CGSizeCreateDictionaryRepresentation') and store the value in
   `size'. Returns true on success; false otherwise. */

CG_EXTERN bool CGSizeMakeWithDictionaryRepresentation(
    CFDictionaryRef __nullable dict, CGSize * __nullable size)
    CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Return a dictionary representation of `rect'. */

CG_EXTERN CFDictionaryRef  CGRectCreateDictionaryRepresentation(CGRect)
    CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Make a CGRect from the contents of `dict' (presumably returned earlier
   from `CGRectCreateDictionaryRepresentation') and store the value in
   `rect'. Returns true on success; false otherwise. */

CG_EXTERN bool CGRectMakeWithDictionaryRepresentation(
    CFDictionaryRef __nullable dict, CGRect * __nullable rect)
    CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/*** Definitions of inline functions. ***/
// 定义一些行间函数

CG_INLINE CGPoint
CGPointMake(CGFloat x, CGFloat y)
{
  CGPoint p; p.x = x; p.y = y; return p;
}

CG_INLINE CGSize
CGSizeMake(CGFloat width, CGFloat height)
{
  CGSize size; size.width = width; size.height = height; return size;
}

CG_INLINE CGVector
CGVectorMake(CGFloat dx, CGFloat dy)
{
  CGVector vector; vector.dx = dx; vector.dy = dy; return vector;
}

CG_INLINE CGRect
CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
  CGRect rect;
  rect.origin.x = x; rect.origin.y = y;
  rect.size.width = width; rect.size.height = height;
  return rect;
}

CG_INLINE bool
__CGPointEqualToPoint(CGPoint point1, CGPoint point2)
{
  return point1.x == point2.x && point1.y == point2.y;
}
#define CGPointEqualToPoint __CGPointEqualToPoint

CG_INLINE bool
__CGSizeEqualToSize(CGSize size1, CGSize size2)
{
  return size1.width == size2.width && size1.height == size2.height;
}

#define CGSizeEqualToSize __CGSizeEqualToSize

CF_ASSUME_NONNULL_END

CF_IMPLICIT_BRIDGING_DISABLED

#endif /* CGGEOMETRY_H_ */
