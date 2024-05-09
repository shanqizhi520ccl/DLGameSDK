//
//  UIButton+DLExtension.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/5/29.
//

#import <UIKit/UIKit.h>

@interface UIButton (DLExtension)


/// 设置当前按钮的状态图片
/// - Parameters:
///   - url: 当前的url
///   - state: 当前的状态
- (void)dl_setButtonImage:(NSString *)url control:(UIControlState)state;

@end
