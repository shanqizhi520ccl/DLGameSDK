//
//  UIControl+DLExtension.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/2/27.
//

#import <UIKit/UIKit.h>

@interface UIControl (DLExtension)

/// 增加按钮的响应区域
/// - Parameter edge: 区域
- (void)dl_setEnlargeEdge:(UIEdgeInsets )edge;

@end
