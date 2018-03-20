//
//  NRConversationalViewController.h
//  NanorepUI
//
//  Created by Nissim Pardo on 05/12/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NRBotConfiguration.h"
#import "NanoRep.h"
#import "NRQuickOptionWrapper.h"
#import "NRCarouselQuickOption.h"
#import "NRHistoryItem.h"
#import "NRApplicationContentHandler.h"

@class NRConversationalViewController;
@protocol NRCustomContentHandler <NSObject>
- (void)chatReady:(NRConversationalViewController *)controller;
- (void)controller:(NRConversationalViewController *)controller didSendStatement:(NSString *)statement;
- (void)controller:(NRConversationalViewController *)controller didStartCustomChatProvider:(NSString *)chatProviderId query:(NSString *)query;
- (void)controller:(NRConversationalViewController *)controller didFailWithError:(NSError *)error;
- (void)controller:(NRConversationalViewController *)controller didRequestShare:(NSString *)shareText;
- (void)controller:(NRConversationalViewController *)controller didRequestLocation:(void(^)(double latitude, double longitude))locationHandler;
@end

@protocol NRConversationHistoryHandler
- (void)addHistoryItem:(id<HistoryItem>)historyItem forAccount:(AccountParams *)accountParams;
- (void)shouldLoadHistoryForAccount:(AccountParams *)accountParams;
@end


@interface NRConversationalViewController : UIViewController
- (instancetype)initWithAccountParams:(AccountParams *)accountParams;
@property (nonatomic, readonly) NanoRep *nanorep;
@property (nonatomic, copy) NSNumber *conversationId;
@property (nonatomic, weak) id<NRChatEngineDelegate> delegate;
@property (nonatomic, weak) id<NRCustomContentHandler> customChatContentHandler;
@property (nonatomic, weak) id<NRApplicationContentHandler> applicationContentHandler;
@property (nonatomic, strong) NRBotConfiguration *configuration;
@property (weak, nonatomic, readonly) IBOutlet UIView *searchView;

@property (copy, nonatomic) NSMutableArray<NRHistoryItem *> *cachedConversation;

@property (copy, nonatomic) id<NRConversationHistoryHandler> historyHandler;

@property (nonatomic) BOOL enableCustomContent;
- (void)sendMessage:(NSString *)message;

- (void)injectQuickOption:(NRQuickOptionWrapper *)optionWrapper;

- (void)injectHistory:(NSArray<id<HistoryItem>> *)history;
- (void)linkedArticle:(NSString *)articleId;
@end
