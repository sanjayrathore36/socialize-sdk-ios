//
//  SocializeThirdPartyAuthenticator.h
//  SocializeSDK
//
//  Created by Nathaniel Griswold on 2/26/12.
//  Copyright (c) 2012 Socialize, Inc. All rights reserved.
//

#import "SocializeAction.h"
#import "SocializeAuthOptions.h"

@protocol SocializeThirdParty;

@interface SocializeThirdPartyAuthenticator : SocializeAction
- (id)initWithDisplayObject:(id)displayObject
                    display:(id)display
                    options:(SocializeAuthOptions*)options
                    success:(void(^)())success
                    failure:(void(^)(NSError *error))failure;

- (void)attemptInteractiveLogin;
- (void)socializeAuthenticationFailedWithError:(NSError*)error;
- (void)socializeAuthenticationSucceeded;
- (void)tryToFinishAuthenticating;
- (void)succeedInteractiveLogin;

@property (nonatomic, retain) SocializeAuthOptions *options;
@property (nonatomic, assign) Class<SocializeThirdParty> thirdParty;

@end