//
//  UIImageView+DLExtension.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/1.
//

#import <UIKit/UIKit.h>

@interface UIImageView (DLExtension)

/// 设置当前系统资源加载的前置地址
/// - Parameter urlString: 图片地址
+ (void)dl_setImagePreUrl:(NSString *)urlString;

/// 设置网络图片的加载
/// - Parameters:
///   - url: 当前图片的网络地址
///   - placeHolder: 当前图片的展位显示
///   - failedShow: 加载图片失败的显示
- (void)dl_setImageUrl:(NSString *)url
      placeHolderImage:(UIImage *)placeHolder
   downLoadFailedImage:(UIImage *)failedShow;

@end
