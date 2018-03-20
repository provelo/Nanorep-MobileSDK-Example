//
//  NRReadMoreViewController.h
//  NanorepUI
//
//  Created by Nissim Pardo on 09/05/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NRResultPresntationView.h"
#import "NRApplicationContentHandler.h"

@interface NRReadMoreViewController : UIViewController
@property (nonatomic, copy) NSString *articleId;
@property (nonatomic, weak) id<NRApplicationContentHandler> applicationHandler;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *articleTitle;
@property (nonatomic) BOOL isInTree;
@end
