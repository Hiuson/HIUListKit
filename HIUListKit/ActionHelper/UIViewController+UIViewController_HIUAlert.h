//
//  UIViewController+UIViewController_HIUAlert.h
//  HIUListKit
//
//  Created by zhouchun on 2020/5/26.
//  Copyright © 2020 Hiuson. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HIUAlertConstructor;

@interface UIViewController (UIViewController_HIUAlert)

- (HIUAlertConstructor * (^)(NSString * _Nullable content))alert;
- (HIUAlertConstructor * (^)(NSString * _Nullable content))action;

@end

NS_ASSUME_NONNULL_END
