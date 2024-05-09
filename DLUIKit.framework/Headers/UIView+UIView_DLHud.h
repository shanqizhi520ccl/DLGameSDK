//
//  UIView+UIView_DLHud.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/4/6.
//

#import <UIKit/UIKit.h>

#import "DLHudView.h"

@interface UIView (UIView_DLHud)
///
@property (nonatomic, strong) DLHudView *showHudView;

/// 显示当前视图
- (void)dl_showHud;

/// 隐藏当前loading视图
- (void)dl_dismissHud;

@end
