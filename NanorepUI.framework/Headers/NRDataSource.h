//
//  NRDataSource.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 10/10/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NRFAQGroup.h"
#import "NRConfiguration.h"
#import "NanoRep.h"
#import "NRResult.h"


@protocol NRDataSourceDelegate <NSObject>

- (void)didFetchResults;
- (void)didFetchConfiguration;
- (void)searchText:(NSString *)text;
- (void)presentContextPicker:(NRQueryResult *)queryResult;
- (void)presentResult:(NRResult *)result;
@end

@interface NRDataSource : NSObject


@property (nonatomic, weak) id<NRDataSourceDelegate> delegate;

@property (nonatomic, copy) NSArray<NRFAQGroup *> *groups;
@property (nonatomic, strong) NRFAQGroup *selectedGroup;
@property (nonatomic, copy) NSArray<NRResult *> *results;
@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *hint;
@property (nonatomic, copy, readonly) NSDictionary *localeParams;
@property (nonatomic, readonly) NRConfiguration *config;
@property (nonatomic, readonly) NanoRep *nanorep;

- (void)fetchAnswerWithId:(NSString *)answerId completion:(void(^)(NRQueryResult *result))completion;
- (void)fetchSuggestionsForText:(NSString *)text completion:(void(^)(NRAutoCompleteResponse *suggestions))completion;
- (void)searchForText:(NSString *)text completion:(void(^)(BOOL hasAnswer))completion;
- (void)sendLike:(int)type result:(NRQueryResult *)result completion:(void(^)(NSString *resultId, int type, BOOL success))completion;

- (void)fetchResultWithId:(NSString *)resultId completion:(void(^)(NRResult *result))completion;
- (void)dynamicContext:(NSString *)context completion:(void(^)(NSArray<NSString *> *values))completion;
//- (void)updateContext:(NSDictionary<NSString *, NSString *> *)context query:(NSString *)query;
- (void)updateChannels:(NRResult *)result completion:(void (^)(NSArray<NRChanneling *> *channels, NSError *error))completion;
- (void)fetchFAQForLabel:(NRLabel *)label completion:(void(^)())completion;
- (void)clearContext:(NSString *)context;
@end
