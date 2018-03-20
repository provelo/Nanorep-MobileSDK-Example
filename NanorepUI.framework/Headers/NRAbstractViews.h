//
//  NRAbstractViews.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 27/10/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NRSearchBarDelegate.h"
#import "NRChanneling.h"

typedef NS_ENUM(NSInteger, NRAnimationType) {
    NRAnimationTypeDefault,
    NRAnimationTypeNanorep,
    NRAnimationTypeCrossDisolve
};


@protocol NRSearchBar <NSObject>
@property (nonatomic, weak) IBOutlet id<NRSearchBarDelegate> seacrhBarDelegate;
@property (nonatomic, copy) NSString *hint;
- (IBAction)clearText:(UIButton *)sender;
@property (nonatomic, copy) NSString *text;

@end

@protocol NRLikeViewDelegate <NSObject>

- (void)didLikePressed:(BOOL)isLike;

@end

@protocol NRLikeView <NSObject>
@property (nonatomic, copy) NSNumber *initialState;
- (void)updateLikeButton:(BOOL)isLike;
- (void)reset;
- (void)cancel;

@optional
@property (nonatomic, weak) id<NRLikeViewDelegate> likeDelegate;

@end

@protocol NRNegativeFeedbackDelegate;



@protocol NRNegativeFeedback <NSObject>

@property (nonatomic, copy) NSString *articleId;
@property (nonatomic, copy, readonly) NSString *text;
@property (nonatomic, weak) id<NRNegativeFeedbackDelegate> delegate;

@end


@protocol NRNegativeFeedbackDelegate <NSObject>

- (void)dismissArticle;
- (void)submitFeedback:(id<NRNegativeFeedback>)negativeFeedback;
- (void)updateChannel:(id<NRNegativeFeedback>)negativeFeedback;
- (void)didCancelFeedback:(id<NRNegativeFeedback>)negativeFeedBack;

@end

@protocol NRChannelingViewDelegate <NSObject>

- (void)didSelectChannel:(NRChanneling *)channel;

@end

@protocol NRFeedbackViewDelegate <NRLikeViewDelegate, NRChannelingViewDelegate>

@end

@protocol NRChannelingView <NSObject>

@property (nonatomic, copy) NSArray<NRChanneling *> *channels;

@optional
@property (nonatomic, weak) IBOutlet id<NRChannelingViewDelegate> delegate;
@end

@protocol NRFeedbackView <NRLikeView, NRChannelingView>
@property (nonatomic, weak) id<NRFeedbackViewDelegate> feedbackDelegate;
@end


@protocol NanorepViewAdapter <NSObject>

@optional
@property (nonatomic, readonly) UIView<NRSearchBar> *customSearchBar;
@property (nonatomic, readonly) UIView<NRLikeView> *customLikeView;
@property (nonatomic, readonly) UIView<NRChannelingView> *customChannelingView;
@property (nonatomic, readonly) UIView<NRFeedbackView> *feedbackView;
@property (nonatomic, readonly) UIView<NRNegativeFeedback> *negativeFeedbackView;
@end
