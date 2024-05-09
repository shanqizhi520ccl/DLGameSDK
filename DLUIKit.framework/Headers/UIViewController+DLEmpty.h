//
//  UIViewController+DLEmpty.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/3.
//

#import <UIKit/UIKit.h>

#import <SVGAPlayer/SVGAPlayer.h>

@class SVGAVideoEntity;

@interface UIViewController (DLEmpty)

/// 显示当前的空页面
/// - Parameters:
///   - image: 当前的空页面图片
///   - size: 当前的图片大小size
///   - offset: y轴偏移的量
- (void)dl_showEmptyImage:(UIImage *)image
                imageSize:(CGSize)size
       imageCenterYOffSet:(CGFloat)offset;

/// 显示当前的空页面
/// - Parameters:
///   - image: 当前的空页面图片
///   - size: 当前的图片大小size
///   - emptyMsg: 空页面的文字
///   - offset: y轴偏移的量
- (void)dl_showEmptyImage:(UIImage *)image
                imageSize:(CGSize)size
                 emptyMsg:(NSString *)emptyMsg
       imageCenterYOffSet:(CGFloat)offset;


/// 空页面播放svga动画的的方法
/// - Parameters:
///   - entity: svga播放的实体
///   - size: 当前的size
///   - emptyMsg: 空页面的文字显示
- (void)dl_showEmptyViewAnimation:(SVGAVideoEntity *)entity
                    animationSize:(CGSize)size
                         emptyMsg:(NSString *)emptyMsg;

/// 空页面播放svga动画的的方法
/// - Parameters:
///   - entity: svga播放的实体
///   - size: 当前的size
///   - emptyMsg: 空页面的文字显示
///   - offset: 基于上面的偏移量
///   - msgSpace: msg与icon的间距
- (void)dl_showEmptyViewAnimation:(SVGAVideoEntity *)entity
                    animationSize:(CGSize)size
                         emptyMsg:(NSString *)emptyMsg
               imageCenterYOffSet:(CGFloat)offset
                         msgSpace:(CGFloat)msgSpace;

/// 显示请求页面失败的页面
///   - retry: 重试的block回掉
- (void)dl_showFailedPageRetryBlock:(dispatch_block_t)retry;

/// 显示请求页面失败的页面
///   - retry: 重试的block回掉
///   - offset: y轴偏移的量
- (void)dl_showFailedPageRetryBlock:(dispatch_block_t)retry imageCenterYOffSet:(CGFloat)offset;

/// 隐藏当前的空视图
- (void)dl_hiddenEmpty;

@end
