//
//  DLShowToastView.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/19.
//

#import <UIKit/UIKit.h>

@interface DLShowToastView : UIView

/// 显示toast
/// - Parameter toast: 当前的toast
- (void)dl_showToast:(NSString *)toast size:(CGSize)toastSize;

/// 显示toast
/// - Parameter toast: 当前的toast
/// - Parameter result: 显示结果
- (void)dl_showToast:(NSString *)toast size:(CGSize)toastSize result:(BOOL)result;

@end
