//
//  DLUIKitResourceConfig.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/24.
//

#import <Foundation/Foundation.h>

@interface DLUIKitResourceConfig : NSObject

/// 获取当前项目中的图片
/// - Parameter image: 当前图片名称
+ (NSString *)getSDKImageUrlPath:(NSString *)image;

/// 获取apng的资源地址
/// - Parameter name: 图片的地址
+ (NSData *)getSDKApngImageName:(NSString *)name;

@end
