//
//  DLPhotoBrowersPageControl.h
//  DLUIKitDemo
//
//  Created by 吴涛 on 2023/3/20.
//

#import <UIKit/UIKit.h>

@interface DLPhotoBrowersPageControl : UIView
///总的页码
@property (nonatomic, assign) NSInteger pageCount;
///当前的页码
@property (nonatomic, assign) NSInteger currentPage;

@end
