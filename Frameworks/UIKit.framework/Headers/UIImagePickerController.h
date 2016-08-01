//
//  UIImagePickerController.h
//  UIKit
//
//  Copyright (c) 2008-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;
@protocol UIImagePickerControllerDelegate;

// 资源类型
typedef NS_ENUM(NSInteger, UIImagePickerControllerSourceType) {
    // 相片库
    UIImagePickerControllerSourceTypePhotoLibrary,
    // 摄像头
    UIImagePickerControllerSourceTypeCamera,
    // 已保存的相册?
    UIImagePickerControllerSourceTypeSavedPhotosAlbum
} __TVOS_PROHIBITED;

// 媒体质量
typedef NS_ENUM(NSInteger, UIImagePickerControllerQualityType) {
    UIImagePickerControllerQualityTypeHigh = 0,       // highest quality
    UIImagePickerControllerQualityTypeMedium = 1,     // medium quality, suitable for transmission via Wi-Fi 
    UIImagePickerControllerQualityTypeLow = 2,         // lowest quality, suitable for tranmission via cellular network
    UIImagePickerControllerQualityType640x480 NS_ENUM_AVAILABLE_IOS(4_0) = 3,    // VGA quality
    UIImagePickerControllerQualityTypeIFrame1280x720 NS_ENUM_AVAILABLE_IOS(5_0) = 4,
    UIImagePickerControllerQualityTypeIFrame960x540 NS_ENUM_AVAILABLE_IOS(5_0) = 5,
} __TVOS_PROHIBITED;

// 摄像头获取资源的模式
typedef NS_ENUM(NSInteger, UIImagePickerControllerCameraCaptureMode) {
    // 拍照
    UIImagePickerControllerCameraCaptureModePhoto,
    // 摄像
    UIImagePickerControllerCameraCaptureModeVideo
} __TVOS_PROHIBITED;

// 摄像设备
typedef NS_ENUM(NSInteger, UIImagePickerControllerCameraDevice) {
    // 后置摄像头
    UIImagePickerControllerCameraDeviceRear,
    // 前置摄像头
    UIImagePickerControllerCameraDeviceFront
} __TVOS_PROHIBITED;

// 闪光灯模式
typedef NS_ENUM(NSInteger, UIImagePickerControllerCameraFlashMode) {
    // 关闭
    UIImagePickerControllerCameraFlashModeOff  = -1,
    // 自动
    UIImagePickerControllerCameraFlashModeAuto = 0,
    // 打开
    UIImagePickerControllerCameraFlashModeOn   = 1
} __TVOS_PROHIBITED;

// info dictionary keys
// 在获取资源后的dict中信息的key值
// 媒体类型
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaType __TVOS_PROHIBITED;      // an NSString (UTI, i.e. kUTTypeImage)
// 原始图片
UIKIT_EXTERN NSString *const UIImagePickerControllerOriginalImage __TVOS_PROHIBITED;  // a UIImage
// 编辑后的图片
UIKIT_EXTERN NSString *const UIImagePickerControllerEditedImage __TVOS_PROHIBITED;    // a UIImage
UIKIT_EXTERN NSString *const UIImagePickerControllerCropRect __TVOS_PROHIBITED;       // an NSValue (CGRect)
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaURL __TVOS_PROHIBITED;       // an NSURL
UIKIT_EXTERN NSString *const UIImagePickerControllerReferenceURL        NS_AVAILABLE_IOS(4_1) __TVOS_PROHIBITED;  // an NSURL that references an asset in the AssetsLibrary framework
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaMetadata       NS_AVAILABLE_IOS(4_1) __TVOS_PROHIBITED;  // an NSDictionary containing metadata from a captured photo
UIKIT_EXTERN NSString *const UIImagePickerControllerLivePhoto NS_AVAILABLE_IOS(9_1) __TVOS_PROHIBITED;  // a PHLivePhoto

// 图片选择控制器
NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UIImagePickerController : UINavigationController <NSCoding>

// sourceType是否可用
+ (BOOL)isSourceTypeAvailable:(UIImagePickerControllerSourceType)sourceType;                 // returns YES if source is available (i.e. camera present)
// 对于sourceType可用的媒体类型
+ (nullable NSArray<NSString *> *)availableMediaTypesForSourceType:(UIImagePickerControllerSourceType)sourceType; // returns array of available media types (i.e. kUTTypeImage)

// 指定的摄像设备是否可用
+ (BOOL)isCameraDeviceAvailable:(UIImagePickerControllerCameraDevice)cameraDevice                   NS_AVAILABLE_IOS(4_0); // returns YES if camera device is available 
// 对于cameraDevice来说闪光灯是否可用
+ (BOOL)isFlashAvailableForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice           NS_AVAILABLE_IOS(4_0); // returns YES if camera device supports flash and torch.
// 对于cameraDevice下可用的资源获取模式
+ (nullable NSArray<NSNumber *> *)availableCaptureModesForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice NS_AVAILABLE_IOS(4_0); // returns array of NSNumbers (UIImagePickerControllerCameraCaptureMode)

// 代理
@property(nullable,nonatomic,weak)      id <UINavigationControllerDelegate, UIImagePickerControllerDelegate> delegate;

// 资源类型,默认UIImagePickerControllerSourceTypePhotoLibrary
@property(nonatomic)           UIImagePickerControllerSourceType     sourceType;                                                        // default value is UIImagePickerControllerSourceTypePhotoLibrary.
// 媒体类型,默认是一个包含kUTTypeImage的数组
@property(nonatomic,copy)      NSArray<NSString *>                   *mediaTypes;
    // default value is an array containing kUTTypeImage.
// 是否允许编辑获取的资源.默认NO.如果设置为YES,会自动切换到系统的编辑
@property(nonatomic)           BOOL                                  allowsEditing NS_AVAILABLE_IOS(3_1);     // replacement for -allowsImageEditing; default value is NO.
// 是否允许编辑图片.3.1后已废弃.使用allowsEditing替代
@property(nonatomic)           BOOL                                  allowsImageEditing NS_DEPRECATED_IOS(2_0, 3_1);

// video properties apply only if mediaTypes includes kUTTypeMovie
// 视频拍摄的最大时长.默认10分钟
@property(nonatomic)           NSTimeInterval                        videoMaximumDuration NS_AVAILABLE_IOS(3_1); // default value is 10 minutes.
// 视频拍摄质量.默认UIImagePickerControllerQualityTypeMedium
@property(nonatomic)           UIImagePickerControllerQualityType    videoQuality NS_AVAILABLE_IOS(3_1);         // default value is UIImagePickerControllerQualityTypeMedium. If the cameraDevice does not support the videoQuality, it will use the default value.

// camera additions available only if sourceType is UIImagePickerControllerSourceTypeCamera.
// 显示相机控制项
@property(nonatomic)           BOOL                                  showsCameraControls NS_AVAILABLE_IOS(3_1);   // set to NO to hide all standard camera UI. default is YES
// 相机预览界面的覆盖层
@property(nullable, nonatomic,strong) __kindof UIView                *cameraOverlayView  NS_AVAILABLE_IOS(3_1);   // set a view to overlay the preview view.
// 对于相机预览界面的形变
@property(nonatomic)           CGAffineTransform                     cameraViewTransform NS_AVAILABLE_IOS(3_1);   // set the transform of the preview view.

// ?
- (void)takePicture NS_AVAILABLE_IOS(3_1);                                                   
// programatically initiates still image capture. ignored if image capture is in-flight.
// clients can initiate additional captures after receiving -imagePickerController:didFinishPickingMediaWithInfo: delegate callback

// 开始,停止录制视频
- (BOOL)startVideoCapture NS_AVAILABLE_IOS(4_0);
- (void)stopVideoCapture  NS_AVAILABLE_IOS(4_0);

// 资源类型,默认UIImagePickerControllerCameraCaptureModePhoto
@property(nonatomic) UIImagePickerControllerCameraCaptureMode cameraCaptureMode NS_AVAILABLE_IOS(4_0); // default is UIImagePickerControllerCameraCaptureModePhoto
// 相机设备,默认UIImagePickerControllerCameraDeviceRear
@property(nonatomic) UIImagePickerControllerCameraDevice      cameraDevice      NS_AVAILABLE_IOS(4_0); // default is UIImagePickerControllerCameraDeviceRear
// 闪光灯模式.默认UIImagePickerControllerCameraFlashModeAuto
@property(nonatomic) UIImagePickerControllerCameraFlashMode   cameraFlashMode   NS_AVAILABLE_IOS(4_0); // default is UIImagePickerControllerCameraFlashModeAuto. 
// cameraFlashMode controls the still-image flash when cameraCaptureMode is Photo. cameraFlashMode controls the video torch when cameraCaptureMode is Video.

@end

// 代理
__TVOS_PROHIBITED @protocol UIImagePickerControllerDelegate<NSObject>
@optional
// The picker does not dismiss itself; the client dismisses it in these callbacks.
// The delegate will receive one or the other, but not both, depending whether the user
// confirms or cancels.
// 选择了image图片.3.0后已废弃
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(nullable NSDictionary<NSString *,id> *)editingInfo NS_DEPRECATED_IOS(2_0, 3_0);
// 选择完媒体数据后调用.在info中包含了所需要的信息
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info;
// 取消按钮被点击时
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker;

@end


// Adds a photo to the saved photos album.  The optional completionSelector should have the form:
//  - (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;
// 将image图片写入到相册中
UIKIT_EXTERN void UIImageWriteToSavedPhotosAlbum(UIImage *image, __nullable id completionTarget, __nullable SEL completionSelector, void * __nullable contextInfo) __TVOS_PROHIBITED;

// Is a specific video eligible to be saved to the saved photos album? 
UIKIT_EXTERN BOOL UIVideoAtPathIsCompatibleWithSavedPhotosAlbum(NSString *videoPath) NS_AVAILABLE_IOS(3_1) __TVOS_PROHIBITED;

// Adds a video to the saved photos album. The optional completionSelector should have the form:
//  - (void)video:(NSString *)videoPath didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;
UIKIT_EXTERN void UISaveVideoAtPathToSavedPhotosAlbum(NSString *videoPath, __nullable id completionTarget, __nullable SEL completionSelector, void * __nullable contextInfo) NS_AVAILABLE_IOS(3_1) __TVOS_PROHIBITED;

NS_ASSUME_NONNULL_END
