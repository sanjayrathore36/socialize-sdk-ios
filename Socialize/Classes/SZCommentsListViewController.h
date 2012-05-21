//
//  SZCommentsListViewController.h
//  appbuildr
//
//  Created by Fawad Haider  on 12/2/10.
//  Copyright 2010 pointabout. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SocializeServiceDelegate.h"
#import "_Socialize.h"
#import "SocializeBaseViewController.h"
#import "SocializeTableViewController.h"
#import "SocializePostCommentViewController.h"

@class CommentsTableFooterView;
@class SocializeTableBGInfoView;
@class ImagesCache;
@class SocializeBubbleView;
@class SocializeNotificationToggleBubbleContentView;

/*
@protocol SocializeCommentsDelegate 

-(void)postComment:(NSString*)commentText location:(CLLocation *)commentLocation shareLocation:(BOOL)shareLocation;
-(void)startFetchingComments;

@end
*/

@class CommentsTableViewCell;
@protocol SZCommentsListViewControllerDelegate;

@interface SZCommentsListViewController : SocializeTableViewController<UITableViewDataSource, SocializeServiceDelegate, UITableViewDelegate, SocializePostCommentViewControllerDelegate> 
{

	IBOutlet UIView*        backgroundView;
	IBOutlet UIImageView*   brushedMetalBackground;
	IBOutlet UIView*        roundedContainerView;
	IBOutlet UIImageView*   noCommentsIconView;
	
	BOOL				_isLoading;
	BOOL				_errorLoading;
    
	NSDateFormatter*    _commentDateFormatter;

	CommentsTableFooterView*      footerView;
    CommentsTableViewCell*        commentsCell;
    
    SocializeEntity*              _entity;
    ImagesCache*                  _cache;
}

@property (retain, nonatomic) IBOutlet UIImageView	*brushedMetalBackground;
@property (retain, nonatomic) IBOutlet UIView		*backgroundView;
@property (retain, nonatomic) IBOutlet UIView		*roundedContainerView;
@property (retain, nonatomic) IBOutlet UIImageView	*noCommentsIconView;
@property (retain, nonatomic) UIBarButtonItem	*closeButton;
@property (retain, nonatomic) UIBarButtonItem	*brandingButton;

@property (nonatomic, assign) IBOutlet CommentsTableViewCell     *commentsCell;
@property (retain, nonatomic) IBOutlet CommentsTableFooterView   *footerView;
@property (retain, nonatomic) ImagesCache               *cache;
@property (assign, nonatomic) BOOL                      isLoading;

@property (nonatomic, assign) id<SZCommentsListViewControllerDelegate> delegate;
@property (nonatomic, retain) id<SocializeEntity> entity;

@property (retain, nonatomic) SocializeBubbleView *bubbleView;
@property (retain, nonatomic) SocializeNotificationToggleBubbleContentView *bubbleContentView;

+ (SZCommentsListViewController*)commentsListViewControllerWithEntityKey:(NSString*)entityKey;
+ (UIViewController*)socializeCommentsTableViewControllerForEntity:(NSString*)entityName __attribute__((deprecated("Please use commentsListViewControllerWithEntityKey: and the SZNavigationController, or the utility functions in SZCommentUtils")));
+ (SZCommentsListViewController*)commentsListViewControllerWithEntity:(id<SZEntity>)entity;

-(IBAction)subscribedButtonPressed:(id)sender;

-(IBAction)addCommentButtonPressed:(id)sender;


-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil entryUrlString:(NSString*) entryUrlString;

- (id)initWithEntityKey:(NSString*)entityKey;

- (id)initWithEntity:(id<SZEntity>)entity;

@end


@protocol SZCommentsListViewControllerDelegate <NSObject>

- (void)commentsTableViewControllerDidFinish:(SZCommentsListViewController*)commentsTableViewController;

@end
