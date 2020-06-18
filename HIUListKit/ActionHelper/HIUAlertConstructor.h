//
//  HIUAlertConstructor.h
//  HIUListKit
//
//  Created by zhouchun on 2020/5/26.
//  Copyright © 2020 Hiuson. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HIUAlertConstructor : NSObject

- (instancetype)initWithAlertController:(UIAlertController *)alertController;

- (HIUAlertConstructor * (^)(NSString * _Nullable content))message;

- (HIUAlertConstructor * (^)(NSString * _Nullable content, void (^ _Nullable handler)(UIAlertAction *action)))action;
//- (HIUAlertConstructor * (^)(NSString * _Nullable content, dispatch_block_t _Nullable actionBlock))destruct;
//- (HIUAlertConstructor * (^)(NSString * _Nullable content, dispatch_block_t _Nullable actionBlock))cancel;
- (HIUAlertConstructor * (^)(BOOL enabled))enabled;
- (HIUAlertConstructor * (^)(void))preferred;

- (HIUAlertConstructor * (^)(dispatch_block_t _Nullable actionBlock))completion;

- (void)present;


@end

NS_ASSUME_NONNULL_END
