//
//  DLPopuBackgroudView.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/6.
//

#import <UIKit/UIKit.h>

///当前弹出控制器的背景颜色
typedef NS_ENUM(NSInteger,DLPresentBackgroudColor) {
    DLPresentBackgroudColorLight = 0,
    DLPresentBackgroudColorClear = 1,
};

@interface DLPopuBackgroudView : UIView
///
@property (nonatomic, assign) DLPresentBackgroudColor bgColor;
///
@property (nonatomic, strong) UIButton *dismissButton;

@end
