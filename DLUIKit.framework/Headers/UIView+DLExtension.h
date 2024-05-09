//
//  UIView+DLExtension.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/2/22.
//

#import <UIKit/UIKit.h>

@interface UIView (DLExtension)
///
@property (nonatomic, strong) UIVisualEffectView *effectView;
///外部线条的layer
@property (nonatomic, strong) CAShapeLayer *borderLineLayer;

/// 添加毛玻璃效果
- (void)dl_addEffectView;

/// 删除毛玻璃效果
- (void)dl_removeEffectView;

/// 为当前视图添加圆角
/// - Parameters:
///   - corener: 当前圆角的设置
///   - size: 圆角的大小
///   - width: 是否设置边框宽度
///   - color: 边框
- (void)dl_setRoundedCorner:(UIRectCorner)corener
                corenerSize:(CGSize)size
                 borderWith:(CGFloat)width
                borderColor:(UIColor *)color;

@end
