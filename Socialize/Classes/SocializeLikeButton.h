//
//  SocializeLikeButton.h
//  SocializeSDK
//
//  Created by Nathaniel Griswold on 4/16/12.
//  Copyright (c) 2012 Socialize, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Socialize.h"

@interface SocializeLikeButton : UIView <SocializeServiceDelegate>

@property (nonatomic, retain) UIButton *actualButton;

@property (nonatomic, retain) Socialize *socialize;
@property (nonatomic, retain) id<SocializeEntity> entity;

@property (nonatomic, assign) BOOL initialized;
@property (nonatomic, readonly) BOOL liked;

@property (nonatomic, retain) UIImage *disabledImage;

@property (nonatomic, retain) UIImage *inactiveImage;
@property (nonatomic, retain) UIImage *inactiveHighlightedImage;

@property (nonatomic, retain) UIImage *activeImage;
@property (nonatomic, retain) UIImage *activeHighlightedImage;

@property (nonatomic, retain) UIImage *likeIcon;

- (id)initWithFrame:(CGRect)frame entity:(id<SocializeEntity>)entity;

@end