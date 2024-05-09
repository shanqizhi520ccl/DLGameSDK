//
//  NSDictionary+DLExtension.h
//  DLFounction
//
//  Created by 吴涛 on 2023/2/20.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (DLExtension)

/// 对字典的key进行排序
- (NSArray *)dl_alphabetSortedKey;

@end



@interface NSDictionary (DLUrl)

/// 字典传承url的keyValye
- (NSString *)dl_getUrlParamsString;

@end


@interface NSDictionary (DLJson)

/// 字典转json字符串
- (NSString *)dl_toJson;

@end
