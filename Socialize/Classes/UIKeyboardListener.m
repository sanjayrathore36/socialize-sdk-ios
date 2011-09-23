/*
 * UIKeyboardListener.m
 * SocializeSDK
 *
 * Created on 9/14/11.
 * 
 * Copyright (c) 2011 Socialize, Inc.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import "UIKeyboardListener.h"
#import <UIKit/UIKit.h>

@interface UIKeyboardListener()
-(void) noticeShowKeyboard:(NSNotification *)inNotification;
-(void) noticeHideKeyboard:(NSNotification *)inNotification;
@end

@implementation UIKeyboardListener

+(UIKeyboardListener*)createWithVisibleKeyboard: (BOOL) visible
{
    return [[[UIKeyboardListener alloc] initWithVisibleKeyboard:visible] autorelease];
}

-(id)initWithVisibleKeyboard: (BOOL) visible
{
    self = [super init];
    
    if ( self ) {
        _visible = visible;
        NSNotificationCenter *center = [NSNotificationCenter defaultCenter];
        [center addObserver:self selector:@selector(noticeShowKeyboard:) name:UIKeyboardDidShowNotification object:nil];
        [center addObserver:self selector:@selector(noticeHideKeyboard:) name:UIKeyboardWillHideNotification object:nil];
    }
    
    return self;
}
-(void)dealloc
{
    NSNotificationCenter *center = [NSNotificationCenter defaultCenter];
    [center removeObserver:self name:UIKeyboardDidShowNotification object:nil];
    [center removeObserver:self name:UIKeyboardWillHideNotification object:nil];
    [super dealloc];
}

-(void) noticeShowKeyboard:(NSNotification *)inNotification 
{
    _visible = true;
}

-(void) noticeHideKeyboard:(NSNotification *)inNotification 
{
    _visible = false;
}

-(BOOL) isVisible {
    return _visible;
}
@end
