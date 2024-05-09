//
//  UIViewController+DLHud.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/19.
//

#import <UIKit/UIKit.h>

@class DLHudPresentController;
@interface UIViewController (DLHud)
///尾部刷新视图
@property (nonatomic, strong) DLHudPresentController *hudController;

///显示当前的
- (void)dl_showHud;

///
- (void)dl_dismissHud;

@end
