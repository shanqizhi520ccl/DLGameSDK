//
//  UIImage+DLExtension.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/2/24.
//

#import <UIKit/UIKit.h>

@interface UIImage (DLExtension)

/// 设置图片拉伸的受保护范围
/// - Parameters:
///   - cap: 保护范围edg
///   - mode: 当前的模式
- (UIImage *)dl_resizableImageCapInsets:(UIEdgeInsets)cap resizingMode:(UIImageResizingMode)mode;

@end
