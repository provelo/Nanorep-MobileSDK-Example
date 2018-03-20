//
//  NRConversationalResponse.h
//  NanorepUI
//
//  Created by Nissim Pardo on 16/02/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NREntity.h"
#import "NRPersonalInfo.h"
#import "NRConversationMissingEntity.h"
#import "NRTokenizer.h"

@interface NRConversationalResponse : NSObject
- (instancetype _Nullable)initWithJSON:(NSString *_Nullable)jsonString;
- (instancetype _Nullable )initWithData:(NSData *_Nullable)data;
- (instancetype _Nullable )initWithDictionary:(NSDictionary *_Nullable)dictionary;

- (void)addAction:(NRAction *_Nullable)action;
@property (nonatomic, readonly) NSInteger status;
@property (nonatomic, copy) NSString * _Nullable statement;
@property (nonatomic, copy) NSString * _Nullable text;
@property (nonatomic, readonly, copy) NRPersonalInfo * _Nullable personalInfo;
@property (nonatomic, readonly, copy) NSNumber * _Nullable articleId;
@property (nonatomic, readonly, copy) NSArray<NSString *> * _Nullable missingEntities;
@property (nonatomic, readonly, copy) NSArray<NREntity *> * _Nullable entities;
@property (nonatomic, readonly, copy) NSArray<NRConversationQuickOption *> * _Nullable quickOptions;
@property (nonatomic, readonly, copy) NSArray<NRConversationQuickOption *> * _Nullable persistentOptions;
@property (nonatomic, readonly, copy) NSString * _Nullable inJSON;
@property (nonatomic, readonly, copy) NSArray<NRAction *> * _Nullable actions;
@property (nonatomic, copy) NSNumber * _Nullable isReadMore;
@property (nonatomic, readonly) BOOL isValid;
@end
