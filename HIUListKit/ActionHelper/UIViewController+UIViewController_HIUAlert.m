//
//  UIViewController+UIViewController_HIUAlert.m
//  HIUListKit
//
//  Created by zhouchun on 2020/5/26.
//  Copyright © 2020 Hiuson. All rights reserved.
//

#import "UIViewController+UIViewController_HIUAlert.h"
#import "HIUAlertConstructor.h"
#import "HIUCommon.h"

@implementation UIViewController (UIViewController_HIUAlert)

- (HIUAlertConstructor * _Nonnull (^)(NSString *content))alert {
    return [self alertWithStyle:UIAlertControllerStyleAlert];
}

- (HIUAlertConstructor * _Nonnull (^)(NSString *content))action {
    return [self alertWithStyle:UIAlertControllerStyleActionSheet];
}

- (HIUAlertConstructor * _Nonnull (^)(NSString *content))alertWithStyle:(UIAlertControllerStyle)style {
    return ^HIUAlertConstructor *(NSString *content) {
            let alert = [UIAlertController alertControllerWithTitle:content message:nil preferredStyle:style];
        return [[HIUAlertConstructor alloc] initWithAlertController:alert];
    };

}

@end
