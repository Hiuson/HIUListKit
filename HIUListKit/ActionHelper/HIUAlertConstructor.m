//
//  HIUAlertConstructor.m
//  HIUListKit
//
//  Created by zhouchun on 2020/5/26.
//  Copyright © 2020 Hiuson. All rights reserved.
//

#import "HIUAlertConstructor.h"
#import "HIUCommon.h"

@interface HIUAlertConstructor ()

@property (nonatomic, weak)   UIViewController *sourceViewController;
@property (nonatomic, strong) UIAlertController *alertController;
@property (nonatomic, strong) NSMutableArray <UIAlertAction *> *actions;

@property (nonatomic, copy)   dispatch_block_t completionBlock;
@property (nonatomic, strong) UIAlertAction *currentAction;
@property (nonatomic, strong) UIAlertAction *preferredAction;

@end

@implementation HIUAlertConstructor

- (instancetype)initWithAlertController:(UIAlertController *)alertController {
    self = [super init];
    if (self) {
        _alertController = alertController;
    }
    return self;
}

- (HIUAlertConstructor * _Nonnull (^)(NSString *content, void (^handler)(UIAlertAction * _Nonnull)))action {
    return [self actionWithStyle:UIAlertActionStyleDefault];
}

- (HIUAlertConstructor * _Nonnull (^)(NSString *content, void (^handler)(UIAlertAction * _Nonnull)))actionWithStyle:(UIAlertActionStyle)preferredStyle {
    return ^HIUAlertConstructor *(NSString *content, void (^handler)(UIAlertAction * _Nonnull)){
        let action = [UIAlertAction actionWithTitle:content style:UIAlertActionStyleDefault handler:handler];
        [self.actions addObject:action];
        self.currentAction = action;
        return self;
    };
}

- (HIUAlertConstructor * (^)(BOOL enabled))enabled {
    return ^HIUAlertConstructor *(BOOL enabled) {
        self.currentAction.enabled = enabled;
        return self;
    };
}

- (HIUAlertConstructor * _Nonnull (^)(void))preferred {
    return ^HIUAlertConstructor *() {
        self.preferredAction = self.currentAction;
        return self;
    };
}

- (HIUAlertConstructor * (^)(dispatch_block_t _Nullable actionBlock))completion {
    return ^HIUAlertConstructor *(dispatch_block_t _Nullable actionBlock) {
        self.completionBlock = actionBlock;
        return self;
    };
}

- (void)present {
    [self.sourceViewController presentViewController:self.alertController animated:YES completion:self.completionBlock];
}

- (NSMutableArray *)actions {
    if (_actions) {
        _actions = NSMutableArray.array;
    }
    return _actions;;
}

@end
